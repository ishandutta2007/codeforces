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

const int maxN = 200005;

int n, m, a[5][maxN];

struct SegmentTree {
    int min[maxN << 2], max[maxN << 2];
    
    inline void modify(int u, int l, int r, int p, int x) {
        if (l == r) { min[u] = max[u] = x; return; }
        int mid = l + r >> 1;
        if (p <= mid) { modify(u << 1, l, mid, p, x); } else { modify(u << 1 | 1, mid + 1, r, p, x); }
        min[u] = std::min(min[u << 1], min[u << 1 | 1]); max[u] = std::max(max[u << 1], max[u << 1 | 1]);
    }
    inline void query(int u, int l, int r, int pl, int pr, int &resMin, int &resMax) {
        if (l == pl && r == pr) { resMin = std::min(resMin, min[u]); resMax = std::max(resMax, max[u]); return; }
        int mid = l + r >> 1;
        if (pr <= mid) { query(u << 1, l, mid, pl, pr, resMin, resMax); }
        else if (pl > mid) { query(u << 1 | 1, mid + 1, r, pl, pr, resMin, resMax); }
        else { query(u << 1, l, mid, pl, mid, resMin, resMax); query(u << 1 | 1, mid + 1, r, mid + 1, pr, resMin, resMax); }
    }
} tr[32];

void modify(int dep, int d, int p, int x) {
    if (dep == m) { tr[d].modify(1, 1, n, p, x); return; }
    modify(dep + 1, d << 1, p, x + a[dep][p]); modify(dep + 1, d << 1 | 1, p, x - a[dep][p]);
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) { a[j][i] = read(); }
        modify(0, 0, i, 0);
    }
    for (int q = read(); q; q--) {
        int opt = read();
        if (opt == 1) {
            int u = read();
            for (int i = 0; i < m; i++) { a[i][u] = read(); }
            modify(0, 0, u, 0);
        } else {
            int ans = 0, l = read(), r = read();
            for (int i = 0; i < 1 << m; i++) { int min = 1e9, max = -1e9; tr[i].query(1, 1, n, l, r, min, max); ans = std::max(ans, max - min); }
            printf("%d\n", ans);
        }
    }
    return 0;
} //