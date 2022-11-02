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

#define int ll

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int val = 0;
        if (i > 0) chkmax(val, a[i - 1]);
        if (i + 1 < n) chkmax(val, a[i + 1]);
        if (val >= a[i]) continue;
        ans += a[i] - val;
        a[i] = val;
    }
    for (int i = 0; i < n; ++i) {
        ans += abs(a[i] - (i > 0 ? a[i - 1] : 0));
    }
    ans += a.back();
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