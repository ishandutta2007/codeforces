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
int res(vector<int> a) {
    int n = a.size();
    int vl = 0, vl2 = a[0];
    for (int i = 1; i < n; ++i) {
        vl = max(vl, min(a[i], a[i - 1]));
        vl2 = min(vl2, a[i]);
    }
    return min(vl, vl2 * 2);
}
void solve() {
    int n, k;
    int mx = 1e9;
    cin >> n >> k;
    vector<int> a(n);
    vector<pair<int, int>> pr;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pr.push_back({a[i], i});
    }
    sort(all(pr));
    for (int i = 0; i < k - 1; ++i) {
        a[pr[i].second] = 1e9;
    }
    vector<int> bb = a;
    bb[pr[k - 1].second] = 1e9;
    int mxind = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > a[mxind])
            mxind = i;
    }
    if (mxind + 1 < n) {
        a[mxind + 1] = mx;
    } else
        a[mxind - 1] = mx;
    cout << max(res(a), res(bb)) << '\n';
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