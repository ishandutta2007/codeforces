#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    const int MOD = 1e9 + 7;
    sort(all(a));
    for (int i = 1; i < n; ++i) {
        if ((a[i] & a[0]) != a[0]) {
            cout << "0\n";
            return;
        }
    }
    if (a[0] != a[1]) {
        cout << "0\n";
        return;
    }
    int cnt = 0;
    for (auto i : a) {
        cnt += i == a[0];
    }
    int ans = (ll)cnt * (cnt - 1) % MOD;
    for (int i = 1; i <= n - 2; ++i) {
        ans = (ll)ans * i % MOD;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}