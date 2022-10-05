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
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(all(h));
    int nd1 = 0, nd2 = 0;
    for (int i = 0; i < n; ++i) {
        h[i] -= h.back();
        h[i] = -h[i];
        nd1 += h[i] % 2;
        nd2 += h[i] / 2;
    }
    int l = -1, r = 1e17;
    while (l + 1 < r) {
        int m = l + r >> 1;
        if ((m+1)/2 >= nd1 and nd2 * 2 + nd1 <= m + m / 2) {
            r = m;
        } else {
            l = m;
        }
    }
    int ans = r;
    l = -1, r = 1e17;
    nd1 = 0, nd2 = 0;
    for (int i = 0; i < n; ++i) {
        h[i] += 1;
        nd1 += h[i] % 2;
        nd2 += h[i] / 2;
    }
    while (l + 1 < r) {
        int m = l + r >> 1;
        if ((m+1)/2 >= nd1 and nd2 * 2 + nd1 <= m + m / 2) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << min(ans, r) << '\n';
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