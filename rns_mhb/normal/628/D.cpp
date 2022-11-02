#include <bits/stdc++.h>
using namespace std;

#define N 2005

const int mod = 1e9 + 7;
int n, m, d, ans;
char s[N], t[N];
int c[N];
int dp[2][N][N];

int calc_dp(int flag) {
    memset(dp, 0, sizeof dp);
    dp[1][0][0] = 1;
    for (int i = 0; i < n-1; i ++)
    for (int t = 0; t < 2; t ++)
    for (int j = 0; j < m; j ++)
    for (int p = 0; p <= (t ? c[i+1] : 9); p ++) {
        if ((i & 1) ^ (p == d)) continue;
        int nt = t & (p == c[i+1]), nj = (j * 10 + p) % m;
        (dp[nt][i+1][nj] += dp[t][i][j]) %= mod;
    }
    int rtn = dp[0][n-1][0];
    if (flag) (rtn += dp[1][n-1][0]) %= mod;
    return rtn;
}

int main() {
    scanf("%d %d ", &m, &d);
    gets(s), gets(t);
    n = 1;
    for (int i = 0; s[i]; i ++) c[n++] = s[i] - '0';
    ans = (mod - calc_dp(0)) % mod;
    n = 1;
    for (int i = 0; t[i]; i ++) c[n++] = t[i] - '0';
    (ans += calc_dp(1)) %= mod;
    printf("%d\n", ans);
    return 0;
}