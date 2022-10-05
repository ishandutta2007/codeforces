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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res1 = 0;
    int k2 = min(k, n);
    for (int i = 0; i < n; ++i) {
        a[i] += k - k2;
    }
    int mxres = 0;
    for (int i = 0; i < k2; ++i) {
        res1 += a[i];
    }
    mxres = res1;
    for (int i = k2; i < n; ++i) {
        res1 += a[i] - a[i-k2];
        mxres = max(mxres, res1);
    }
    cout << mxres + (k2 - 1) * (k2) / 2 << '\n';
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