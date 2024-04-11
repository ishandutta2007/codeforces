#include <bits/stdc++.h>

#define ls(x) ((x) << 1)
#define rs(x) (ls(x) | 1)
#define mid ((l + r) >> 1)
#define lch ls(x), l, mid
#define rch rs(x), mid + 1, r

const int max_N = (int) 2e5 + 21;

int n, m, q, w[max_N], st[max_N], top, dfn[max_N], low[max_N], cnt, par[max_N], tot;

std::vector<int> vec[max_N], bcc[max_N];

std::multiset<int> set[max_N];

void tarjan(int u, int p) {
    st[++top] = u;
    dfn[u] = low[u] = ++cnt;
    for (auto v : vec[u]) {
        if (v == p) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = std::min(low[u], low[v]);
            if (dfn[u] <= low[v]) {
                ++tot;
                do {
                    bcc[tot].push_back(st[top]);
                    assert(!par[st[top]]);
                    par[st[top]] = tot;
                } while (st[top--] != v);
                bcc[u].push_back(tot);
                par[tot] = u;
            }
        } else if (dfn[v] < dfn[u]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
}

int sz[max_N], mx[max_N], vp[max_N], head[max_N], dep[max_N];

void dfs1(int u) {
    sz[u] = 1, mx[u] = 0;
    for (auto v : bcc[u]) {
        dep[v] = dep[u] + 1;
        dfs1(v);
        sz[u] += sz[v];
        if (sz[v] > sz[mx[u]]) {
            mx[u] = v;
        }
    }
}

void dfs2(int u, int c) {
    vp[dfn[u] = ++cnt] = u;
    head[u] = c;
    if (mx[u]) dfs2(mx[u], c);
    for (auto v : bcc[u]) {
        if (dfn[v]) continue;
        dfs2(v, v);
    }
}

int seg[max_N << 2], pos[max_N], ql, qr, qa;

inline void updt(int u) {
    seg[u] = std::min(seg[ls(u)], seg[rs(u)]);
}

void build(int x, int l, int r) {
    if (l == r) {
        seg[x] = *set[vp[l]].begin();
        pos[l] = x;
    } else {
        build(lch), build(rch);
        updt(x);
    }
}

void query(int x, int l, int r) {
    if (ql <= l && r <= qr) {
        qa = std::min(qa, seg[x]);
    } else {
        if (ql <= mid) query(lch);
        if (qr > mid)  query(rch);
    }
}

inline void query(int u, int v) {
    qa = INT_MAX;
    while (head[u] != head[v]) {
        if (dep[head[u]] > dep[head[v]]) {
            std::swap(u, v);
        }
        ql = dfn[head[v]], qr = dfn[v];
        query(1, 1, tot);
        v = par[head[v]];
    }
    if (dep[u] > dep[v]) std::swap(u, v);
    ql = dfn[u], qr = dfn[v];
    query(1, 1, tot);
    if (u > n) {
        qa = std::min(qa, *set[par[u]].begin());
    }
    printf("%d\n", qa);
}

inline void change(int u, int a, int b) {
    int tmp = *set[u].begin();
    set[u].erase(set[u].find(a));
    set[u].insert(b);
    if (tmp != *set[u].begin()) {
        int x = pos[dfn[u]];
        seg[x] = *set[u].begin();
        for (; x > 1; x >>= 1) updt(x >> 1);
    }
}

inline void modify(int u, int a) {
    if (w[u] == a) return;
    change(u, w[u], a);
    if (par[u]) {
        change(par[u], w[u], a);
    }
    w[u] = a;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",  w + i);
        set[i].insert(w[i]);
    }
    for (int i = 1, u, v; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    tot = n;
    tarjan(1, 0);
    /*for (int u = 1; u <= tot; ++u)
        for (auto v : bcc[u]) {
            printf("(%d, %d)\n", u, v);
        }*/
    for (int i = 2; i <= n; ++i) {
        set[par[i]].insert(w[i]);
    }
    /*for (int i = 1; i <= tot; ++i) {
        printf("min[%d] = %d\n", i, *set[i].begin());
    }*/
    dfs1(1);
    memset(dfn + 1, 0, tot * sizeof(int));
    cnt = 0;
    dfs2(1, 1);
    build(1, 1, tot);
    while (q--) {
        char opt[5];
        int u, v;
        scanf("%s%d%d", opt, &u, &v);
        if (*opt == 'A') {
            query(u, v);
        } else {
            modify(u, v);
        }
    }
    return 0;
}