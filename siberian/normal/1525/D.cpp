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

const int N = 5e3 + 10;
int n;
int a[N];
int pos[N];
int topPos = 0;
int dp[N][N];

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i]) pos[topPos++] = i;
    }
    // cerr << "pos = " << endl;
    // for (int i = 0; i < topPos; ++i) {
    //     cerr << pos[i] << ' ';
    // }
    // cerr << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = N * N;
        }
    }
    dp[0][0] = 0;
    for (int cnt = 0; cnt < topPos; ++cnt) {
        for (int i = 0; i < n; ++i) {
            if (dp[cnt][i] == N * N) continue;
            chkmin(dp[cnt][i + 1], dp[cnt][i]);
            // cerr << "pos[cnt] = " << pos[cnt] << " i = " << i << endl;
            if (a[i + 1] == 0) chkmin(dp[cnt + 1][i + 1], dp[cnt][i] + abs(pos[cnt] - i - 1));
        }
    }
    // cerr << "dp = " << endl;
    // for (int cnt = 0; cnt <= topPos; ++cnt) {
    //     for (int i = 0; i <= n; ++i) {
    //         cerr << dp[cnt][i] << ' ';
    //     }
    //     cerr << endl;
    // }
    int ans = N * N;
    for (int i = 0; i <= n; ++i) {
        chkmin(ans, dp[topPos][i]);
    }
    cout << ans << endl;
    return 0;
}