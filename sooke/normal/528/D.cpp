#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int power(int x, int y, int p) { int res = 1; for (; y; y >>= 1, x = 1ll * x * x % p) { if (y & 1) { res = 1ll * res * x % p; } } return res; }

const int maxN = 530000;

struct Poly {
    int n, p, g, invG, a[maxN];

    Poly() { p = 119 << 23 | 1; g = 3; invG = (p + 1) / g; }
    void ntt(int lim, int rev[], int sgn) {
        for (int i = 0; i < lim; i++) { if (i < rev[i]) { std::swap(a[i], a[rev[i]]); } }
        for (int len = 1, logLen = 1; len < lim; len <<= 1, logLen++) {
            int uni = power(sgn == 1 ? g : invG, (p + 1) >> logLen, p);
            for (int i = 0, w = 1; i < lim; i += len << 1, w = 1) {
                for (int j = 0; j < len; j++, w = 1ll * w * uni % p) { int x = 1ll * a[i + j + len] * w % p; a[i + j + len] = (a[i + j] + p - x) % p; (a[i + j] += x) %= p; }
            }
        }
        if (!~sgn) { for (int i = 0, invLim = power(lim, p - 2, p); i < lim; i++) { a[i] = 1ll * a[i] * invLim % p; } }
    }
} tmp1, tmp2, tmp3; int rev[maxN];
void mul(const Poly &f, const Poly &g, Poly &res) {
    int lim = 1, cnt = 0; while (lim <= f.n + g.n - 2) { lim <<= 1; cnt++; }
    for (int i = 1; i < lim; i++) { rev[i] = rev[i >> 1] >> 1 | (i & 1) << cnt - 1; }
    tmp1.n = f.n; memcpy(tmp1.a, f.a, sizeof(int) * lim); tmp1.ntt(lim, rev, 1);
    tmp2.n = g.n; memcpy(tmp2.a, g.a, sizeof(int) * lim); tmp2.ntt(lim, rev, 1);
    for (int i = 0; i < lim; i++) { res.a[i] = 1ll * tmp1.a[i] * tmp2.a[i] % f.p; }
    res.n = f.n + g.n - 1; res.ntt(lim, rev, -1);
}
Poly operator *(const Poly &f, const Poly &g) { memset(tmp3.a, 0, sizeof(tmp3.a)); mul(f, g, tmp3); return tmp3; }

// -------------------------------------  ------------------------------------- //

int n, m, k, ans, cnt[maxN];
std::string s, t;
Poly f, g;

void solve(char c) {
    f.n = n; g.n = m; memset(f.a, 0, sizeof(f.a)); memset(g.a, 0, sizeof(g.a)); // , .
    // ---------------------------------  f ------------------------------------- //
    for (int i = 0, lst = -1e9; i < n; i++) {
        if (s[i] == c) { lst = i; } //  c.
        if (i - lst <= k) { f.a[i] = 1; } // ,  1.
    }
    for (int i = n - 1, lst = 1e9; ~i; i--) {
        if (s[i] == c) { lst = i; } //  c.
        if (lst - i <= k) { f.a[i] = 1; } // ,  1.
    }
    // ---------------------------------  g ------------------------------------- //
    for (int i = 0; i < m; i++) { g.a[i] = t[m - 1 - i] == c; } // .
    // ---------------------------------  ------------------------------------- //
    f = f * g; for (int i = 0; i < f.n; i++) { cnt[i] += f.a[i]; }
}

int main() {
    std::cin >> n >> m >> k >> s >> t;
    for (int i = 0; i <= 3; i++) { solve("ACTG"[i]); } // .
    for (int i = 0; i <= n + m - 2; i++) { ans += cnt[i] == m; } //  m .
    std::cout << ans << std::endl;
    return 0;
} ///