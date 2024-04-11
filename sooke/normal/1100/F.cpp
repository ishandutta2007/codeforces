#include <cstdio>
#include <algorithm>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

struct LinearBasis {
    int ver, f[20], g[20];
    
    void insert(int x) {
        int v = ver;
        for (int i = 19; ~i; i--) {
            if (x >> i & 1) {
                if (f[i]) {
                    if (g[i] <= v) { x ^= f[i]; f[i] ^= x; std::swap(g[i], v); }
                    else { x ^= f[i]; }
                } else { f[i] = x; g[i] = v; break; }
            }
        }
    }
    int query(int u) {
        int res = 0;
        for (int i = 19; ~i; i--) {
            if (g[i] >= u) { res = std::max(res, res ^ f[i]); }
        }
        return res;
    }
} bas[500005];

int main() {
    int n = read();
    for (int i = 1; i <= n; i++) { bas[i] = bas[i - 1]; bas[i].ver = i; bas[i].insert(read()); }
    for (int l, r, q = read(); q; q--) { l = read(); printf("%d\n", bas[read()].query(l)); }
    return 0;
}