#include <cmath>
#include <cstdio>
#include <algorithm>

const int N = 300005, L = 20;

int n, m, q, a[N], f[L][N], g[L][N];

bool check(int x, int y) {
    for (int i = 0; i <= m; i++) {
        if ((a[y] >> i & 1) && f[i][x] <= y) { return true; }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); }
    m = log(*std::max_element(a + 1, a + n + 1)) / log(2) + 1e-7;
    for (int i = 0; i <= m; i++) { f[i][n + 1] = g[i][n + 1] = n + 1; }
    for (int i = n; i; i--) {
        for (int j = 0; j <= m; j++) {
            f[j][i] = a[i] >> j & 1 ? g[j][i + 1] : n + 1;
            g[j][i] = a[i] >> j & 1 ? i : g[j][i + 1];
            for (int k = 0; k <= m; k++) {
                if (a[i] >> k & 1) { f[j][i] = std::min(f[j][i], f[j][g[k][i + 1]]); }
            }
        }
    }
    for (int x, y; q; q--) { scanf("%d%d", &x, &y); printf("%s\n", check(x, y) ? "Shi" : "Fou"); }
    return 0;
}