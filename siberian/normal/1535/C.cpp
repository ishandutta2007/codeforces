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
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    int cnt[2][2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cnt[i][j] = 0;
        }
    }
    int r = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n) {
            if (s[r] == '?') {
                ++r;
            } else {
                int val = s[r] - '0';
                if (cnt[(r & 1) ^ 1][val]) break;
                if (cnt[r & 1][val ^ 1]) break;
                cnt[r & 1][val]++;
                // cerr << "(r & 1) = " << (r & 1) << " val = " << val << endl;
                ++r;
            }
        }
        ans += r - l;
        // cerr << "l = " << l << " r = " << r << endl;
        if (s[l] != '?') {
            int val = s[l] - '0';
            cnt[l & 1][val]--;
        }
    }
    cout << ans << endl;
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