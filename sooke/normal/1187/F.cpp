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

const int N = 1e6 + 5;

int n, ans, l[N], r[N], len[N], inv[N], p[N], q[N];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { l[i] = read(); }
    for (int i = 1; i <= n; i++) { r[i] = read(); }
    for (int i = 0; i <= n; i++) {
        len[i] = r[i] - l[i] + 1;
        inv[i] = power(len[i], mod - 2);
    }
    for (int i = 1; i <= n; i++) {
        p[i] = std::max(0, std::min(r[i - 1], r[i]) - std::max(l[i - 1], l[i]) + 1);
        p[i] = 1ll * p[i] * inv[i - 1] % mod * inv[i] % mod;
        if (i >= 2) {
            q[i] = std::max(0, std::min(std::min(r[i - 2], r[i - 1]), r[i]) - std::max(std::max(l[i - 2], l[i - 1]), l[i]) + 1);
            q[i] = 1ll * q[i] * inv[i - 2] % mod * inv[i - 1] % mod * inv[i] % mod;
            q[i] = add(1, sub(q[i], add(p[i], p[i - 1])));
            ans = add(ans, add(q[i], q[i]));
        }
    }
    for (int i = 1, sum = 0; i <= n; i++) {
        p[i] = sub(1, p[i]);
        ans = add(ans, 1ll * p[i] * add(add(sum, sum), 1) % mod);
        sum = add(sum, p[i - 1]);
    }
    printf("%d\n", ans);
    return 0;
}