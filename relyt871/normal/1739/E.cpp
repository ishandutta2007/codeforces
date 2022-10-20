#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const int INF = 0x3f3f3f3f;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

template <typename T> inline void cmin(T &x, T y) {
    if (x > y) x = y;
}

char s[2][MAXN];
int n, a[MAXN][2], sum, dp[MAXN][2][2][2];

void solve() {
    read(n);
    scanf("%s", s[0] + 1);
    scanf("%s", s[1] + 1);
    for (int i = 1; i <= n; ++i) {
        a[i][0] = (s[0][i] - '0');
        a[i][1] = (s[1][i] - '0');
        sum += a[i][0] + a[i][1];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int t = 0; t < 2; ++t) {
                    dp[i][j][k][t] = INF;
                }
            }
        }
    }
    for (int i = 0; i <= a[1][0]; ++i) {
        for (int j = 0; j <= a[1][1]; ++j) {
            dp[0][0][i][j] = a[1][0] - i + a[1][1] - j;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= a[i][0]; ++j) {
            for (int k = 0; k <= a[i][1]; ++k) {
                for (int p = 0; p <= j; ++p) {
                    for (int q = 0; q <= k; ++q) {
                        for (int x = 0; x <= a[i + 1][0]; ++x) {
                            for (int y = 0; y <= a[i + 1][1]; ++y) {
                                int w = (j - p) + (k - q) + (a[i + 1][0] - x) + (a[i + 1][1] - y);
                                if (!q) {
                                    cmin(dp[i][0][x][y], dp[i - 1][0][j][k] + w);
                                }
                                if (!p) {
                                    cmin(dp[i][1][x][y], dp[i - 1][1][j][k] + w);
                                }
                                if (q && !x) {
                                    cmin(dp[i][1][x][y], dp[i - 1][0][j][k] + w);
                                }
                                if (p && !y) {
                                    cmin(dp[i][0][x][y], dp[i - 1][1][j][k] + w);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= a[n][0]; ++i) {
        for (int j = 0; j <= a[n][1]; ++j) {
            cmin(ans, dp[n - 1][0][i][j]);
            cmin(ans, dp[n - 1][1][i][j]);
        }
    }
    printf("%d\n", sum - ans);
}

int main() {
    solve();
    return 0;
}