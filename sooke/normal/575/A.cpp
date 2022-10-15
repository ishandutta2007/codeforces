#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int mod;

struct Matrix {
    int a[2][2];
};

inline Matrix unit() {
    static Matrix res;
    res.a[0][0] = res.a[1][1] = 1;
    res.a[0][1] = res.a[1][0] = 0;
    return res;
}
Matrix operator *(const Matrix &f, const Matrix &g) {
    static Matrix res;
    res.a[0][0] = (1ll * f.a[0][0] * g.a[0][0] + 1ll * f.a[0][1] * g.a[1][0]) % mod;
    res.a[0][1] = (1ll * f.a[0][0] * g.a[0][1] + 1ll * f.a[0][1] * g.a[1][1]) % mod;
    res.a[1][0] = (1ll * f.a[1][0] * g.a[0][0] + 1ll * f.a[1][1] * g.a[1][0]) % mod;
    res.a[1][1] = (1ll * f.a[1][0] * g.a[0][1] + 1ll * f.a[1][1] * g.a[1][1]) % mod;
    return res;
}
Matrix operator ^(Matrix f, long long k) {
    static Matrix res; res = unit();
    for (; k; k /= 2, f = f * f) {
        if (k & 1) { res = res * f; }
    }
    return res;
}

const int N = 2e5 + 5;

int n, m, q, a[N];
long long k;
Matrix ans, s[N];

struct Element {
    long long i;
    int y, x;
} e[N];

bool operator <(const Element &i, const Element &j) {
    return i.i < j.i;
}

struct SegmentTree {
    Matrix f[N];
    
    void build(int u, int l, int r) {
        if (l + 1 >= r) { f[u] = s[l]; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        build(ls, l, mid); build(rs, mid, r);
        f[u] = f[rs] * f[ls];
    }
    void modify(int u, int l, int r, int p, int y, int x) {
        if (l + 1 >= r) { f[u].a[0][y] = x == -1 ? s[l].a[0][y] : x; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        if (p < mid) {
            modify(ls, l, mid, p, y, x);
        } else {
            modify(rs, mid, r, p, y, x);
        }
        f[u] = f[rs] * f[ls];
    }
    void query(int u, int l, int r, int pl, int pr, Matrix &res) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { res = f[u] * res; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        if (pr <= mid) {
            query(ls, l, mid, pl, pr, res);
        } else if (pl >= mid) {
            query(rs, mid, r, pl, pr, res);
        } else {
            query(ls, l, mid, pl, mid, res);
            query(rs, mid, r, mid, pr, res);
        }
    }
} smt;

int main() {
    k = read(); mod = read(); n = read();
    if (k <= 1) { printf("%lld\n", k % mod); return 0; }
    k--; //
    for (int i = 0; i < n; i++) {
        a[i] = read(); a[i] %= mod;
    }
    for (int i = 0; i < n; i++) {
        s[i].a[0][0] = a[(i + 1) % n]; s[i].a[0][1] = a[i];
        s[i].a[1][0] = 1 % mod; s[i].a[1][1] = 0;
    }
    smt.build(1, 0, n);
    for (q = read(); q; q--) {
        long long i = read();
        int x = read(); x %= mod;
        e[m++] = (Element) {i - 1, 0, x};
        e[m++] = (Element) {i, 1, x};
    }
    e[m++] = (Element) {k, 0, -1};
    std::sort(e, e + m); ans = unit();
    long long lst = -1;
    for (int i = 0, j; i < m; i = j) {
        ans = (smt.f[1] ^ (e[i].i / n - lst - 1)) * ans;
        for (j = i; j < m && e[i].i / n == e[j].i / n; j++) {
            smt.modify(1, 0, n, e[j].i % n, e[j].y, e[j].x);
        }
        if (e[i].i / n == k / n) {
            smt.query(1, 0, n, 0, k % n, ans);
            break;
        } else {
            ans = smt.f[1] * ans;
        }
        for (j = i; j < m && e[i].i / n == e[j].i / n; j++) {
            smt.modify(1, 0, n, e[j].i % n, e[j].y, -1);
        }
        lst = e[i].i / n;
    }
    printf("%d\n", ans.a[0][0]);
    return 0;
}