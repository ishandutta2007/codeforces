#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e6 + 5;

int n, ans = 1e9, ansi, a[N], f[N], pos[N], sl[N], sr[N];
std::set<int> set;

struct SegmentTree {
    int f[N], g[N];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = std::max(f[ls], f[rs]) + g[u];
    }
    void build(int u, int l, int r) {
        if (l + 1 >= r) {
            f[u] = ::f[l]; return;
        } int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        build(ls, l, mid); build(rs, mid, r); pushUp(u);
    }
    void modify(int u, int l, int r, int pl, int pr, int x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) {
            f[u] += x; g[u] += x; return;
        } int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        if (pr <= mid) {
            modify(ls, l, mid, pl, pr, x);
        } else if (pl >= mid) {
            modify(rs, mid, r, pl, pr, x);
        } else {
            modify(ls, l, mid, pl, mid, x);
            modify(rs, mid, r, mid, pr, x);
        } pushUp(u);
    }
    int query(int u, int l, int r, int pl, int pr) {
        if (pl >= pr) { return -1e9; }
        if (l == pl && r == pr) { return f[u]; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        if (pr <= mid) {
            return g[u] + query(ls, l, mid, pl, pr);
        } else if (pl >= mid) {
            return g[u] + query(rs, mid, r, pl, pr);
        } else {
            return g[u] + std::max(query(ls, l, mid, pl, mid),
                                   query(rs, mid, r, mid, pr));
        }
    }
} smt;

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); a[i]--;
        pos[a[i]] = i;
    } set.insert(-1); set.insert(n);
    for (int i = 0; i < n; i++) {
        int u = pos[i];
        int l = *--set.lower_bound(u), x;
        int r = *set.lower_bound(u), y;
        if (l == -1) {
            x = 1;
        } else {
            x = f[l] + 1;
        }
        if (r == -1) {
            y = 1;
        } else {
            y = f[r] + 1;
        }
        f[u] = std::max(x, y); set.insert(u);
    } set.clear();
    for (int i = 0; i < n; i++) { a[i + n] = a[i]; }
    set.insert(-1); set.insert(n + n);
    for (int u, i = 0; i < n; i++) {
        u = pos[i];
        sl[u] = *--set.lower_bound(u);
        sr[u] = *set.lower_bound(u);
        u = pos[i] + n;
        sl[u] = *--set.lower_bound(u);
        sr[u] = *set.lower_bound(u);
        set.insert(u); set.insert(u - n);
    }
    smt.build(1, 0, n + n);
    for (int i = 0; i < n; i++) {
        int res = smt.query(1, 0, n + n, i, i + n);
        int l = sl[i + n], r = sr[i], x;
        if (r != n + n) {
            smt.modify(1, 0, n + n, i, r, -1);
        }
        if (l == -1) {
            x = 1;
        } else {
            x = smt.query(1, 0, n + n, l, l + 1) + 1;
        }
        smt.modify(1, 0, n + n, i + n, i + n + 1, x);
        if (l != -1) {
            smt.modify(1, 0, n + n, l + 1, i + n, 1);
        }
        if (ans > res) {
            ans = res; ansi = i;
        }
        
    } printf("%d %d\n", ans, ansi);
    return 0;
} //