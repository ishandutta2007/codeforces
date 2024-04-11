#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

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
    vin(a);
    vector<vector<int>> pref(n, vector<int>(n + 1, 0)), suff(n, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            pref[i] = pref[i - 1];
        }
        for (int val = a[i]; val <= n; ++val) {
            ++pref[i][val];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i + 1 < n) {
            suff[i] = suff[i + 1];
        }
        for (int val = a[i]; val <= n; ++val) {
            ++suff[i][val];
        }
    }
    ll ans = 0;
    for (int b = 1; b < n; ++b) {
        for (int c = b + 1; c + 1 < n; ++c) {
            ans += (ll)pref[b - 1][a[c] - 1] * suff[c + 1][a[b] - 1];
        }
    }
    cout << ans << '\n';
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