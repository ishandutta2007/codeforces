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

const int SZ = 5e3 + 10;

long long a[SZ], b[SZ];
long long dp[SZ][SZ];

long long pref[SZ];

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        pref[i] = a[i] * b[i] + (i == 0 ? 0 : pref[i - 1]);
    for (int i = 0; i < n; i++) {
        dp[0][i] = pref[n - 1];
        dp[1][i] = pref[n - 1];
    }
    long long ans = pref[n - 1];
    for (int len = 2; len <= n; len++) {
        for (int L = 0; L < n; L++) {
            int R = L + len - 1;
            if (R >= n)
                continue;
            dp[len][L] = dp[len - 2][L + 1]
                    - a[L] * b[L] - a[R] * b[R] + a[L] * b[R] + a[R] * b[L];
            ans = max(ans, dp[len][L]);
        }
    }
    cout << ans;
    return 0;
}