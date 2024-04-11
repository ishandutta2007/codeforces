#include <cstdio>
#include <vector>

inline int read() {
    char c = getchar();
    while (c != '0' && c != '1') { c = getchar(); }
    return c & 15;
}

const int p = 998244353;

inline int add(int x, int y) { x += y; return x >= p ? x - p : x; }
inline int sub(int x, int y) { x -= y; return x < 0 ? x + p : x; }
inline int half(int x) { return x & 1 ? x + p >> 1 : x >> 1; }

namespace Poly {
    void fwt(std::vector<int> &f, int n, int d) {
        f.resize(n);
        for (int len = 1; len < n; len <<= 1) {
            for (int i = 0; i < n; i += len << 1) {
                for (int j = 0; j < len; j++) {
                    int x = d & 1 ? f[i + j] : half(f[i + j]), y = d & 1 ? f[i + j + len] : half(f[i + j + len]);
                    f[i + j] = add(x, y); f[i + j + len] = sub(x, y);
                }
            }
        }
    }

    std::vector<int> operator ^(std::vector<int> f, std::vector<int> g) {
        int n = std::max(f.size(), g.size()); fwt(f, n, 1); fwt(g, n, 1);
        for (int i = 0; i < n; i++) { f[i] = (long long) f[i] * g[i] % p; }
        fwt(f, n, 2); return f;
    }
}

using Poly::operator ^;

const int maxN = 20, maxM = 1000005;

int n, m, lim, ans = 2e9, a[maxM];
std::vector<int> f, g;

int main() {
    scanf("%d%d", &n, &m); lim = 1 << n; g.resize(lim);
    for (int i = 0; i < lim; i++) { f.push_back(std::min(__builtin_popcount(i), n - __builtin_popcount(i))); }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) { a[j] |= read() << i; }
    }
    for (int i = 1; i <= m; i++) { g[a[i]]++; }
    f = f ^ g;
    for (int i = 0; i < lim; i++) { ans = std::min(ans, f[i]); }
    printf("%d\n", ans);
    return 0;
}