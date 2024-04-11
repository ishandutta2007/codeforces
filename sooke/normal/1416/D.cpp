#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5, L = 20;

int n, m, q, a[N], opt[N], optx[N], eu[N], ev[N], del[N], ord[N];
int tot, anc[N], lgn, ft[L][N], tms, dfn[N], siz[N], val[N];
std::vector<int> e[N];

struct SegmentTree {
    int fi[N * 4];

    void pushUp(int u) {
        int ls = u << 1, rs = ls | 1;
        if (a[fi[ls]] > a[fi[rs]]) {
            fi[u] = fi[ls];
        } else {
            fi[u] = fi[rs];
        }
    }

    void modify(int u, int l, int r, int p, int x) {
        if (l + 1 >= r) { fi[u] = x; return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        if (p < mid) {
            modify(ls, l, mid, p, x);
        } else {
            modify(rs, mid, r, p, x);
        }
        pushUp(u);
    }
    void query(int u, int l, int r, int pl, int pr, int &res) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) {
            if (a[fi[u]] > a[res]) {
                res = fi[u];
            }
            return;
        }
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

bool compare(int i, int j) {
    return del[i] < del[j];
}

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

void dfs(int u, int fa) {
    ft[0][u] = fa;
    for (int i = 1; i <= lgn; i++) {
        ft[i][u] = ft[i - 1][ft[i - 1][u]];
    }
    dfn[u] = tms++; siz[u] = 1;
    for (auto v : e[u]) {
        dfs(v, u); siz[u] += siz[v];
    }
}

int main() {
    n = read(); m = read(); q = read();
    for (int u = 1; u <= n; u++) {
        a[u] = read();
    }
    for (int i = 1; i <= m; i++) {
        eu[i] = read(); ev[i] = read();
        del[i] = q; ord[i] = i;
    }
    for (int i = 0; i < q; i++) {
        opt[i] = read(); optx[i] = read();
        if (opt[i] == 2) { del[optx[i]] = i; }
    }
    std::sort(ord + 1, ord + m + 1, compare);
    for (int u = 1; u <= n * 2; u++) {
        anc[u] = u;
    }
    tot = n;
    for (int i = m; i >= 1; i--) {
        int u = eu[ord[i]], v = ev[ord[i]];
        u = find(u); v = find(v);
        if (u == v) { continue; }
        tot++; anc[u] = tot; anc[v] = tot; val[tot] = del[ord[i]];
        e[tot].push_back(u); e[tot].push_back(v);
    }
    lgn = std::log(tot) / std::log(2) + 1e-7;
    for (int u = tot; u >= 1; u--) {
        if (ft[0][u] != 0) { continue; }
        dfs(u, 0);
    }
    for (int u = 1; u <= n; u++) {
        smt.modify(1, 0, tms, dfn[u], u);
    }
    for (int i = 0; i < q; i++) {
        if (opt[i] == 2) { continue; }
        int u = optx[i];
        for (int j = lgn; j >= 0; j--) {
            if (val[ft[j][u]] > i) {
                u = ft[j][u];
            }
        }
        int v = 0;
        smt.query(1, 0, tms, dfn[u], dfn[u] + siz[u], v);
        if (a[v] == 0) { printf("0\n"); continue; }
        printf("%d\n", a[v]);
        a[v] = 0;
        smt.modify(1, 0, tms, dfn[v], 0);
    }
    return 0;
}