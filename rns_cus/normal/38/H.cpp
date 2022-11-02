#include <bits/stdc++.h>
using namespace std;

#define N 55

int n, m, a[N][N], g1, g2, s1, s2, g[N], s[N], b[N], mn[N], mx[N];
const int inf = 1e9;
long long f[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) if (i != j) a[i][j] = inf;
    while (m --) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u][v] = a[v][u] = w;
    }
    scanf("%d %d %d %d", &g1, &g2, &s1, &s2);
    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        mn[i] = inf, mx[i] = -inf;
        for (int j = 1; j <= n; j ++) if (i != j) {
            a[i][j] = a[i][j] * 100 + i;
            mn[i] = min(mn[i], a[i][j]);
            mx[i] = max(mx[i], a[i][j]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i == j || mn[i] > mx[j]) continue;
            for (int k = 1; k <= n; k ++) {
                if (k == i || k == j) continue;
                g[k] = b[k] = s[k] = 0;
                if (mn[k] < mn[i]) g[k] = 1;
                if (mx[k] > mx[j]) b[k] = 1;
                for (int l = 1; l <= n; l ++) if (l != k && a[k][l] > mn[i] && a[k][l] < mx[j]) s[k] = 1;
            }
            g[i] = 1, b[i] = s[i] = 0;
            b[j] = 1, g[j] = s[j] = 0;
            memset(f, 0, sizeof f);
            f[0][0] = 1;
            for (int k = 1; k <= n; k ++) {
                for (int x = min(g2, k); ~x; x --) {
                    for (int y = min(s2, k - x); ~y; y --) {
                        if (!b[k]) f[x][y] = 0;
                        if (g[k] && x) f[x][y] += f[x-1][y];
                        if (s[k] && y) f[x][y] += f[x][y-1];
                    }
                }
            }
            for (int x = g1; x <= g2; x ++) for (int y = s1; y <= s2; y ++) ans += f[x][y];
        }
    }
    printf("%I64d\n", ans);

    return 0;
}