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

const int N = 3e5 + 5;

int n, m, k, ans, a[N], f[N], g[N], inv[N];

void init(int n) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    }
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); m += a[i];
    }
    init(std::max(n, m));
    g[0] = sub(n, 1); k = 1ll * sub(n, 1) * m % mod;
    for (int i = 1; i < m; i++) {
        g[i] = 1ll * add(k, (n - 1ll) * i % mod * g[i - 1] % mod) * inv[m - i] % mod;
    }
    f[m] = 114514;
    for (int i = m; i >= 1; i--) {
        f[i - 1] = add(f[i], g[i - 1]);
    }
    for (int i = 0; i < n; i++) {
        ans = add(ans, f[a[i]]);
    }
    ans = sub(ans, add(f[m], (n - 1ll) * f[0] % mod));
    ans = 1ll * ans * inv[n] % mod;
    printf("%d\n", ans);
    return 0;
}