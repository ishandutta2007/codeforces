#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e3 + 10;
int n, m;
char table[MAXN][MAXN];

void read() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> table[i][j];
        }
    }
}

int len[2][MAXN][MAXN];
int dp[2][MAXN][MAXN];

void build() {
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            len[0][i][j] = len[0][i][j + 1] * (table[i][j] == table[i][j + 1]) + 1;
            len[1][i][j] = len[1][i + 1][j] * (table[i][j] == table[i + 1][j]) + 1;
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[0][i][j] = len[0][i][j];
            if (table[i][j] == table[i - 1][j])
                chkmin(dp[0][i][j], dp[0][i - 1][j]);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            dp[1][i][j] = len[0][i][j];
            if (table[i][j] == table[i + 1][j])
                chkmin(dp[1][i][j], dp[1][i + 1][j]);
        }
    }
}

ll ans;

void run() {
    build();
    ans = 0;
    for (int i = 2; i <= n - 1; i++) {
        for (int j = 1; j <= m; j++) {
            if (table[i][j] == table[i - 1][j]) continue;
            int my_len = len[1][i][j];
            if (i - my_len <= 0) continue;
            if (len[1][i - my_len][j] != my_len) continue;
            if (i + my_len > n) continue;
            if (len[1][i + my_len][j] < my_len) continue;
            int add = dp[1][i][j];
            chkmin(add, dp[1][i - my_len][j]);
            chkmin(add, dp[0][i + my_len * 2 - 1][j]);
            ans += add;
        }
    }
}

void write() {
    cout << ans << endl;
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