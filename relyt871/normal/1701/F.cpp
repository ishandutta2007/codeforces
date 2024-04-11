#include <bits/stdc++.h>
#define lc (rt << 1)
#define rc (rt << 1) | 1
using namespace std;
typedef long long LL;
const int N = 200000;
const int MAXN = 200005;

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

bool in[MAXN], pd[MAXN << 2];

struct BIT {
    int tr[MAXN];
    inline void add(int x, int v) {
        for (; x <= N; x += (x & (-x))) {
            tr[x] += v;
        }
    }
    inline int sum(int x) {
        int ret = 0;
        for (; x; x -= (x & (-x))) {
            ret += tr[x];
        }
        return ret;
    }
    inline int qry(int l, int r) {
        return sum(r) - sum(l - 1);
    }
} bit;

struct Matrix {
    LL a[3][3];
    Matrix() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                a[i][j] = 0;
            }
        }
    }
    void I() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                a[i][j] = (i == j);
            }
        }
    }
    Matrix operator * (const Matrix &b) const {
        Matrix ret;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    ret.a[i][j] += a[i][k] * b.a[k][j];
                }
            }
        }
        return ret;
    }
} tag[MAXN << 2], ADD, SUB;

struct Data {
    LL a[3];
    Data() {
        for (int i = 0; i < 3; ++i) {
            a[i] = 0;
        }
    }
    Data operator * (const Matrix &b) const {
        Data ret;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ret.a[i] += a[j] * b.a[j][i];
            }
        }
        return ret;
    }
} seg[MAXN << 2];

inline void pushup(int rt) {
    for (int i = 0; i < 3; ++i) {
        seg[rt].a[i] = seg[lc].a[i] + seg[rc].a[i];
    }
}

inline void puttag(int rt, Matrix tg) {
    tag[rt] = tag[rt] * tg;
    seg[rt] = seg[rt] * tg;
    pd[rt] = 1;
}

inline void pushdown(int rt) {
    if (pd[rt]) {
        puttag(lc, tag[rt]);
        puttag(rc, tag[rt]);
        tag[rt].I();
        pd[rt] = 0;
    }
}

void Build(int rt, int b, int e) {
    tag[rt].I();
    if (b == e) return;
    int mid = (b + e) >> 1;
    Build(lc, b, mid);
    Build(rc, mid + 1, e);
}

void Update(int rt, int b, int e, int l, int r, Matrix v) {
    if (l <= b && e <= r) {
        puttag(rt, v);
        return;
    }
    int mid = (b + e) >> 1;
    pushdown(rt);
    if (l <= mid) Update(lc, b, mid, l, r, v);
    if (r > mid) Update(rc, mid + 1, e, l, r, v);
    pushup(rt);
}

void Modify(int rt, int b, int e, int pos, int x) {
    if (b == e) {
        if (x == -1) {
            seg[rt].a[0] = seg[rt].a[1] = seg[rt].a[2] = 0;
        } else {
            seg[rt].a[0] = 1;
            seg[rt].a[1] = x;
            seg[rt].a[2] = 1LL * x * x;
        }
        return;
    }
    int mid = (b + e) >> 1;
    pushdown(rt);
    if (pos <= mid) Modify(lc, b, mid, pos, x);
    else Modify(rc, mid + 1, e, pos, x);
    pushup(rt);
}

void solve() {
    ADD.a[0][0] = ADD.a[0][1] = ADD.a[0][2] = 1;
    ADD.a[1][1] = 1; ADD.a[1][2] = 2;
    ADD.a[2][2] = 1;
    SUB = ADD;
    SUB.a[0][1] = -1;
    SUB.a[1][2] = -2;
    Build(1, 1, N);

    int q, d, x;
    read(q); read(d);
    while (q--) {
        read(x);
        if (in[x]) {
            if (x < N) Update(1, 1, N, x + 1, min(N, x + d), SUB);
            Modify(1, 1, N, x, -1);
            bit.add(x, -1);
        } else {
            if (x < N) Update(1, 1, N, x + 1, min(N, x + d), ADD);
            Modify(1, 1, N, x, bit.qry(max(1, x - d), x - 1));
            bit.add(x, 1);
        }
        in[x] ^= 1;
        printf("%lld\n", (seg[1].a[2] - seg[1].a[1]) / 2);
    }
}

int main() {
    solve();
    return 0;
}