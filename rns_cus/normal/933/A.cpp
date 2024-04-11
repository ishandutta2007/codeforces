#include <bits/stdc++.h>
using namespace std;
#define N 2020

int n, a[N], cnt[2][N], dp[N][N][2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) {
        cnt[0][i] = cnt[0][i-1];
        if (a[i] == 1) cnt[0][i] ++;
    }
    for (int i = n; i >= 1; i --) {
        cnt[1][i] = cnt[1][i+1];
        if (a[i] == 2) cnt[1][i] ++;
    }
    int rlt = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            dp[i][j][0] = dp[i][j-1][0];
            dp[i][j][1] = dp[i][j-1][1];
            if (a[j] == 1) dp[i][j][0] = max(dp[i][j][0], dp[i][j][1]) + 1;
            else dp[i][j][1] ++;
            rlt = max(rlt, cnt[0][i-1] + max(dp[i][j][0], dp[i][j][1]) + cnt[1][j+1]);
        }
    }
    printf("%d\n", rlt);
}