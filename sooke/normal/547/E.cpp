#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5, C = 26, V = 15e6;

int n, q, tms, dfn[N], siz[N];
char str[N];
std::vector<int> e[N], pos[N];

struct AcAutomaton {
    int tot, son[N][C], fail[N];

    AcAutomaton() { tot = 1; memset(son[0], -1, C * 4); }

    void insert(char str[], std::vector<int> &pos) {
        int u = 1;
        for (int i = 0; str[i] > 0; i++) {
            int x = str[i] - 'a';
            if (son[u][x] == 0) { son[u][x] = ++tot; }
            u = son[u][x]; pos.push_back(u);
        }
    }

    void build() {
        std::queue<int> que;
        for (int x = 0; x < C; x++) {
            if (son[1][x] == 0) { continue; }
            fail[son[1][x]] = 1;
            que.push(son[1][x]);
        }
        for (; !que.empty(); que.pop()) {
            int u = que.front(), v;
            e[fail[u]].push_back(u);
            for (int x = 0; x < C; x++) {
                if (son[u][x] == 0) { continue; }
                for (v = fail[u]; son[v][x] == 0; v = fail[v]);
                fail[son[u][x]] = v ? son[v][x] : 1;
                que.push(son[u][x]);
            }
        }
     }
} aam;

struct SegmentTree {
    int tot, rt[N], ls[V], rs[V], f[V];

    void modify(int &u, int l, int r, int p) {
        f[++tot] = f[u]; ls[tot] = ls[u]; rs[tot] = rs[u]; u = tot;
        if (l + 1 >= r) { f[u]++; return; }
        int mid = l + r >> 1;
        if (p < mid) {
            modify(ls[u], l, mid, p);
        } else {
            modify(rs[u], mid, r, p);
        }
        f[u] = f[ls[u]] + f[rs[u]];
    }
    void query(int u, int l, int r, int pl, int pr, int &res) {
        if (pl >= pr || u == 0) { return; }
        if (l == pl && r == pr) { res += f[u]; return; }
        int mid = l + r >> 1;
        if (pr <= mid) {
            query(ls[u], l, mid, pl, pr, res);
        } else if (pl >= mid) {
            query(rs[u], mid, r, pl, pr, res);
        } else {
            query(ls[u], l, mid, pl, mid, res);
            query(rs[u], mid, r, mid, pr, res);
        }
    }
} smt;

void dfs(int u) {
    siz[u] = 1; dfn[u] = tms++;
    for (auto v : e[u]) {
        dfs(v);
        siz[u] += siz[v];
    }
}

int main() {
    n = read(); q = read();
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        aam.insert(str, pos[i]);
    }
    aam.build(); dfs(1);
    for (int i = n - 1; i >= 0; i--) {
        smt.rt[i] = smt.rt[i + 1];
        for (auto u : pos[i]) {
            smt.modify(smt.rt[i], 0, tms, dfn[u]);
        }
    }
    for (; q; q--) {
        int l = read(), r = read(), i = read(); l--; i--;
        int u = pos[i].back(), ans1 = 0, ans2 = 0;
        smt.query(smt.rt[l], 0, tms, dfn[u], dfn[u] + siz[u], ans1);
        smt.query(smt.rt[r], 0, tms, dfn[u], dfn[u] + siz[u], ans2);
        printf("%d\n", ans1 - ans2);
    }
    return 0;
}