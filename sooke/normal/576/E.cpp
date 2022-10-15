#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5, V = N * 2, K = 51;

int n, m, k, q, lst[N], p[N], c[N], t[N], cnt[K][K];

struct Edge {
    int u, v, c;
} edg[N];

struct UnionSet {
    int anc[N], siz[N];
    std::stack<int> stu, stv;

    void reset(int n) {
        for (int u = 1; u <= n; u++) {
            anc[u] = u; siz[u] = 1;
        }
    }
    int find(int u) {
        return anc[u] == u ? u : find(anc[u]);
    }
    bool query(int u, int v) {
        return find(u) == find(v);
    }
    bool merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) { return false; }
        if (siz[u] > siz[v]) { std::swap(u, v); }
        stu.push(u); stv.push(v);
        anc[u] = v; siz[v] += siz[u];
        return true;
    }
    void undo() {
        int u = stu.top(), v = stv.top();
        stu.pop(); stv.pop();
        anc[u] = u; siz[v] -= siz[u];
    }
} dsu[K];

struct SegmentTree {
    std::vector<Edge> e[V];

    void insert(int u, int l, int r, int pl, int pr, Edge i) {
        if (pl >= pr) { return; }
        if (l == pl && r == pr) { e[u].push_back(i); return; }
        int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
        if (pr <= mid) {
            insert(ls, l, mid, pl, pr, i);
        } else if (pl >= mid) {
            insert(rs, mid, r, pl, pr, i);
        } else {
            insert(ls, l, mid, pl, mid, i);
            insert(rs, mid, r, mid, pr, i);
        }
    }
    void query(int u, int l, int r, int d) {
        for (auto i : e[u]) {
            if (dsu[i.c].merge(i.u, n + i.v)) { cnt[d][i.c]++; }
            if (dsu[i.c].merge(i.v, n + i.u)) { cnt[d][i.c]++; }
        }
        if (l + 1 >= r) {
            Edge i = edg[p[l]];
            if (dsu[c[l]].merge(i.u, n + i.v)) { cnt[50][c[l]]++; }
            if (dsu[c[l]].merge(i.v, n + i.u)) { cnt[50][c[l]]++; }
            if (dsu[c[l]].query(i.u, n + i.u) || dsu[c[l]].query(i.v, n + i.v)) {
                printf("NO\n");
            } else {
                edg[p[l]].c = c[l];
                printf("YES\n");
            }
            insert(1, 0, q, l + 1, t[l], edg[p[l]]);
            for (; cnt[50][c[l]] > 0; cnt[50][c[l]]--) { dsu[c[l]].undo(); }
        } else {
            int mid = l + r >> 1, ls = u << 1, rs = ls | 1;
            query(ls, l, mid, d + 1);
            query(rs, mid, r, d + 1);
        }
        for (auto i : e[u]) {
            for (; cnt[d][i.c] > 0; cnt[d][i.c]--) { dsu[i.c].undo(); }
        }
    }
} smt;

int main() {
    n = read(); m = read(); k = read(); q = read();
    for (int i = 0; i < m; i++) {
        edg[i].u = read(); edg[i].v = read();
        edg[i].c = -1; lst[i] = q;
    }
    for (int i = 0; i < k; i++) { dsu[i].reset(n * 2); }
    for (int i = 0; i < q; i++) {
        p[i] = read(); c[i] = read(); p[i]--; c[i]--;
    }
    for (int i = q - 1; i >= 0; i--) {
        t[i] = lst[p[i]]; lst[p[i]] = i;
    }
    smt.query(1, 0, q, 0);
    return 0;
}