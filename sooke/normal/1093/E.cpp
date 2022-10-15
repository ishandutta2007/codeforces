#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 200005, maxLen = 455;

int n, m, len, num, pos[maxN], bl[maxN], br[maxN], a[maxN], b[maxN], posA[maxN], posB[maxN], f[maxN], g[maxN];

void build(int u) {
    for (int i = bl[u]; i <= br[u]; i++) { g[i] = f[i]; }
    std::sort(g + bl[u], g + br[u] + 1);
}
int query(int l, int r, int x, int y) {
    int ans = 0;
    if (pos[l] + 1 >= pos[r]) {
        for (int i = l; i <= r; i++) { ans += f[i] >= x && f[i] <= y; }
        return ans;
    }
    for (int i = l; i < bl[pos[l] + 1]; i++) { ans += f[i] >= x && f[i] <= y; }
    for (int i = br[pos[r] - 1] + 1; i <= r; i++) { ans += f[i] >= x && f[i] <= y; }
    for (int i = pos[l] + 1; i <= pos[r] - 1; i++) { ans += std::lower_bound(g + bl[i], g + br[i] + 1, y + 1) - std::lower_bound(g + bl[i], g + br[i] + 1, x); }
    return ans;
}

int main() {
    n = read(); m = read(); len = sqrt(n);
    for (int i = 1; i <= n; i++) { a[i] = read(); posA[a[i]] = i; }
    for (int i = 1; i <= n; i++) { b[i] = read(); posB[b[i]] = i; }
    for (int i = 1; i <= n; i++) { f[i] = posB[a[i]]; }
    for (int i = 1; i <= n; i++) {
        pos[i] = (i - 1) / len + 1;
        if (!bl[pos[i]]) { bl[pos[i]] = i; } br[pos[i]] = i;
    }
    num = pos[n];
    for (int i = 1; i <= num; i++) { build(i); }
    for (; m; m--) {
        int opt = read();
        if (opt == 1) {
            int l = read(), r = read(), x = read(), y = read();
            printf("%d\n", query(l, r, x, y));
        } else {
            int u = read(), v = read(), x = posA[b[u]], y = posA[b[v]]; std::swap(b[u], b[v]);
            posB[b[u]] = u; posB[b[v]] = v; f[x] = posB[a[x]]; f[y] = posB[a[y]];
            build(pos[x]); build(pos[y]);
        }
    }
    return 0;
}