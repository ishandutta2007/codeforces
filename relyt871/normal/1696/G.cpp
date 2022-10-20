#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define lc (rt << 1)
#define rc (rt << 1) | 1
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const double INF = 1e18;

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

int n, q, X, Y, arr[MAXN];

struct Matrix {
    double a[3][3];
    Matrix() {}
    Matrix(int x) {
        a[0][0] = a[1][0] = a[2][0] = 0;
        a[0][1] = a[1][1] = 1.0 / (X + Y) * x; a[2][1] = -INF;
        a[0][2] = 1.0 / Y * x; a[1][2] = a[2][2] = -INF;
    }
    Matrix operator * (const Matrix &b) const {
        Matrix ret;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                double tmp = 0;
                for (int k = 0; k < 3; ++k) {
                    tmp = max(tmp, a[i][k] + b.a[k][j]);
                }
                ret.a[i][j] = tmp;
            }
        }
        return ret;
    }
} seg[MAXN << 2];

void Build(int rt, int b, int e) {
    if (b == e) {
        seg[rt] = Matrix(arr[b]);
        return;
    }
    int mid = (b + e) >> 1;
    Build(lc, b, mid);
    Build(rc, mid + 1, e);
    seg[rt] = seg[lc] * seg[rc];
}

void Update(int rt, int b, int e, int p) {
    if (b == e) {
        seg[rt] = Matrix(arr[b]);
        return;
    }
    int mid = (b + e) >> 1;
    if (p <= mid) Update(lc, b, mid, p);
    else Update(rc, mid + 1, e, p);
    seg[rt] = seg[lc] * seg[rc];
}

Matrix Query(int rt, int b, int e, int l, int r) {
    if (l <= b && e <= r) return seg[rt];
    int mid = (b + e) >> 1;
    if (r <= mid) return Query(lc, b, mid, l, r);
    if (l > mid) return Query(rc, mid + 1, e, l, r);
    return Query(lc, b, mid, l, r) * Query(rc, mid + 1, e, l, r);
}

void solve() {
    read(n); read(q);
    read(X); read(Y);
    if (X > Y) swap(X, Y);
    for (int i = 1; i <= n; ++i) {
        read(arr[i]);
    }
    Build(1, 1, n);
    while (q--) {
        int type, l, r;
        read(type); read(l); read(r);
        if (type == 1) {
            arr[l] = r;
            Update(1, 1, n, l);
        } else {
            Matrix cur = Query(1, 1, n, l, r);
            double ans = 0;
            for (int i = 0; i < 3; ++i) {
                ans = max(ans, cur.a[0][i]);
            }
            printf("%.10lf\n", ans);
        }
    }
}

int main() {
    solve();
    return 0;
}