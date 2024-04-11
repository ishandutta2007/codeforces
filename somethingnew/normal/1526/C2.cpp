#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    vector<int> heap;
    int val = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t >= 0) {
            val += t;
            res++;
        } else {
            t = abs(t);
            if (val >= t) {
                val -= t;
                heap.push_back(t);
                res++;
                push_heap(all(heap));
            } else {
                if (!heap.empty() and heap[0] >= t) {
                    pop_heap(all(heap));
                    val += heap.back() - t;
                    heap.back() = t;
                    push_heap(all(heap));
                }
            }
        }
    }
    cout << res;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}