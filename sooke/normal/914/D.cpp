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

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

const int maxN = 500005;

int n, m;

struct SegmentTree {
    int c[maxN << 2];

    inline void pushUp(int u) { c[u] = gcd(c[u << 1], c[u << 1 | 1]); }
    void build(int u, int l, int r) {
        if (l == r) { c[u] = read(); return; }
        int mid = l + r >> 1; build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
        pushUp(u);
    }
    void modify(int u, int l, int r, int p, int x) {
        if (l == r) { c[u] = x; return; }
        int mid = l + r >> 1;
        if (p <= mid) { modify(u << 1, l, mid, p, x); } else { modify(u << 1 | 1, mid + 1, r, p, x); }
        pushUp(u);
    }
    int query(int u, int l, int r, int pl, int pr, int x, bool flag) {
        if (l == pl && r == pr) { flag = true; }
        if (l == r) { return c[u] % x != 0; }
        int mid = l + r >> 1;
        if (pr <= mid) { return query(u << 1, l, mid, pl, pr, x, flag); }
        else if (pl > mid) { return query(u << 1 | 1, mid + 1, r, pl, pr, x, flag); }
        else if (flag) {
            if (c[u << 1] % x == 0) { return query(u << 1 | 1, mid + 1, r, mid + 1, pr, x, flag); }
            if (c[u << 1 | 1] % x == 0) { return query(u << 1, l, mid, pl, mid, x, flag); }
            return 2;
        } else { return query(u << 1, l, mid, pl, mid, x, flag) + query(u << 1 | 1, mid + 1, r, mid + 1, pr, x, flag); }
    }
} tr;

int main() {
    n = read(); tr.build(1, 1, n);
    for (m = read(); m; m--) {
        int opt = read();
        if (opt == 1) {
            int l = read(), r = read(), x = read();
            printf("%s\n", tr.query(1, 1, n, l, r, x, false) <= 1 ? "YES" : "NO");
        } else {
            int u = read(), x = read();
            tr.modify(1, 1, n, u, x);
        }
    }
    return 0;
} ///