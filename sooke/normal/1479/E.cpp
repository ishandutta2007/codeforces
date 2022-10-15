#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 998244353;

inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    }
    return res;
}

const int N = 1005;

int n, m, ans, a[N];

int main() {
    n = read();
    if (n == 1) { printf("0\n"); return 0; }
    for (int i = 0; i < n; i++) {
        a[i] = read(); m += a[i];
    }
    std::sort(a, a + n);
    int xp = 1, xq = 1, yp = 1, yq = 1;
    for (int i = 0, j = 1; j < m; j++) {
        for (; i < n && a[i] == j; i++) {
            ans = (ans + mod - 1ll * yp * power(yq, mod - 2) % mod) % mod;
        }
        xp = 1ll * xp * (m * 2 - j) % mod;
        xq = 1ll * xq * (m - j) % mod;
        yp = (1ll * xp * yq + 1ll * xq * yp) % mod;
        yq = 1ll * xq * yq % mod;
    }
    ans = 2 * (ans + 1ll * yp * power(yq, mod - 2)) % mod;
    printf("%d\n", ans);
    return 0;
}