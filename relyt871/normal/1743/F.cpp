#include <bits/stdc++.h>
#define lc (rt << 1)
#define rc (rt << 1) | 1
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 300005;
const int M = 300000;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

namespace ModCalculator {
    const int MOD = 998244353;
    inline void Inc(int &x, int y) {
        x += y; if (x >= MOD) x -= MOD;
    }
    inline void Dec(int &x, int y) {
        x -= y; if (x < 0) x += MOD;
    }
    inline int Add(int x, int y) {
        Inc(x, y); return x;
    }
    inline int Sub(int x, int y) {
        Dec(x, y); return x;
    }
    inline int Mul(int x, int y) {
        return 1LL * x * y % MOD;
    }
    inline int Ksm(int x, int y) {
        int ret = 1;
        for (; y; y >>= 1) {
            if (y & 1) ret = Mul(ret, x);
            x = Mul(x, x);
        }
        return ret;
    }
    inline int Inv(int x) {
        return Ksm(x, MOD - 2);
    }
}
using namespace ModCalculator;

int n, l1, r1, has[MAXN << 2], ans;

struct Matrix {
    int a[2][2];
    Matrix() {}
    inline void I() {
        a[0][0] = a[1][1] = 1;
        a[0][1] = a[1][0] = 0;
    }
    Matrix operator * (const Matrix &b) const {
        Matrix ret;
        ret.a[0][0] = (1LL * a[0][0] * b.a[0][0] + 1LL * a[0][1] * b.a[1][0]) % MOD;
        ret.a[0][1] = (1LL * a[0][0] * b.a[0][1] + 1LL * a[0][1] * b.a[1][1]) % MOD;
        ret.a[1][0] = (1LL * a[1][0] * b.a[0][0] + 1LL * a[1][1] * b.a[1][0]) % MOD;
        ret.a[1][1] = (1LL * a[1][0] * b.a[0][1] + 1LL * a[1][1] * b.a[1][1]) % MOD;
        return ret;
    }
} seg[MAXN << 2], tag[MAXN << 2], IN, OUT;

inline void puttag(int rt, Matrix tg) {
    tag[rt] = tag[rt] * tg;
    has[rt] = 1;
}

inline void pushdown(int rt) {
    if (has[rt]) {
        puttag(lc, tag[rt]);
        puttag(rc, tag[rt]);
        tag[rt].I();
        has[rt] = 0;
    }
}

void Build(int rt, int b, int e) {
    has[rt] = 0;
    tag[rt].I();
    if (b == e) return;
    int mid = (b + e) >> 1;
    Build(lc, b, mid);
    Build(rc, mid + 1, e);
}

void Update(int rt, int b, int e, int l, int r, Matrix F) {
    if (l <= b && e <= r) {
        puttag(rt, F);
        return;
    }
    int mid = (b + e) >> 1;
    pushdown(rt);
    if (l <= mid) Update(lc, b, mid, l, r, F);
    if (r > mid) Update(rc, mid + 1, e, l, r, F);
}

int GetAns(int rt, int b, int e) {
    if (b == e) {
        if (l1 <= b && b <= r1) {
            return tag[rt].a[1][1];
        } else {
            return tag[rt].a[0][1];
        }
    }
    int mid = (b + e) >> 1;
    pushdown(rt);
    return Add(GetAns(lc, b, mid), GetAns(rc, mid + 1, e));
}

void solve() {
    IN.a[0][0] = IN.a[1][0] = 1;
    IN.a[0][1] = IN.a[1][1] = 2;
    OUT.a[0][0] = 3;
    OUT.a[1][0] = 1;
    OUT.a[1][1] = 2;
    read(n);
    Build(1, 0, M);
    read(l1); read(r1);
    for (int i = 2, l, r; i <= n; ++i) {
        read(l); read(r);
        if (l != 0) {
            Update(1, 0, M, 0, l - 1, OUT);
        }
        Update(1, 0, M, l, r, IN);
        if (r != M) {
            Update(1, 0, M, r + 1, M, OUT);
        }
    }
    printf("%d\n", GetAns(1, 0, M));
}

int main() {
    solve();
    return 0;
}