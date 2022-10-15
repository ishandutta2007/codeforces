#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int inf = 1e9;
const int N = 1e6 + 5;

int n, q, a[N];

struct Info {
    int l, r, x;
};

bool operator <(const Info &i, const Info &j) {
    return i.x < j.x;
}
Info operator -(const Info &i) {
    return (Info) {i.l, i.r, -i.x};
}
Info operator +(const Info &i, const Info &j) {
    return (Info) {i.l, j.r, i.x + j.x};
}

struct Node {
    Info sum, lmax, rmax, max, lmin, rmin, min;
};

Node operator -(const Node &f) {
    return (Node) {-f.sum, -f.lmin, -f.rmin, -f.min, -f.lmax, -f.rmax, -f.max};
}
Node operator +(const Node &f, const Node &g) {
    return (Node) {
        f.sum + g.sum,
        std::max(f.lmax, f.sum + g.lmax),
        std::max(f.rmax + g.sum, g.rmax),
        std::max(f.rmax + g.lmax, std::max(f.max, g.max)),
        std::min(f.lmin, f.sum + g.lmin),
        std::min(f.rmin + g.sum, g.rmin),
        std::min(f.rmin + g.lmin, std::min(f.min, g.min))
    };
}

struct SegmentTree {
    Node f[N];
    bool rev[N];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = f[ls] + f[rs];
    }
    inline void pushRev(int u) {
        rev[u] ^= 1; f[u] = -f[u];
    }
    inline void pushDown(int u) {
        if (rev[u]) {
            int ls = u << 1, rs = ls | 1;
            pushRev(ls); pushRev(rs);
            rev[u] = false;
        }
    }

    void modify(int u, int l, int r, int p, int x) {
        if (l + 1 >= r) {
            f[u].sum = (Info) {l, r, x};
            f[u].lmax = x > 0 ? (Info) {l, r, x} : (Info) {l, l, 0};
            f[u].rmax = f[u].max = x > 0 ? (Info) {l, r, x} : (Info) {r, r, 0};
            f[u].lmin = x < 0 ? (Info) {l, r, x} : (Info) {l, l, 0};
            f[u].rmin = f[u].min = x < 0 ? (Info) {l, r, x} : (Info) {r, r, 0};
            return;
        }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (p < mid) {
            modify(ls, l, mid, p, x);
        } else {
            modify(rs, mid, r, p, x);
        }
        pushUp(u);
    }
    void reverse(int u, int l, int r, int pl, int pr) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { pushRev(u); return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (pr <= mid) {
            reverse(ls, l, mid, pl, pr);
        } else if (pl >= mid) {
            reverse(rs, mid, r, pl, pr);
        } else {
            reverse(ls, l, mid, pl, mid);
            reverse(rs, mid, r, mid, pr);
        }
        pushUp(u);
    }
    void query(int u, int l, int r, int pl, int pr, Node &res) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { res = res + f[u]; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        pushDown(u);
        if (pr <= mid) {
            query(ls, l, mid, pl, pr, res);
        } else if (pl >= mid) {
            query(rs, mid, r, pl, pr, res);
        } else {
            query(ls, l, mid, pl, mid, res);
            query(rs, mid, r, mid, pr, res);
        }
        pushUp(u);
    }
} smt;

int query(int l, int r, int k) {
    int res = 0;
    Node f;
    f.sum = (Info) {0, 0, 0};
    f.lmax = f.rmax = f.max = (Info) {0, 0, -inf};
    f.lmin = f.rmin = f.min = (Info) {0, 0, inf};
    smt.query(1, 0, n, l, r, f);
    if (f.max.x == 0) {
        res = 0;
    } else {
        res = f.max.x;
        if (k > 1) {
            smt.reverse(1, 0, n, f.max.l, f.max.r);
            res += query(l, r, k - 1);
            smt.reverse(1, 0, n, f.max.l, f.max.r);
        }
    }
    return res;
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read();
        smt.modify(1, 0, n, i, a[i]);
    }
    q = read();
    for (int i = 0; i < q; i++) {
        int opt = read();
        if (opt == 0) {
            int p = read(), x = read(); p--;
            smt.modify(1, 0, n, p, x);
        } else {
            int l = read(), r = read(), k = read(); l--;
            printf("%d\n", query(l, r, k));
        }
    }
    return 0;
}