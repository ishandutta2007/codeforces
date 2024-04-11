#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 400005;

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

int n, m, ans[MAXN];
vector<int> sub[MAXN], blk[MAXN];
set<int> G[MAXN];

struct UnionFindSet {
    int ufs[MAXN];
    int getf(int x) {
        return (ufs[x] == x)? x : ufs[x] = getf(ufs[x]);
    }
} S1, S2, S3;

struct RebuildTree {
    int tot, val[MAXN], tree[MAXN][2];
    int fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], top[MAXN];

    void AddEdge(int u, int v, int w) {
        u = S3.getf(u), v = S3.getf(v);
        val[++tot] = w;
        tree[tot][0] = u;
        tree[tot][1] = v;
        fa[u] = fa[v] = tot;
        S3.ufs[tot] = S3.ufs[u] = S3.ufs[v] = tot;
    }

    void DFS1(int u) {
        siz[u] = 1;
        if (!tree[u][0]) return;
        for (int i = 0; i < 2; ++i) {
            int v = tree[u][i];
            dep[v] = dep[u] + 1;
            DFS1(v);
            if (siz[v] > siz[son[u]]) son[u] = v;
            siz[u] += siz[v];
        }
    }

    void DFS2(int u, int topf) {
        top[u] = topf;
        if (!son[u]) return;
        DFS2(son[u], topf);
        int v = tree[u][tree[u][0] == son[u]];
        DFS2(v, v);
    }

    int LCA(int u, int v) {
        while (top[u] ^ top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            u = fa[top[u]];
        }
        return (dep[u] < dep[v]? u : v);
    }

    void Clean() {
        for (int i = 1; i <= tot; ++i) {
            val[i] = tree[i][0] = tree[i][1] = 0;
            fa[i] = dep[i] = siz[i] = son[i] = top[i] = 0;
        }
        tot = 0;
    }

    void Build() {
        DFS1(tot);
        DFS2(tot, tot);
    }

    int Query(int u, int v) {
        return val[LCA(u, v)];
    }
} T;

int MergeVec(int u, int v) {
    if (blk[u].size() < blk[v].size()) {
        swap(u, v);
    }
    blk[u].insert(blk[u].end(), blk[v].begin(), blk[v].end());
    S2.ufs[v] = u;
    return u;
}

void Merge(int U, int V, int W) {
    static int lnk[MAXN];
    if (sub[U].size() > sub[V].size()) {
        swap(U, V);
    }
    vector<int> tmp1, tmp2;
    for (auto u : sub[U]) {
        tmp1.clear();
        tmp2.clear();
        for (auto v : sub[V]) {
            bool ok = 0;
            for (auto x : blk[u]) {
                for (auto y : blk[v]) {
                    if (G[x].count(y)) continue;
                    ok = 1; break;
                }
                if (ok) break;
            }
            if (ok) {
                tmp1.push_back(v);
                T.AddEdge(u, v, W);
            } else {
                tmp2.push_back(v);
            }
        }
        swap(sub[V], tmp2);
        if (!tmp1.size()) {
            lnk[u] = 0;
        } else {
            int cur = tmp1[0];
            for (int i = 1; i < tmp1.size(); ++i) {
                cur = MergeVec(cur, tmp1[i]);
            }
            lnk[u] = cur;
            sub[V].push_back(cur);
        }
    }
    for (auto u : sub[U]) {
        if (lnk[u]) {
            MergeVec(u, S2.getf(lnk[u]));
        }
    }
    tmp1.clear();
    for (auto u : sub[U]) {
        if (S2.getf(u) == u) {
            tmp1.push_back(u);
        }
    }
    for (auto v : sub[V]) {
        if (S2.getf(v) == v) {
            tmp1.push_back(v);
        }
    }
    sub[V] = tmp1;
    S1.ufs[U] = V;
}

struct Edge {
    int u, v, w, id;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
} e[MAXN];

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
        sub[i].clear();
        blk[i].clear();
    }
    T.Clean();
    for (int i = 1; i <= m; ++i) {
        read(e[i].u); read(e[i].v); read(e[i].w);
        e[i].id = i;
        G[e[i].u].insert(e[i].v);
        G[e[i].v].insert(e[i].u);
    }

    sort(e + 1, e + m + 1);
    for (int i = 1; i <= n; ++i) {
        S1.ufs[i] = S2.ufs[i] = S3.ufs[i] = i;
        sub[i].push_back(i);
        blk[i].push_back(i);
    }
    T.tot = n;
    for (int i = 1; i <= m; ++i) {
        int u = S1.getf(e[i].u), v = S1.getf(e[i].v);
        if (u == v) continue;
        Merge(u, v, e[i].w);
    }
    T.Build();

    for (int i = 1; i <= m; ++i) {
        ans[e[i].id] = T.Query(e[i].u, e[i].v);
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d ", ans[i]);
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