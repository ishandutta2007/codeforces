#include <bits/stdc++.h>

const int N = 5e3 + 5;

int n, m, ans, f[N][N];
char s[N], t[N];

int main() {
    scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = std::max(f[i][j], std::max(f[i - 1][j], f[i][j - 1]) - 1);
            if (s[i] == t[j]) { f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 2); }
            ans = std::max(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}