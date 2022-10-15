#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

const int p = 998244353, gen = 3;

inline int add(int x, int y) { x += y; return x >= p ? x - p : x; }
inline int sub(int x, int y) { x -= y; return x >= 0 ? x : x + p; }
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % p) { if (y & 1) { res = 1ll * res * x % p; } }
    return res;
}

namespace Polynom {
    std::vector<int> rev, root;

    void getRevRoot(int n) {
        int m = std::log(n) / std::log(2) + 1e-7; rev.resize(n); root.resize(n);
        for (int i = 1; i < n; i++) { rev[i] = rev[i >> 1] >> 1 | (i & 1) << m - 1; }
        for (int len = 1, uni; len < n; len <<= 1) {
            uni = power(gen, (p ^ 1) / (len << 1)); root[len] = 1;
            for (int i = 1; i < len; i++) { root[i + len] = 1ll * root[i + len - 1] * uni % p; }
        }
    }
    void ntt(std::vector<int> &f, int n) {
        f.resize(n);
        for (int i = 0; i < n; i++) { if (i < rev[i]) { std::swap(f[i], f[rev[i]]); } }
        for (int len = 1; len < n; len <<= 1) {
            for (int i = 0; i < n; i += len << 1) {
                for (int j = 0, x, y; j < len; j++) {
                    x = f[i + j]; y = 1ll * f[i + j + len] * root[j + len] % p;
                    f[i + j] = add(x, y); f[i + j + len] = sub(x, y);
                }
            }
        }
    }
    std::vector<int> operator *(std::vector<int> f, std::vector<int> g) {
        int n = 1, m = (int) f.size() + (int) g.size() - 1, ivn;
        while (n < m) { n <<= 1; } ivn = power(n, p - 2);
        getRevRoot(n); ntt(f, n); ntt(g, n);
        for (int i = 0; i < n; i++) { f[i] = 1ll * f[i] * g[i] % p; }
        std::reverse(f.begin() + 1, f.end()); ntt(f, n); f.resize(m);
        for (int i = 0; i < m; i++) { f[i] = 1ll * f[i] * ivn % p; } return f;
    }
}

using Polynom::operator *;

int n, s, t;
std::vector<int> f;

int binomial(int n, int m) {
    int x = 1, y = 1;
    for (int i = n; i; i--) { x = 1ll * x * i % p; }
    for (int i = m; i; i--) { y = 1ll * y * i % p; }
    for (int i = n - m; i; i--) { y = 1ll * y * i % p; }
    return 1ll * x * power(y, p - 2) % p;
}

std::vector<int> stirling(int l, int r) {
    if (l == r) { return {l, 1}; } int mid = l + r >> 1;
    return stirling(l, mid) * stirling(mid + 1, r);
}

int main() {
    scanf("%d%d%d", &n, &s, &t);
    if (!s || !t || s + t > n + 1) { printf("0\n"); return 0; }
    if (s + t == 2) { printf("%d\n", n == 1 ? 1 : 0); return 0; }
    f = stirling(0, n - 2); printf("%I64d\n", 1ll * binomial(s + t - 2, s - 1) * f[s + t - 2] % p);
    return 0;
}

// lj remotejudge