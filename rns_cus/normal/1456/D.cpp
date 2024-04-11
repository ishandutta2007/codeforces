#include <bits/stdc++.h>
using namespace std;

#define N 5050

int n, x[N];
long long t[N], mt[N];
bool dp[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%I64d %d", &t[i], &x[i]);

    for (int i = 1; i <= n; i ++) mt[i] = 1e18;

    for (int i = 0; i < n; i ++) {
        if (mt[i] <= t[i]) {
            mt[i+1] = min(mt[i+1], max(mt[i] + abs(x[i+1] - x[i]), t[i]));
            for (int j = i + 2; j <= n; j ++) {
                if (max(t[i], mt[i] + abs(x[i] - x[j])) + abs(x[j] - x[i+1]) <= t[i+1]) dp[i+1][j] = 1;
                if (mt[i] + 2 * abs(x[i] - x[j]) <= t[i] && t[i] + abs(x[i] -x[i+1]) <= t[i+1]) dp[i+1][j] = 1;
            }
        }

        if (t[i] + abs(x[i] - x[i+1]) <= t[i+1]) {
            for (int j = i + 2; j <= n; j ++) if (dp[i][j]) dp[i+1][j] = 1;
        }

        if (dp[i][i+1]) {
            mt[i+2] = min(mt[i+2], max(t[i] + abs(x[i] - x[i+2]), t[i+1]));
            for (int j = i + 3; j <= n; j ++) {
                if (max(t[i] + abs(x[i] - x[j]), t[i+1]) + abs(x[j] - x[i+2]) <= t[i+2]) dp[i+2][j] = 1;
            }
        }

    }

    if (mt[n] <= t[n] || dp[n-1][n]) puts("YES");
    else puts("NO");

}