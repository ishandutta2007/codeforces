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

const int N = 1e6 + 5, M = 1e7 + 5;

int n, m, np, ans, pri[N], mu[M], a[N], pwr[N], f[M];
bool vis[M];

void sieve(int n) {
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) { pri[np++] = i; mu[i] = -1; }
        for (int j = 0; j < np; j++) {
            int k = i * pri[j];
            if (k > n) { break; }
            vis[k] = true;
            if (i % pri[j] == 0) { break; }
            mu[k] = -mu[i];
        }
    }
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); f[a[i]]++;
    }
    m = *std::max_element(a, a + n);
    sieve(m);
    pwr[0] = 1;
    for (int i = 1; i <= n; i++) {
        pwr[i] = add(pwr[i - 1], pwr[i - 1]);
    }
    for (int j = 0; j < np; j++) {
        for (int i = m / pri[j], k = i * pri[j]; i >= 1; i--, k -= pri[j]) {
            f[i] += f[k];
        }
    }
    for (int i = 1; i <= m; i++) {
        int res = sub(pwr[f[i]], 1);
        if (mu[i] == 1) { ans = add(ans, res); }
        if (mu[i] == -1) { ans = sub(ans, res); }
    }
    ans = 1ll * sub(0, ans) * n % mod;
    for (int i = 1; i <= m; i++) {
        int res = 1ll * sub(pwr[f[i]], 1) * f[i] % mod;
        if (mu[i] == 1) { ans = add(ans, res); }
        if (mu[i] == -1) { ans = sub(ans, res); }
    }
    printf("%d\n", ans);
    return 0;
}