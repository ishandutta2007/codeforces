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

const int N = 1e5 + 5;

int n, ans, f[N], mu[N];
std::vector<int> ds[N];

int main() {
    n = read();
    for (int d = 1; d <= n; d++) {
        for (int i = d; i <= n; i += d) {
            ds[i].push_back(d);
        }
    }
    for (int i = 1; i < n; i++) {
        mu[i] = 1;
        int x = i;
        for (auto d : ds[i]) {
            if (d == 1) { continue; }
            int c = 0;
            for (; x % d == 0; x /= d) { c++; }
            if (c > 1) { mu[i] = 0; break; }
            if (c == 1) { mu[i] *= -1; }
            if (x == 1) { break; }
        }
        for (auto d : ds[i]) {
            f[d] = (i - 1) / d;
        }
        for (auto d : ds[i]) {
            for (auto e : ds[d]) {
                if (d != e) {
                    f[e] = mu[d / e] == -1 ? sub(f[e], f[d]) : mu[d / e] == 1 ? add(f[e], f[d]) : f[e];
                }
            }
        }
        for (auto d : ds[i]) {
            ans = add(ans, 1ll * ((1ll * d * (n - i) / std::__gcd(d, n - i)) % mod) * f[d] % mod);
        }
    }
    printf("%d\n", ans);
    return 0;
}