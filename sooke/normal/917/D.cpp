#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    }
    return res;
}

const int N = 1e3 + 5;

int n, siz[N], f[N][N][2], g[N], fac[N], invf[N];

struct List {
    int tot, fst[N], nxt[N], to[N];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v) {
        nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++;
    }
    inline void link(int u, int v) {
        insert(u, v); insert(v, u);
    }
} e;

void initCombin(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) { fac[i] = 1ll * fac[i - 1] * i % mod; }
    invf[n] = power(fac[n], mod - 2);
    for (int i = n; i >= 1; i--) { invf[i - 1] = 1ll * invf[i] * i % mod; }
}
inline int binom(int x, int y) {
    if (x < y || y < 0) { return 0; }
    return 1ll * fac[x] * invf[y] % mod * invf[x - y] % mod;
}

void dfs(int u, int fa) {
    siz[u] = 1;
    f[u][0][0] = f[u][0][1] = 1;
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i];
        if (v == fa) { continue; }
        dfs(v, u);
        for (int j = siz[u] + siz[v]; j >= 0; j--) {
            int res0 = 0, res1 = 0;
            for (int k = std::max(0, j - siz[u]); k <= siz[v] && k <= j; k++) {
                res0 = add(res0, 1ll * f[v][k][0] * f[u][j - k][0] % mod);
                res1 = add(res1, 1ll * f[v][k][1] * f[u][j - k][0] % mod);
                res1 = add(res1, 1ll * f[v][k][0] * f[u][j - k][1] % mod);
            }
            f[u][j][0] = res0;
            f[u][j][1] = res1;
        }
        siz[u] += siz[v];
    }
    if (u == 1) {
        for (int i = siz[u]; i >= 2; i--) {
            g[n - i] = 1ll * f[u][i - 1][1] * power(n, i - 2) % mod;
        }
        g[n - 1] = 1;
    } else {
        for (int i = siz[u]; i >= 1; i--) {
            f[u][i][0] = add(f[u][i][0], f[u][i - 1][1]);
        }
    }
}

int main() {
    n = read();
    initCombin(n);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e.link(u, v);
    }
    dfs(1, 0);
    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = i; j < n; j++) {
            if (j - i & 1) {
                ans = sub(ans, 1ll * binom(j, i) * g[j] % mod);
            } else {
                ans = add(ans, 1ll * binom(j, i) * g[j] % mod);
            }
        }
        printf("%d ", ans);
    }
    return 0;
}