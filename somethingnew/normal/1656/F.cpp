#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
    }
    sort(all(a));
    int t2 = sm + (n - 2) * a[0], t1 = 0;
    for (int i = 1; i < n; ++i) {
        t1 += a[i] * a[0];
    }
    if (t2 > 0) {
        cout << "INF\n";
        return;
    }
    int res = -1e18;
    res = max(res, (-a[0]) * t2 + t1);
    for (int i = 1; i < n-1; ++i) {
        t2 -= a[0];
        t2 += a.back();
        t1 -= a[0] * a[i];
        t1 += a.back() * a[i];
        res = max(res, (-a[i]) * t2 + t1);
        res = max(res, (-a[i + 1]) * t2 + t1);
    }
    if (t2 < 0) {
        cout << "INF\n";
        return;
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