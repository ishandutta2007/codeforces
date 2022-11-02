#include <bits/stdc++.h>
using namespace std;

#define N 5050

int n, a[N], cur[N], dp[N][N], ans[N];

int main() {
    scanf("%d", &n); a[0] = a[n+1] = 0;
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) cur[i] = max(a[i-1] - a[i] + 1, 0) + max(a[i+1] - a[i] + 1, 0);
    for (int i = 0; i <= n; i ++)
        for (int j = 1; j <= n; j ++) dp[i][j] = 1e9;
    for (int i = 0; i <= n; i ++) ans[i] = 1e9;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= (i + 1) / 2; j ++) {
            if (j == 1) {dp[i][j] = cur[i]; if (i > 3) ans[j] = min(ans[j], dp[i-3][j]); continue;}
            if (i > 1) dp[i][j] = min(dp[i][j], dp[i-2][j-1] + max(min(a[i-1], a[i-2] - 1) - a[i] + 1, 0) + max(a[i+1] - a[i] + 1, 0));
            if (i > 2) dp[i][j] = min(dp[i][j], ans[j-1] + cur[i]);
            if (i > 3) ans[j] = min(ans[j], dp[i-3][j]);
        }
    }
    for (int i = n - 2; i <= n; i ++)
        for (int j = 1; j <= (n + 1) / 2; j ++) ans[j] = min(ans[j], dp[i][j]);
    for (int i = 1; i <= (n + 1) / 2; i ++) printf("%d ", ans[i]);
}