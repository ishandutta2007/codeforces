#include <bits/stdc++.h>

const int max_N = 5000 + 21;
const int inf = 0x3f3f3f3f;

int n, a[max_N], dp[3][max_N][max_N >> 1];

inline void updt(int &x, int a) { x = std::min(x, a); }

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    // n = 5000;
    // for (int i = 1; i <= n; ++i) a[i] = 1;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= (i + 1) / 2; ++j) {
            for (int s = 0; s < 3; ++s) {
                int tmp = dp[s][i][j];
                if (tmp == inf) continue;
                updt(dp[s >> 1][i + 1][j], tmp);
                if (s != 2) {
                    int ht = (s == 1) ? std::min(a[i], a[i - 1] - 1) : a[i];
                    int ttmp = tmp + std::max(0, ht - a[i + 1] + 1);
                    if (i + 1 < n) ttmp += std::max(0, a[i + 2] - a[i + 1] + 1);
                    updt(dp[2][i + 1][j + 1], ttmp);
                }
            }
        }
    }
    for (int i = 1; i <= (n + 1) / 2; ++i) {
        int res = inf;
        for (int s = 0; s < 3; ++s) updt(res, dp[s][n][i]);
        printf("%d ", res);
    }
    return 0;
}