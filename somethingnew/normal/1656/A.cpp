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
    int mx = 0, mn = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn = min(a[i], mn);
        mx = max(mx, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (mn == a[i]) {
            cout << i + 1 << ' ';
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (mx == a[i]) {
            cout << i + 1 << '\n';
            return;
        }
    }
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