// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int L = 2e5, n, q, ans[N];
 
vector<int> g[N];
vector<PII> e[N];

#define ls t[p].l
#define rs t[p].r

struct T{
    int l, r, t1, t2, r1, r2, l1, l2;
} t[N * 36];

int idx, rt[N];

void inline add1(int p, int k) {
    t[p].r1 += k;
    t[p].l1 += k;
    t[p].t1 += k;
}

void inline add2(int p, int k) {
    t[p].r2 += k;
    t[p].l2 += k;
    t[p].t2 += k;
}

void inline pushup(int p) {
    t[p].r1 = t[rs].r1;
    t[p].r2 = t[rs].r2;
    t[p].l1 = t[ls].l1;
    t[p].l2 = t[ls].l2;
}

void inline pushdown(int p) {
    if (t[p].t1) {
        if (!ls) ls = ++idx;
        add1(ls, t[p].t1);
        if (!rs) rs = ++idx;
        add1(rs, t[p].t1);
        t[p].t1 = 0;
    }
    if (t[p].t2) {
        if (!ls) ls = ++idx;
        add2(ls, t[p].t2);
        if (!rs) rs = ++idx;
        add2(rs, t[p].t2);
        t[p].t2 = 0;
    }
}

void merge(int &p, int q, int l, int r) {
    if (!p) { p = q; return ;}
    if (!q) return;
    t[p].t1 += t[q].t1, t[p].t2 += t[q].t2;
    t[p].l1 += t[q].l1, t[p].l2 += t[q].l2;
    t[p].r1 += t[q].r1, t[p].r2 += t[q].r2;
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge(ls, t[q].l, l, mid);
    merge(rs, t[q].r, mid + 1, r);
}

void upd(int &p, int l, int r) {
    if (!p) {
        p = ++idx;
        t[p].t1 = t[p].l1 = t[p].r1 = 1;
        return;
    }
    if (t[p].r1 - 1ll * t[p].r2 * r > 0) return;
    if (t[p].l1 - 1ll * t[p].l2 * l <= 1) {
        t[p].r2 = t[p].l2 = t[p].t2 = 0;
        t[p].l1 = t[p].r1 = t[p].t1 = 1;
        ls = rs = 0;
        return;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    upd(ls, l, mid);
    upd(rs, mid + 1, r);
}

int query(int p, int l, int r, int x) {
    if (!p) return 0;
    if (l == r) return t[p].l1 - t[p].l2 * l;
    int mid = (l + r) >> 1;
    pushdown(p);
    if (x <= mid) return query(ls, l, mid, x);
    return query(rs, mid + 1, r, x);
}

void dfs(int u, int fa) {
    for (int v: g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        merge(rt[u], rt[v], 0, L);
    }
    for (PII t: e[u]) {
        ans[t.se] = query(rt[u], 0, L, t.fi);
    }
    if (!rt[u]) rt[u] = ++idx;
    add2(rt[u], 1);
    upd(rt[u], 0, L);
}

signed main() {
    read(n);
    for (int i = 1, u, v; i < n; i++)
        read(u), read(v), g[u].pb(v), g[v].pb(u);
    read(q);
    for (int i = 1; i <= q; i++) {
        int v, k; read(v), read(k);
        e[v].pb(mp(k, i));
    }
    dfs(1, 0);
    for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
    return 0;
}