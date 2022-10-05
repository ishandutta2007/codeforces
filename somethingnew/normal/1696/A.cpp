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
void solve() {
    int n, z;
    cin >> n >> z;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >>  a[i];
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, (a[i]|z));
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