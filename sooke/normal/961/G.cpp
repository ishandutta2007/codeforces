#include <cstdio>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int p = 1e9 + 7;

inline int add(int x, int y) { x += y; return x >= p ? x - p : x; }
inline int sub(int x, int y) { x -= y; return x >= 0 ? x : x + p; }
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % p) { if (y & 1) { res = 1ll * res * x % p; } }
    return res;
}

const int N = 200005;

int n, m, sum, ans, f[N], fac[N], ivf[N], ivg[N];

void initCombin(int n) {
    for (int i = fac[0] = 1; i <= n; i++) { fac[i] = 1ll * fac[i - 1] * i % p; }
    ivf[n] = power(fac[n], p - 2);
    for (int i = n; i; i--) { ivf[i - 1] = 1ll * ivf[i] * i % p; }
    for (int i = 0; i <= n; i++) { ivg[i] = i & 1 ? sub(0, ivf[i]) : ivf[i]; }
}

int stirling(int k) {
    int res = 0;
    for (int i = 0; i <= k; i++) { res = add(res, 1ll * ivg[k - i] * ivf[i] % p * f[i] % p); }
    return res;
}

int main() {
    n = read(); m = read(); initCombin(m);
    for (int i = 1; i <= n; i++) { sum = add(sum, read()); }
    for (int i = 0; i <= m; i++) { f[i] = power(i, n - 1); }
    ans = (n - 1ll) * stirling(m) % p;
    for (int i = 0; i <= m; i++) { f[i] = 1ll * f[i] * i % p; }
    printf("%I64d\n", 1ll * sum * add(ans, stirling(m)) % p);
    return 0;
}