#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

template<typename T>
void swapElements(const T& a, const T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
class Heap {
    public:
        void pushToHeap(const T& element, function<bool(const T&, const T&)>& comparator) {
            heap.push_back(element);
            heapUp(comparator);
        }
        void popFromHeap(function<bool(const T&, const T&)>& comparator) {
            swapElements(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            heapDown(comparator);
        }
        T nextElement() {
            return heap[0];
        }
        bool isEmpty() {
            return hea.size() == 0;
        }
        void printHeap () {
            copy(heap.begin(), heap.end(), ostream_iterator<T>(cout, " "));
        }
    private:
        vector<T> heap;
        void heapUp(function<int(const T&, const T&)>& comparator) {
            int sz = heap.size();
            int index = sz - 1;
            int parent = (index - 1) / 2;
            while (parent >= 0) {
                if (comparator(heap[index], heap[parent]) < 0) {
                    swapElements(heap[index], heap[parent]);
                } else {
                    break;
                }
                index = parent;
                parent = (index - 1) / 2;
            }
        }

        void heapDown(function<int(const T&, const T&)>& comparator) {
            int sz = heap.size();
            int parent = 0;
            int child = 2 * parent + 1;
            while (child < sz) {
                if (child + 1 < sz && comparator(heap[child], heap[child+1]) > 0) {
                    swapElements(heap[child], heap[child+1]);
                }
                if (comparator(heap[child], heap[parent]) < 0) {
                    swapElements(heap[child], heap[parent]);
                } else {
                    break;
                }
                parent = child;
                child = 2 * parent + 1;
            }
        }
};

int  main() {
   vector<int> t{10,4,9,13,7,8,3,19,16,14};
   for(int i = t.size() - 1; i >= 0; --i) {
       cout << t[i] << endl;
   }
   Heap<int> minHeap;
   for_each(t.begin(), t.end(), [&minHeap](int x) {
       minHeap.pushToHeap(x, [](const int& x, const int& y) {
           return x - y;
       });
   });
   return 0;
}
