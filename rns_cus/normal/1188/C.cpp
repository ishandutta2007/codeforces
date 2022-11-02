#include <bits/stdc++.h>
using namespace std;
#define N 1010
const int mod = 998244353;
int n, m, a[N], d[N][N], dp[N][N];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%d", a + i);
    sort(a, a + n);
    int ans = 0;
    for (int j = 0; j < n; j ++) dp[1][j] = j;
    int X = 100000 / (m - 1) + 1;
    for (int t = 1; t < X; t ++) {
        for (int i = 2; i <= m; i ++) {
            for (int j = 0, k = 0; j < n; j ++) {
                while (a[j] - a[k] >= t) k ++;
                dp[i][j + 1] = dp[i][j] + dp[i - 1][k];
                if (dp[i][j + 1] >= mod) dp[i][j + 1] -= mod;
            }
        }
        ans += dp[m][n];
        if (ans >= mod) ans -= mod;
    }
    printf("%d\n", ans);
}