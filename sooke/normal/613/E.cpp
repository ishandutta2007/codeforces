#include <bits/stdc++.h>

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}

const int N = 2e3 + 5;

int n, m, ans, l[2][N][N], r[2][N][N], f[2][N][N];
char s[2][N], t[N];

void solve(bool flag) {
    for (int i = 1; i <= n; i++) {
        for (int o = 0; o < 2; o++) {
            for (int k = 1; k <= m; k++) {
                if (s[o][i] == t[k]) {
                    l[o][i][k] = l[o][i - 1][k - 1] + 1;
                    r[o][i][k] = r[o][i - 1][k + 1] + 1;
                } else {
                    l[o][i][k] = r[o][i][k] = 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int o = 0, p = 1; o < 2; o++, p--) {
            for (int k = 0; k <= m; k++) {
                f[o][i][k] = 0;
            }
            f[o][i][0] = 1;
            for (int j = 0; j < i; j++) {
                if (j * 2 + 1 >= m || (flag && j * 2 + 2 >= m)) { continue; }
                f[o][i][j * 2 + 1] = r[p][i][1] >= j + 1 && l[o][i - 1][j * 2 + 1] >= j;
            }
            for (int k = 2; k <= m; k++) {
                int j = std::max(1, l[p][i][k]);
                if (k > 1) { f[o][i][k] = add(f[o][i][k], f[p][i - 1][k - 2]); }
                if (k > j) { f[o][i][k] = sub(f[o][i][k], f[p][i - j][k - 1 - j]); }
            }
            ans = add(ans, f[o][i][m]);
            for (int j = 0; j < n + 1 - i; j++) {
                int k = m - (j * 2 + 1);
                if (k >= 0 && r[o][i + j][m - j] >= j + 1 && l[p][i + j][m - j - 1] >= j) {
                    if (j * 2 + 1 >= m || (flag && j * 2 + 2 >= m)) { continue; }
                    ans = add(ans, f[o][i][k]);
                    if (k % 2 == 1) {
                        int _j = k / 2;
                        if (j > 0 && _j > 0 && r[p][i][1] >= _j + 1 && l[o][i - 1][_j * 2 + 1] >= _j) {
                            ans = sub(ans, 1);
                        }
                    }
                }
            }
            for (int k = 1; k <= m; k++) {
                f[o][i][k] = add(f[o][i][k], f[o][i - 1][k - 1]);
            }
        }
    }
}

int main() {
    scanf("%s%s%s", s[0] + 1, s[1] + 1, t + 1);
    n = strlen(s[0] + 1); m = strlen(t + 1);
    if (m == 1) {
        for (int i = 1; i <= n; i++) {
            ans += s[0][i] == t[1];
            ans += s[1][i] == t[1];
        }
    } else {
        solve(false);
        std::reverse(t + 1, t + m + 1);
        solve(true);
    }
    printf("%d\n", ans);
    return 0;
}