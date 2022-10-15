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

const int maxN = 100005, p = 1e9 + 7;

int n, m;

struct Matrix { int a[2][2]; } emp, uni, fib, ans;
bool operator !=(const Matrix &x, const Matrix &y) { return x.a[0][0] != y.a[0][0] || x.a[0][1] != y.a[0][1] || x.a[1][0] != y.a[1][0] || x.a[1][1] != y.a[1][1]; }
Matrix operator +(const Matrix &x, const Matrix &y) {
    static Matrix res;
    res.a[0][0] = x.a[0][0] + y.a[0][0]; if (res.a[0][0] >= p) { res.a[0][0] -= p; }
    res.a[0][1] = x.a[0][1] + y.a[0][1]; if (res.a[0][1] >= p) { res.a[0][1] -= p; }
    res.a[1][0] = x.a[1][0] + y.a[1][0]; if (res.a[1][0] >= p) { res.a[1][0] -= p; } 
    res.a[1][1] = x.a[1][1] + y.a[1][1]; if (res.a[1][1] >= p) { res.a[1][1] -= p; }
    return res;
}
Matrix operator *(const Matrix &x, const Matrix &y) {
    static Matrix res;
    res.a[0][0] = (1ll * x.a[0][0] * y.a[0][0] + 1ll * x.a[0][1] * y.a[1][0]) % p;
    res.a[0][1] = (1ll * x.a[0][0] * y.a[0][1] + 1ll * x.a[0][1] * y.a[1][1]) % p;
    res.a[1][0] = (1ll * x.a[1][0] * y.a[0][0] + 1ll * x.a[1][1] * y.a[1][0]) % p;
    res.a[1][1] = (1ll * x.a[1][0] * y.a[0][1] + 1ll * x.a[1][1] * y.a[1][1]) % p;
    return res;
}
Matrix operator ^(Matrix x, int y) {
    static Matrix res; res = uni;
    for (; y; y >>= 1, x = x * x) { if (y & 1) { res = res * x; } }
    return res;
}

struct SegmentTree {
    Matrix f[maxN << 2], tag[maxN << 2];

    inline void pushUp(int u) { f[u] = f[u << 1] + f[u << 1 | 1]; }
    inline void pushTag(int u, const Matrix &x) { tag[u] = tag[u] * x; f[u] = f[u] * x; }
    inline void pushDown(int u) { if (tag[u] != uni) { pushTag(u << 1, tag[u]); pushTag(u << 1 | 1, tag[u]); tag[u] = uni; } }
    void build(int u, int l, int r) {
        if (l == r) { f[u] = fib ^ (read() - 1); return; }
        int mid = l + r >> 1; tag[u] = uni;
        build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r); pushUp(u);
    }
    void modify(int u, int l, int r, int pl, int pr, const Matrix &x) {
        if (l == pl && r == pr) { pushTag(u, x); return; }
        int mid = l + r >> 1; pushDown(u);
        if (pr <= mid) { modify(u << 1, l, mid, pl, pr, x); }
        else if (pl > mid) { modify(u << 1 | 1, mid + 1, r, pl, pr, x); }
        else { modify(u << 1, l, mid, pl, mid, x); modify(u << 1 | 1, mid + 1, r, mid + 1, pr, x); }
        pushUp(u);
    }
    void query(int u, int l, int r, int pl, int pr, Matrix &res) {
        if (l == pl && r == pr) { res = res + f[u]; return; }
        int mid = l + r >> 1; pushDown(u);
        if (pr <= mid) { query(u << 1, l, mid, pl, pr, res); }
        else if (pl > mid) { query(u << 1 | 1, mid + 1, r, pl, pr, res); }
        else { query(u << 1, l, mid, pl, mid, res); query(u << 1 | 1, mid + 1, r, mid + 1, pr, res); }
        pushUp(u);
    }
} tr;

int main() {
    n = read(); m = read();
    uni.a[0][0] = uni.a[1][1] = 1;
    fib.a[0][0] = fib.a[0][1] = fib.a[1][0] = 1;
    tr.build(1, 1, n);
    for (; m; m--) {
        int opt = read(), l = read(), r = read();
        if (opt == 1) { tr.modify(1, 1, n, l, r, fib ^ read()); }
        else { ans = emp; tr.query(1, 1, n, l, r, ans); printf("%d\n", ans.a[0][0]); }
    }
    return 0;
} ///