#include <cstdio>
#include <algorithm>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

inline int power(int x, int y, int p) { int res = 1; for (; y; y >>= 1, x = (long long) x * x % p) { if (y & 1) { res = (long long) res * x % p; } } return res; }

const int maxN = 300005, p1 = 998244353, b1 = 131, p2 = 167772161, b2 = 233;

int n, base1[maxN], base2[maxN], inv1[maxN], inv2[maxN];
bool flag;

struct FenwickTree {
    int p, f[maxN];

    inline void modify(int u, int x) { for (; u <= n; u += u & -u) { f[u] = (f[u] + x) % p; } }
    inline int query(int u) { int res = 0; for (; u; u ^= u & -u) { res = (res + f[u]) % p; } return res; }
    inline int query(int l, int r) { return (query(r) + p - query(l - 1)) % p; }
} a, b, c, d;

int main() {
    n = read(); a.p = b.p = p1; c.p = d.p = p2;
    for (int i = base1[0] = 1; i <= n; i++) { base1[i] = (long long) base1[i - 1] * b1 % p1; inv1[i] = power(base1[i], p1 - 2, p1); }
    for (int i = base2[0] = 1; i <= n; i++) { base2[i] = (long long) base2[i - 1] * b2 % p2; inv2[i] = power(base2[i], p2 - 2, p2); }
    for (int i = 1; i <= n; i++) {
        int x = read(), len = std::min(x - 1, n - x), l = x - len, r = x + len, f, g, h, k;
        f = (long long) a.query(l, x - 1) * inv1[l] % p1; a.modify(x, base1[x]);
        g = (long long) b.query(n + 1 - r, n - x) * inv1[n + 1 - r] % p1; b.modify(n + 1 - x, base1[n + 1 - x]);
        h = (long long) c.query(l, x - 1) * inv2[l] % p2; c.modify(x, base2[x]);
        k = (long long) d.query(n + 1 - r, n - x) * inv2[n + 1 - r] % p2; d.modify(n + 1 - x, base2[n + 1 - x]);
        if (f != g || h != k) { flag = true; }
    }
    printf("%s\n", flag ? "YES" : "NO");
    return 0;
}