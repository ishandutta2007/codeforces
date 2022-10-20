#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define lc (rt << 1)
#define rc (rt << 1) | 1
using namespace std;
typedef long long LL;
const int MAXN = 500005;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const LL INF2 = INF / 2;

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

template <typename T> inline void cmax(T &x, T y) {
    if (x < y) x = y;
}

int n, q, a[3][MAXN];
LL pre[3][MAXN], suf[3][MAXN], dp[MAXN];
vector<pii> spe[MAXN];

struct Node {
    LL lmx, rmx, mx;
    Node() {}
    Node(LL _lmx, LL _rmx, LL _mx): lmx(_lmx), rmx(_rmx), mx(_mx) {}
    Node operator + (const Node &rhs) const {
        Node ret;
        ret.lmx = max(lmx, rhs.lmx);
        ret.rmx = max(rmx, rhs.rmx);
        ret.mx = max(max(mx, rhs.mx), lmx + rhs.rmx);
        return ret;
    }
};

struct SegmentTree {
    Node seg[MAXN << 2];

    void Build(int rt, int b, int e) {
        if (b == e) {
            seg[rt] = Node(-INF, pre[1][b] + suf[2][b], -INF);
            return;
        }
        int mid = (b + e) >> 1;
        Build(lc, b, mid);
        Build(rc, mid + 1, e);
        seg[rt] = seg[lc] + seg[rc];
    }

    void Update(int rt, int b, int e, int p, LL val) {
        if (b == e) {
            cmax(seg[rt].lmx, val);
            return;
        }
        int mid = (b + e) >> 1;
        if (p <= mid) Update(lc, b, mid, p, val);
        else Update(rc, mid + 1, e, p, val);
        seg[rt] = seg[lc] + seg[rc];
    }

    Node Query(int rt, int b, int e, int l, int r) {
        if (l <= b && e <= r) return seg[rt];
        int mid = (b + e) >> 1;
        if (r <= mid) return Query(lc, b, mid, l, r);
        if (l > mid) return Query(rc, mid + 1, e, l, r);
        return Query(lc, b, mid, l, r) + Query(rc, mid + 1, e, l, r);
    }
} SEG;

void solve() {
    read(n); read(q);
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            read(a[i][j]);
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            pre[i][j] = pre[i][j - 1] + a[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = n; j >= 1; --j) {
            suf[i][j] = suf[i][j + 1] + a[i][j];
        }
    }
    for (int i = 1, l, r, k; i <= q; ++i) {
        read(l); read(r); read(k);
        spe[r].push_back(make_pair(l, k));
    }

    LL ans = -INF;
    SEG.Build(1, 0, n);
    for (int i = 1; i <= n; ++i) {
        SEG.Update(1, 0, n, i - 1, pre[0][i] - pre[1][i - 1]);
        dp[i] = -INF;
        for (auto pr : spe[i]) {
            int l = pr.first, k = pr.second;
            Node u = SEG.Query(1, 0, n, l - 1, i);
            cmax(dp[i], u.lmx - k);
            cmax(ans, u.mx - k);
        }
        SEG.Update(1, 0, n, i, dp[i]);
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}