//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
void solve() {
    int n, x;
    cin >> n >> x;
    pair<int, int> inf = {-2e9, 2e9};
    pair<int, int> nw = inf;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        nw.first = max(nw.first, d - x);
        nw.second = min(nw.second, d + x);
        if (nw.first > nw.second) {
            res++;
            nw = {d - x, d + x};
        }
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}