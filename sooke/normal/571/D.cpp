#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, q;
long long ans[N];
std::vector<int> tag[N];

struct Action {
    char opt;
    int u, v;
} a[N];

struct FenwickTree {
    long long f[N];

    void modify(int u, int x) {
        for (int i = u; i <= n * 2; i += i & -i) { f[i] += x; }
    }
    void modify(int l, int r, int x) {
        modify(l, x); modify(r, -x);
    }
    long long query(int u) {
        long long res = 0;
        for (int i = u; i >= 1; i ^= i & -i) { res += f[i]; }
        return res;
    }
} tr;

struct SegmentTree {
    int f[N * 4];

    void modify(int u, int l, int r, int pl, int pr, int x) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { f[u] = x; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        if (pr <= mid) {
            modify(ls, l, mid, pl, pr, x);
        } else if (pl >= mid) {
            modify(rs, mid, r, pl, pr, x);
        } else {
            modify(ls, l, mid, pl, mid, x);
            modify(rs, mid, r, mid, pr, x);
        }
    }
    int query(int u, int l, int r, int p) {
        if (l + 1 >= r) { return f[u]; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        if (p < mid) {
            return std::max(f[u], query(ls, l, mid, p));
        } else {
            return std::max(f[u], query(rs, mid, r, p));
        }
    }
} smt;

struct UnionSet {
    int tot, anc[N], ft[N], tms, dfn[N], siz[N], siz0[N];
    std::vector<int> e[N];

    void reset() {
        for (int u = 1; u <= n * 2; u++) { anc[u] = u; }
        tot = n;
    }
    int find(int u) {
        return anc[u] == u ? u : anc[u] = find(anc[u]);
    }
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) { return; } tot++;
        anc[u] = tot; ft[u] = tot; e[tot].push_back(u);
        anc[v] = tot; ft[v] = tot; e[tot].push_back(v);
    }

    void dfs(int u) {
        dfn[u] = ++tms; siz[u] = 1; siz0[u] = u <= n;
        for (auto v : e[u]) {
            dfs(v);
            siz[u] += siz[v]; siz0[u] += siz0[v];
        }
    }
    void build() {
        for (int u = tot; u >= 1; u--) {
            if (ft[u] == 0) { dfs(u); }
        }
    }
} s1, s2;

int main() {
    n = read(); q = read();
    s1.reset(); s2.reset();
    for (int i = 0; i < q; i++) {
        char opt[3];
        scanf("%s", opt);
        if (opt[0] == 'U') {
            int u = read(), v = read();
            s1.merge(u, v);
            a[i] = (Action) {'U', u, v};
        } else if (opt[0] == 'M') {
            int u = read(), v = read();
            s2.merge(u, v);
            a[i] = (Action) {'M', u, v};
        } else if (opt[0] == 'A') {
            int u = read();
            a[i] = (Action) {'A', u, 0};
        } else if (opt[0] == 'Z') {
            int u = read();
            a[i] = (Action) {'Z', u, 0};
        } else {
            int u = read();
            a[i] = (Action) {'Q', u, 0};
        }
    }
    s1.build(); s2.build();
    s1.reset(); s2.reset();
    for (int i = 0; i < q; i++) {
        if (a[i].opt == 'M') {
            int u = a[i].u, v = a[i].v;
            s2.merge(u, v);
        } else if (a[i].opt == 'Z') {
            int u = a[i].u; u = s2.find(u);
            smt.modify(1, 0, n * 2, s2.dfn[u] - 1, s2.dfn[u] - 1 + s2.siz[u], i + 1);
        } else if (a[i].opt == 'Q') {
            tag[smt.query(1, 0, n * 2, s2.dfn[a[i].u] - 1)].push_back(i);
        }
    }
    for (int i = 0; i < q; i++) {
        for (auto u : tag[i]) {
            ans[u] -= tr.query(s1.dfn[a[u].u]);
        }
        if (a[i].opt == 'U') {
            int u = a[i].u, v = a[i].v;
            s1.merge(u, v);
        } else if (a[i].opt == 'A') {
            int u = a[i].u; u = s1.find(u);
            tr.modify(s1.dfn[u], s1.dfn[u] + s1.siz[u], s1.siz0[u]);
        } else if (a[i].opt == 'Q') {
            ans[i] += tr.query(s1.dfn[a[i].u]);
        }
    }
    for (int i = 0; i < q; i++) {
        if (a[i].opt == 'Q') {
            printf("%lld\n", ans[i]);
        }
    }
    return 0;
}