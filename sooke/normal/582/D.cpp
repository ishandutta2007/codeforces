#include <bits/stdc++.h>

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int s1(int x) {
    return x * (x + 1ll) / 2 % mod;
}

const int N = 3500;

int p, q, n, ans, a[N], dig[N], f[N][N][2][2];
char str[N];

void transform() {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        dig[i] = str[i] - '0';
    }
    bool flag = true;
    while (flag) {
        flag = false;
        long long ret = 0;
        for (int i = 0; i < len; i++) {
            ret = ret * 10 + dig[i];
            dig[i] = ret / p; ret %= p;
            if (dig[i] > 0) { flag = true; }
        }
        a[++n] = ret;
    }
}

void solve() {
    f[n][0][0][0] = 1;
    for (int i = n; i >= 1; i--) {
        int j = i - 1;
        for (int x = 0; x < n; x++) {
            for (int u = 0; u < 2; u++) {
                int y = x + u;
                for (int v = 0; v < 2; v++) {
                    int k = u == 0 ? a[i] + 1 - v : p - (a[i] + 1 - v);
                    f[j][y][v][0] = add(f[j][y][v][0], 1ll * k * f[i][x][u][0] % mod);
                    k = u == 0 ? s1(a[i] - v) : sub(1ll * p * a[i] % mod, s1(a[i] - v));
                    f[j][y][v][1] = add(f[j][y][v][1], 1ll * k * f[i][x][u][0] % mod);
                    k = u == 0 ? s1(p - v) : sub(1ll * p * p % mod, s1(p - v));
                    f[j][y][v][1] = add(f[j][y][v][1], 1ll * k * f[i][x][u][1] % mod);
                }
            }
        }
    }
    for (int i = q; i <= n; i++) {
        ans = add(ans, f[0][i][0][0]);
        ans = add(ans, f[0][i][0][1]);
    }
}

int main() {
    scanf("%d%d%s", &p, &q, str);
    if (str[0] == '0') { printf("0\n"); return 0; }
    transform();
    if (q >= n) { printf("0\n"); return 0; }
    solve();
    printf("%d\n", ans);
    return 0;
}