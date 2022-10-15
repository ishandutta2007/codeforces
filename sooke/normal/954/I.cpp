#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int power(int x, int y, int p) { int res = 1; for (; y; y >>= 1, x = 1ll * x * x % p) { if (y & 1) { res = 1ll * res * x % p; } } return res; }

const int maxN = 262205;

struct Poly {
    int n, p, g, invG, a[maxN];

    Poly() { p = 119 << 23 | 1; g = 3; invG = (p + 1) / g; }
    void ntt(int lim, int rev[], int sgn) {
        for (int i = 0; i < lim; i++) { if (i < rev[i]) { std::swap(a[i], a[rev[i]]); } }
        for (int len = 1, logLen = 1; len < lim; len <<= 1, logLen++) {
            int uni = power(sgn == 1 ? g : invG, (p ^ 1) >> logLen, p);
            for (int i = 0, w = 1; i < lim; i += len << 1, w = 1) {
                for (int j = 0; j < len; j++, w = 1ll * w * uni % p) { int x = 1ll * a[i + j + len] * w % p; a[i + j + len] = (a[i + j] + p - x) % p; a[i + j] = (a[i + j] + x) % p; }
            }
        }
        if (!~sgn) { for (int i = 0, invLim = power(lim, p - 2, p); i < lim; i++) { a[i] = 1ll * a[i] * invLim % p; } }
    }
} tmp1, tmp2, tmp3; int rev[maxN];

int n, m, fa[maxN][6], ans[maxN];
std::string s, t;
Poly f[6], g[6], h;

int find(int pos, int u) { return fa[pos][u] == u ? u : fa[pos][u] = find(pos, fa[pos][u]); }

int main() {
    std::cin >> s >> t;
    n = s.size(); m = t.size(); reverse(t.begin(), t.end());
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= 5; j++) { fa[i][j] = j; }
    }
    int lim = 1, cnt = 0; while (lim <= n + m - 2) { lim <<= 1; cnt++; }
    for (int i = 1; i < lim; i++) { rev[i] = rev[i >> 1] >> 1 | (i & 1) << cnt - 1; }
    for (int x = 0; x <= 5; x++) { for (int i = 0; i < n; i++) { f[x].a[i] = s[i] - 'a' == x; } f[x].ntt(lim, rev, 1); }
    for (int x = 0; x <= 5; x++) { for (int i = 0; i < m; i++) { g[x].a[i] = t[i] - 'a' == x; } g[x].ntt(lim, rev, 1); }
    for (int x = 0; x <= 5; x++) {
        for (int y = 0; y <= 5; y++) {
            for (int i = 0; i < lim; i++) { h.a[i] = 1ll * f[x].a[i] * g[y].a[i] % h.p; } h.ntt(lim, rev, -1);
            for (int i = m - 1; i <= n - 1; i++) {
                if (h.a[i]) {
                    if (find(i - m + 1, x) != find(i - m + 1, y)) { fa[i - m + 1][find(i - m + 1, x)] = find(i - m + 1, y); ans[i - m + 1]++; }
                }
            }
        }
    }
    for (int i = 0; i <= n - m; i++) { printf("%d ", ans[i]); }
    return 0;
} ///