#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 998244353;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : 0;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int power(int x, int y, int res = 1) {
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    } return res;
}

const int N = 1e6 + 5;

int n, m, a[N];
bool c[N];

struct Matrix {
    int a[3][3];
} ini, res, p[N], q[N], used[N];

Matrix operator *(const Matrix &f, const Matrix &g) {
    static Matrix res;
    res.a[0][0] = (1ll * f.a[0][0] * g.a[0][0] + 1ll * f.a[0][1] * g.a[1][0] + 1ll * f.a[0][2] * g.a[2][0]) % mod;
    res.a[0][1] = (1ll * f.a[0][0] * g.a[0][1] + 1ll * f.a[0][1] * g.a[1][1] + 1ll * f.a[0][2] * g.a[2][1]) % mod;
    res.a[0][2] = (1ll * f.a[0][0] * g.a[0][2] + 1ll * f.a[0][1] * g.a[1][2] + 1ll * f.a[0][2] * g.a[2][2]) % mod;
    res.a[1][0] = (1ll * f.a[1][0] * g.a[0][0] + 1ll * f.a[1][1] * g.a[1][0] + 1ll * f.a[1][2] * g.a[2][0]) % mod;
    res.a[1][1] = (1ll * f.a[1][0] * g.a[0][1] + 1ll * f.a[1][1] * g.a[1][1] + 1ll * f.a[1][2] * g.a[2][1]) % mod;
    res.a[1][2] = (1ll * f.a[1][0] * g.a[0][2] + 1ll * f.a[1][1] * g.a[1][2] + 1ll * f.a[1][2] * g.a[2][2]) % mod;
    res.a[2][0] = (1ll * f.a[2][0] * g.a[0][0] + 1ll * f.a[2][1] * g.a[1][0] + 1ll * f.a[2][2] * g.a[2][0]) % mod;
    res.a[2][1] = (1ll * f.a[2][0] * g.a[0][1] + 1ll * f.a[2][1] * g.a[1][1] + 1ll * f.a[2][2] * g.a[2][1]) % mod;
    res.a[2][2] = (1ll * f.a[2][0] * g.a[0][2] + 1ll * f.a[2][1] * g.a[1][2] + 1ll * f.a[2][2] * g.a[2][2]) % mod;
    return res;
}

struct SegmentTree {
    Matrix f[N];

    inline void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        f[u] = f[rs] * f[ls];
    }
    
    void build(int u, int l, int r) {
        if (r - l <= 1) { f[u] = used[l]; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        build(ls, l, mid); build(rs, mid, r);
        pushUp(u);
    }
    void modify(int u, int l, int r, int p, Matrix x) {
        if (r - l <= 1) { f[u] = x; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        if (p < mid) {
            modify(ls, l, mid, p, x);
        } else {
            modify(rs, mid, r, p, x);
        }
        pushUp(u);
    }
} smt;

int main() {
    n = read(); m = read();
    for (int i = 0; i < n; i++) {
        a[i] = 1ll * read() * power(100, mod - 2) % mod;
        a[i] = power(a[i], mod - 2) % mod;
    }
    ini.a[2][0] = 1;
    ini.a[2][1] = 1;
    ini.a[2][2] = 1;
    for (int i = 0; i <= n; i++) {
        p[i].a[0][0] = 1;
        p[i].a[0][1] = 0;
        p[i].a[0][2] = 0;
        p[i].a[1][0] = 0;
        p[i].a[1][1] = a[i];
        p[i].a[1][2] = a[i];
        p[i].a[2][0] = 0;
        p[i].a[2][1] = 0;
        p[i].a[2][2] = 1;
        q[i].a[0][0] = 1;
        q[i].a[0][1] = 1;
        q[i].a[0][2] = 0;
        q[i].a[1][0] = 0;
        q[i].a[1][1] = 0;
        q[i].a[1][2] = a[i];
        q[i].a[2][0] = 0;
        q[i].a[2][1] = 0;
        q[i].a[2][2] = 1;
        if (i == n) {
            used[i] = q[i];
        } else {
            used[i] = p[i];
        } 
    }
    smt.build(1, 0, n + 1);
    for (int i = 0; i < m; i++) {
        int u = read(); u--;
        if (!c[u]) {
            smt.modify(1, 0, n + 1, u, q[u]);
        } else {
            smt.modify(1, 0, n + 1, u, p[u]);
        }
        c[u] ^= 1;
        // for (int x = 0; x < 3; x++) {
        //     for (int y = 0; y < 3; y++) {
        //         printf("%d ", smt.f[1].a[x][y]);
        //     }
        //     printf("\n");
        // }
        res = smt.f[1] * ini;
        printf("%d\n", res.a[0][0]);
    }
    return 0;
}