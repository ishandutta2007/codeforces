#include <bits/stdc++.h>
using namespace std;

#define N 5005
#define M 100005
#define K 7

template <class T> bool chkmax(T &a, T b) { return a < b ? 1, a = b : 0; }
int n, ans;
int a[N];
int dp[N][N];
int f[M], g[10];

void calc_dp() {
    for (int i = 0; i <= n; i ++) {
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        for (int j = 0; j <= n; j ++) {
            if (j == i) dp[i][j] = 0;
            else if (j < i) dp[i][j] = dp[j][i];
            else {
                dp[i][j] = 0;
                chkmax(dp[i][j], f[a[j]+1] + 1);
                chkmax(dp[i][j], f[a[j]-1] + 1);
                chkmax(dp[i][j], g[a[j]%K] + 1);
                chkmax(dp[i][j], dp[i][0] + 1);
            }
            chkmax(f[a[j]], dp[i][j]);
            chkmax(g[a[j]%K], dp[i][j]);
            chkmax(ans, dp[i][j]);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    calc_dp();
    printf("%d\n", ans);
    return 0;
}