#include <bits/stdc++.h>
using namespace std;

#define N 2005

int n, t;
double p;
double ans;
double dp[N][N];

int main() {
    scanf("%d %lf %d", &n, &p, &t);
    dp[0][0] = 1;
    for (int i = 1; i <= t; i ++)
    for (int j = 0; j <= t; j ++) {
        if (j > i) {
            dp[i][j] = 0;
            continue;
        }
        dp[i][j] = 0;
        dp[i][j] += dp[i-1][j] * (1 - p);
        if (j) dp[i][j] += dp[i-1][j-1] * p;
    }
    ans = 0;
    for (int i = 0; i <= t; i ++) {
        ans += dp[t][i] * min(i, n);
    }
    printf("%.12lf\n", ans);
    return 0;
}