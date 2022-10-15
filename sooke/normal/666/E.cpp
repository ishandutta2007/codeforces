#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int inf = 1e9;
const int N = 12e5, L = 21, C = 26, V = 16e6;

int n, m, q, end[N];
char s[N], t[N];

struct SegmentTree {
    int tot, rt[N], f[V], g[V], ls[V], rs[V];
    
    SegmentTree() { f[0] = -inf; }

    inline void pushUp(int u) {
        if (f[ls[u]] > f[rs[u]]) {
            f[u] = f[ls[u]]; g[u] = g[ls[u]];
        } else if (f[ls[u]] < f[rs[u]]) {
            f[u] = f[rs[u]]; g[u] = g[rs[u]];
        } else {
            f[u] = f[ls[u]]; g[u] = std::min(g[ls[u]], g[rs[u]]);
        }
    }
    
    void modify(int &u, int l, int r, int p, int x) {
        if (u == 0) { u = ++tot; }
        if (l + 1 >= r) { f[u] += x; g[u] = l; return; }
        int mid = l + r >> 1;
        if (p < mid) {
            modify(ls[u], l, mid, p, x);
        } else {
            modify(rs[u], mid, r, p, x);
        }
        pushUp(u);
    }
    void query(int u, int l, int r, int pl, int pr, int &res, int &resi) {
        if (u == 0 || pl >= pr) { return; }
        if (l == pl && r == pr) {
            if (res < f[u]) {
                res = f[u]; resi = g[u];
            } else if (res == f[u]) {
                resi = std::min(resi, g[u]);
            }
            return;
        }
        int mid = l + r >> 1;
        if (pr <= mid) {
            query(ls[u], l, mid, pl, pr, res, resi);
        } else if (pl >= mid) {
            query(rs[u], mid, r, pl, pr, res, resi);
        } else {
            query(ls[u], l, mid, pl, mid, res, resi);
            query(rs[u], mid, r, mid, pr, res, resi);
        }
    }
    int merge(int u, int v, int l, int r) {
        if (u == 0 || v == 0) { return u | v; }
        int w = ++tot;
        if (l + 1 >= r) { f[w] = f[u] + f[v]; g[w] = l; return w; }
        int mid = l + r >> 1;
        ls[w] = merge(ls[u], ls[v], l, mid);
        rs[w] = merge(rs[u], rs[v], mid, r);
        pushUp(w);
        return w;
    }
} smt;

struct SuffixAutomaton {
    int tot, lst, son[N][C], len[N], fail[N], ord[N], ft[L][N];

    SuffixAutomaton() {
        memset(son[0], -1, C * 4);
        tot = lst = 1; len[0] = -1;
    }
    
    void insert(int x) {
        int u = lst, v, w;
        if (son[u][x] == 0) {
            lst = ++tot; len[lst] = len[u] + 1;
            for (; son[u][x] == 0; u = fail[u]) {
                son[u][x] = lst;
            }
            if (u == 0) { fail[lst] = 1; return; }
            v = son[u][x];
            if (len[v] == len[u] + 1) { fail[lst] = v; return; }
            fail[lst] = w = ++tot;
        } else {
            v = son[u][x];
            if (len[v] == len[u] + 1) { lst = v; return; }
            lst = w = ++tot;
        }
        len[w] = len[u] + 1;
        fail[w] = fail[v]; fail[v] = w;
        memcpy(son[w], son[v], C * 4);
        for (; son[u][x] == v; u = fail[u]) {
            son[u][x] = w;
        }
    }

    void sort() {
        int max = *std::max_element(len, len + tot + 1);
        int buc[max + 1] = {};
        for (int u = 1; u <= tot; u++) { buc[len[u]]++; }
        for (int i = 1; i <= max; i++) { buc[i] += buc[i - 1]; }
        for (int u = tot; u >= 1; u--) { ord[buc[len[u]]--] = u; }
    }
    void build() {
        memcpy(ft[0], fail, (tot + 1) * 4);
        for (int i = 1; i < L; i++) {
            for (int u = 1; u <= tot; u++) {
                ft[i][u] = ft[i - 1][ft[i - 1][u]];
            }
        }
    }
    int locate(int u, int x) {
        for (int i = L - 1; i >= 0; i--) {
            int v = ft[i][u];
            if (len[v] >= x) { u = v; }
        }
        return u;
    }
} sam;

int main() {
    scanf("%s", s); n = strlen(s);
    for (int i = 0; i < n; i++) {
        sam.insert(s[i] - 'a');
        end[i] = sam.lst;
    }
    m = read();
    for (int i = 0; i < m; i++) {
        scanf("%s", t); sam.lst = 1;
        for (int j = 0; t[j]; j++) {
            sam.insert(t[j] - 'a');
            smt.modify(smt.rt[sam.lst], 0, m, i, 1);
        }
    }
    sam.sort(); sam.build();
    for (int i = sam.tot; i >= 1; i--) {
        int u = sam.ord[i], fa = sam.fail[u];
        smt.rt[fa] = smt.merge(smt.rt[fa], smt.rt[u], 0, m);
    }
    q = read();
    for (int i = 0; i < q; i++) {
        int pl = read(), pr = read(), l = read(), r = read(); pl--;
        int u = sam.locate(end[r - 1], r - l + 1);
        int ansi = pl, ans = 0;
        smt.query(smt.rt[u], 0, m, pl, pr, ans, ansi);
        printf("%d %d\n", ansi + 1, ans);
    }
    return 0;
}