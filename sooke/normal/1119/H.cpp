#include <cstdio>

const int M = 18, N = 1 << M, p = 998244353, iv2 = 499122177, iv4 = 748683265;

inline int add(int x, int y) { x += y; return x >= p ? x - p : x; }
inline int sub(int x, int y) { x -= y; return x >= 0 ? x : x + p; }
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % p) { if (y & 1) { res = 1ll * res * x % p; } }
    return res;
}

void fwt(int f[], int n) {
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0, x, y; j < len; j++) {
                x = f[i + j], y = f[i + j + len];
                f[i + j] = add(x, y); f[i + j + len] = sub(x, y);
            }
        }
    }
}

int n, m, k, x, y, z, a, b, c, sum, f[N], g[N], h[N], ans[N];

int main() {
    scanf("%d%d%d%d%d", &m, &k, &x, &y, &z); n = 1 << k;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        sum ^= a; f[a ^ b]++; g[a ^ c]++; h[b ^ c]++;
    }
    fwt(f, n); fwt(g, n); fwt(h, n); ans[0] = 1;
    for (int i = 0; i < n; ans[++i] = 1) {
        ans[i] = 1ll * ans[i] * power(add(add(x, y), z), 1ll * add(add(add(m, f[i]), g[i]), h[i]) * iv4 % p) % p;
        ans[i] = 1ll * ans[i] * power(sub(add(x, y), z), 1ll * sub(sub(add(m, f[i]), g[i]), h[i]) * iv4 % p) % p;
        ans[i] = 1ll * ans[i] * power(add(sub(x, y), z), 1ll * sub(add(sub(m, f[i]), g[i]), h[i]) * iv4 % p) % p;
        ans[i] = 1ll * ans[i] * power(sub(sub(x, y), z), 1ll * add(sub(sub(m, f[i]), g[i]), h[i]) * iv4 % p) % p;
    }
    fwt(ans, n); k = power(iv2, k);
    for (int i = 0; i < n; i++) { printf("%I64d ", 1ll * ans[i ^ sum] * k % p); }
    return 0;
} //