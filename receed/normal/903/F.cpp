#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mx = 1 << 12;
int a[4], ms[4], dp[1007][mx], b[1007];
char c[4][1007];

int main() {
    int n, t, inf = 1e9 + 7;
    scanf("%d", &n);
    for (int i = 0; i < 4; i++) {
        scanf("%d", &a[i]);
        ms[i] = (1 << (i + 1)) - 1;
    }
    for (int i = 0; i < 4; i++)
        scanf("%s", &c[i]);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++)
            b[i] += (c[j][i] == '*') << j;
        for (int j = 0; j < mx; j++)
            dp[i][j] = inf;
    }
    dp[0][b[0] + (b[1] << 4) + (b[2] << 8)] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = mx - 1; j >= 0; j--) {
            if (dp[i][j] == inf)
                continue;
            if (j % 16 == 0) {
                t = (j >> 4) + (b[i + 3] << 8);
                dp[i + 1][t] = min(dp[i + 1][t], dp[i][j]);
            }
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + a[3]);
            for (int k = 0; k < 3; k++) {
                for (int z = 0; z + k < 4; z++) {
                    t = j;
                    for (int p = 0; p <= k; p++) {
                        t &= ~(ms[k] << (p * 4 + z));
                    }
                    dp[i][t] = min(dp[i][t], dp[i][j] + a[k]);
                }
            }
        }
    }
    printf("%d", dp[n][0]);
}