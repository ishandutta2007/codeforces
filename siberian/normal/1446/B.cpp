#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int N = 5e3 + 10;
int n, m;
string a, b;

void read() {
    cin >> n >> m >> a >> b;
}

const int INF = -1e9 - 228;
int dp[N][N];
int ans = 0;

void run() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = -i;
    }
    for (int j = 1; j <= m; ++j) {
        dp[0][j] = -j;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 2;
                chkmax(dp[i][j], dp[i - 1][j - 1] + 2);
            } else {
                dp[i][j] = -2;
            }
            chkmax(dp[i][j], dp[i - 1][j] - 1);
            chkmax(dp[i][j], dp[i][j - 1] - 1);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            chkmax(ans, dp[i][j]);
        }
    }
}

void write() {
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}