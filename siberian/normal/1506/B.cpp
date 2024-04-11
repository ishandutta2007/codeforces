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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> dp(n, 100);
    int pos = 0;
    for (auto i : s) {
        ++pos;
        if (i == '*') {
            dp[pos - 1] = 1;
            break;
        }
    }
    for (int i = pos; i < n; ++i) {
        if (s[i] != '*') continue;
        for (int j = 0; j < i; ++j) {
            if (i - j > k) continue;
            if (dp[j] == 100) continue;
            chkmin(dp[i], dp[j] + 1);
        }
    }
    // cerr <<"dp = " << endl;
    // for (auto i : dp) {
    //     cerr << i << " ";
    // }
    // cerr << endl;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '*') {
            cout << dp[i] << '\n';
            return;
        }
    }
    assert(false);
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