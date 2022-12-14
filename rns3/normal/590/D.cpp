#include <cstdio>

#define N 155
#define M 12000

int a[N], b[N];
int dp[N][M];
bool chk[N][M];

main() {
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n; i ++) scanf("%d", a + i);
    if (s > n * (n - 1) / 2) s = n * (n - 1) / 2;
    int rlt = 0;
    for (int i = 1; i <= m; i ++) rlt += a[i];
    int cur = 0;
    for (int i = 1; i <= n; i ++) cur += a[i];
    int ps = n;
    for (int i = 1; i <= ps; i ++) {
        b[i] = ps - i;

    }
    int ss = s + (ps - m) * (ps - m - 1) / 2;
    if (ss > ps * (ps - 1) / 2) ss = ps * (ps - 1) / 2;
    for (int i = 0; i <= ps - m; i ++) for (int j = 0; j <= ss; j ++) chk[i][j] = 0;
    chk[0][0] = 1;
    for (int i = 1; i <= ps; i ++) {
        for (int cnt = ps - m - 1; cnt >= 0; cnt --) {
            for (int j = ss - b[i]; j >= 0; j --) if (chk[cnt][j]) {
				chk[cnt + 1][j + b[i]] = 1;
                if (dp[cnt + 1][j + b[i]] < dp[cnt][j] + a[i]) dp[cnt + 1][j + b[i]] = dp[cnt][j] + a[i];
            }
        }
    }
    int mx = 0;
    for (int i = 0; i <= ss; i ++) if (mx < dp[ps - m][i]) mx = dp[ps - m][i];
    if (rlt > cur - mx) rlt = cur - mx;
    printf("%d\n", rlt);
}