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

const int N = 3e3 + 5;

int n, m, _m, ft[N], f[N][N];
std::vector<int> e[N];

void dfs(int u) {
    for (int i = 1; i <= m; i++) { f[u][i] = 1; }
    for (auto v : e[u]) {
        if (v == ft[u]) { continue; }
        dfs(v);
        for (int i = 1; i <= m; i++) { f[u][i] = 1ll * f[u][i] * f[v][i] % mod; }
    }
    for (int i = 2; i <= m; i++) { f[u][i] = add(f[u][i], f[u][i - 1]); }
}

int lagrange(int n) {
    int res = 0;
    for (int i = 1; i <= m; i++) {
        int u = 1, v = 1;
        for (int j = 1; j <= m; j++) {
            if (i == j) { continue; }
            u = 1ll * u * sub(n, j) % mod;
            v = 1ll * v * sub(i, j) % mod;
        }
        res = add(res, 1ll * f[1][i] * u % mod * power(v, mod - 2) % mod);
    }
    return res;
}

int main() {
    n = read(); _m = read(); m = n + 2;
    for (int u = 2; u <= n; u++) {
        ft[u] = read(); e[ft[u]].push_back(u);
    }
    dfs(1);
    printf("%d\n", lagrange(_m));
    return 0;
}