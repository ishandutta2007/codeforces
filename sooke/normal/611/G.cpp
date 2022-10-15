#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int mod = 1e9 + 7;

struct Point {
    long long x, y;
};

Point operator +(const Point &u, const Point &v) {
    return (Point) {u.x + v.x, u.y + v.y};
}
Point operator -(const Point &u, const Point &v) {
    return (Point) {u.x - v.x, u.y - v.y};
}
long long operator ^(const Point &u, const Point &v) {
    return u.x * v.y - u.y * v.x;
}

const int N = 1e6 + 5;

int n, ans;
long long f[N], g[N];
Point p[N], q[N];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        p[i].x = read(); p[i].y = read();
        q[i] = q[i - 1] + p[i];
        q[i].x %= mod; q[i].y %= mod;
    }
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + (p[i - 1] ^ p[i]);
        g[i] = (g[i - 1] + f[i]) % mod;
    }
    f[n + 1] = f[n] + (p[n] ^ p[1]);
    for (int i = 3, j = 1; i <= n; i++) {
        for (; j < i - 1 && std::abs(f[n + 1]) < std::abs((f[i] - f[j]) + (p[i] ^ p[j])) * 2.0L; j++);
        ans = (ans + f[i] % mod * (i - j - 1) - (g[i - 2] - g[j - 1]) + (p[i] ^ (q[i - 2] - q[j - 1]))) % mod;
        ans = (ans + (f[n + 1] - f[i]) % mod * (j - 1) + g[j - 1] - (p[i] ^ q[j - 1])) % mod;
    }
    ans = (ans + mod) * 2ll % mod;
    ans = (ans + std::abs(f[n + 1]) % mod * (n * (n - 3ll) / 2 % mod)) % mod;
    printf("%d\n", ans);
    return 0;
}