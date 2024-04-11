#include <bits/stdc++.h>
using namespace std;

#define N 1005

template <class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
const int inf = 1e9;
int n;
char s[N];
int dp[N][N], f[N][N], g[N][N];
int ans[N];

void calc_dp() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i == 1) {
                dp[i][j] = j;
            }
            else if (s[i-1] == '=') dp[i][j] = dp[i-1][j] + j;
            else if (s[i-1] == 'L') {
                dp[i][j] = f[i-1][j+1] + j;
            }
            else {
                dp[i][j] = g[i-1][j-1] + j;
            }
        }
        g[i][0] = inf;
        for (int j = 1; j <= n; j ++) {
            g[i][j] = min(g[i][j-1], dp[i][j]);
        }
        f[i][n+1] = inf;
        for (int j = n; j; j --) {
            f[i][j] = min(f[i][j+1], dp[i][j]);
        }
    }
    int mn = inf;
    for (int j = 1; j <= n; j ++) if (chkmin(mn, dp[n][j])) ans[n] = j;
    for (int i = n - 1; i; i --) {
        if (s[i] == '=') {
            ans[i] = ans[i+1];
        }
        else if (s[i] == 'L') {
            int mn = inf;
            for (int j = ans[i+1] + 1; j <= n; j ++)
                if (chkmin(mn, dp[i][j])) ans[i] = j;
        }
        else {
            int mn = inf;
            for (int j = ans[i+1] - 1; j; j --) {
                if (chkmin(mn, dp[i][j])) ans[i] = j;
            }
        }
    }
}

int main() {
    scanf("%d ", &n);
    gets(s + 1);
    calc_dp();
    for (int i = 1; i <= n; i ++) printf("%d ", ans[i]);
    return 0;
}