#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

ll get(ll x) {
    return x * (x + 1) / 2;
}

void solve() {
    int n, m;
    cin >> n >> m;
    ll ans = get(n);
    int x = (n - m) / (m + 1);
    int y = (n - m) % (m + 1);
    for (int i = 0; i < y; i++) {
        ans -= get(x + 1);
    }
    for (int i = 0; i < m + 1 - y; i++) {
        ans -= get(x);
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}