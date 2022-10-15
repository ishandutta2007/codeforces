#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 998244353;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int power(int x, int y, int res = 1) {
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    } return res;
}

const int N = 1e5 + 5, M = 3600 + 5;

int r, c, n, ans, sumr, sumc, fac[N], invf[N], f[M][M], g[M][M];
bool usedr[N], usedc[N];

void initCombin(int n) {
    for (int i = fac[0] = 1; i <= n; i++) { fac[i] = 1ll * fac[i - 1] * i % mod; }
    invf[n] = power(fac[n], mod - 2);
    for (int i = n; i >= 1; i--) { invf[i - 1] = 1ll * invf[i] * i % mod; }
}

inline int permu(int n, int m) {
    if (n < m || n < 0 || m < 0) { return 0; }
    return 1ll * fac[n] * invf[n - m] % mod;
}

int main() {
    initCombin(1e5);
    r = read(); c = read(); n = read();
    for (int i = 1; i <= n; i++) {
        usedr[read()] = true;
        usedc[read()] = true;
        usedr[read()] = true;
        usedc[read()] = true;
    }
    for (int i = 1; i <= r; i++) { sumr += !usedr[i]; }
    for (int i = 1; i <= c; i++) { sumc += !usedc[i]; }
    f[0][0] = 1;
    for (int i = 1; i <= r; i++) {
        memcpy(f[i], f[i - 1], sizeof(f[i]));
        if (i >= 2 && !usedr[i] && !usedr[i - 1]) {
            for (int j = 1; j <= c; j++) { f[i][j] = add(f[i][j], f[i - 2][j - 1]); }
        }
    }
    g[0][0] = 1;
    for(int i = 1; i <= c; i++) {
        memcpy(g[i], g[i - 1], sizeof(g[i]));
        if (i >= 2 && !usedc[i] && !usedc[i - 1]) {
            for (int j = 1; j <= r; j++) { g[i][j] = add(g[i][j], g[i - 2][j - 1]); }
        }
    }
    for (int i = 0; i <= r / 2; i++) {
        for (int j = 0; j <= c / 2; j++) {
            ans = add(ans, 1ll * f[r][i] * g[c][j] % mod * permu(sumr - i * 2, j) % mod * permu(sumc - j * 2, i) % mod);
        }
    }
    printf("%d\n", ans);
    return 0;
}