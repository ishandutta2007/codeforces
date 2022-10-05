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
#define int long long
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= n - i;
        if (i < n-k)
            res += n - i;
    }
    sort(all(a));
    for (int i = 0; i < n - k; ++i) {
        res += a[i];
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