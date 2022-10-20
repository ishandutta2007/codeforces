#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define lc (rt << 1)
#define rc (rt << 1) | 1
using namespace std;
typedef long long LL;
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

int n, m, q;

struct UFS {
    int fa[MAXN], fe[MAXN], siz[MAXN], dep[MAXN];

    inline void init() {
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            fe[i] = 0;
            siz[i] = 1;
            dep[i] = -1;
        }
    }

    inline int getf(int x) {
        while (fa[x] != x) {
            x = fa[x];
        }
        return x;
    }

    inline int getd(int x) {
        if (dep[x] != -1) return dep[x];
        if (fa[x] == x) return dep[x] = 1;
        return dep[x] = getd(fa[x]) + 1;
    }

    inline void AddEdge(int u, int v, int w) {
        u = getf(u), v = getf(v);
        if (u == v) return;
        if (siz[u] > siz[v]) {
            swap(u, v);
        }
        fa[u] = v;
        fe[u] = w;
        siz[v] += siz[u];
    }

    int Query(int u, int v) {
        int ret = 0;
        while (u ^ v) {
            if (dep[u] < dep[v]) {
                swap(u, v);
            }
            ret = max(ret, fe[u]);
            u = fa[u];
        }
        return ret;
    }
} ufs;

struct SegmentTree {
    int mx[MAXN << 2];

    void Build(int rt, int b, int e) {
        if (b == e) {
            mx[rt] = ufs.Query(b, b + 1);
            return;
        }
        int mid = (b + e) >> 1;
        Build(lc, b, mid);
        Build(rc, mid + 1, e);
        mx[rt] = max(mx[lc], mx[rc]);
    }

    int Query(int rt, int b, int e, int l, int r) {
        if (l <= b && e <= r) return mx[rt];
        int mid = (b + e) >> 1;
        if (r <= mid) return Query(lc, b, mid, l, r);
        if (l > mid) return Query(rc, mid + 1, e, l, r);
        return max(Query(lc, b, mid, l, r), Query(rc, mid + 1, e, l, r));
    }
} seg;

void solve() {
    read(n); read(m); read(q);
    ufs.init();
    for (int i = 1, u, v; i <= m; ++i) {
        read(u); read(v);
        ufs.AddEdge(u, v, i);
    }
    for (int i = 1; i <= n; ++i) {
        ufs.getd(i);
    }
    seg.Build(1, 1, n - 1);
    while (q--) {
        int l, r;
        read(l); read(r);
        if (l == r) {
            printf("0 ");
        } else {
            printf("%d ", seg.Query(1, 1, n - 1, l, r - 1));
        }
    }
    printf("\n");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}