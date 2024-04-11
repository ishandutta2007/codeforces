#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

inline int read() {
    char c = getchar(); int x = 0; bool sgn = false;
    while (c < '0' || c > '9') { if (c == '-') { sgn = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return sgn ? -x : x;
}

const int N = 500005, p = 1e9 + 7;

inline int add(int x, int y) { x += y; return x >= p ? x - p : x; }
inline int sub(int x, int y) { x -= y; return x >= 0 ? x : x + p; }

int n, ans, a[N], b[N], f[N], g[N];

struct FenwickTree {
    int f[N];

    inline void reset() { memset(f, 0, sizeof(int) * (n + 1)); }
    inline void modify(int u, int x) { for (; u <= n; u += u & -u) { f[u] = add(f[u], x); } }
    inline int query(int u) { int res = 0; for (; u; u ^= u & -u) { res = add(res, f[u]); } return res; }
} bit;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = b[i] = read(); }
    std::sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) { a[i] = std::lower_bound(b + 1, b + n + 1, a[i]) - b; }
    for (int i = 1; i <= n; i++) { f[i] = bit.query(a[i]); bit.modify(a[i], i); } bit.reset();
    for (int i = n; i; i--) { g[i] = bit.query(a[i]); bit.modify(a[i], n + 1 - i); }
    for (int i = 1; i <= n; i++) { ans = add(ans, 1ll * b[a[i]] * add(add(1ll * f[i] * (n + 1 - i) % p, 1ll * g[i] * i % p), 1ll * i * (n + 1 - i) % p) % p); }
    printf("%d\n", ans);
    return 0;
}