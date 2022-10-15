#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 400005, C = 27, L = 19, S = 1005;

int n, m, m1, m2, lgt, sqt, tms, sl[N], sr[N], bl[N], br[N], bel[N], siz[N], pos[N], dfn[N];
int f[N], g[S], fa[L][N];
long long now, ans[N];
char str[N];

struct Query { int u, v, i; } q1[N], q2[N];

bool cmp1(Query a, Query b) { return a.v < b.v; }
bool cmp2(Query a, Query b) { return a.u == b.u ? a.v < b.v : a.u < b.u; }

struct List {
    int tot, fst[N], nxt[N], to[N];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v) { nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++; }
} e;

struct SuffixAutomaton {
    int tot, lst, dat[N], len[N], end[N], fail[N], son[N][C];

    SuffixAutomaton() { memset(son[0], -1, C << 2); tot = lst = 1; }
    void insert(int x) {
        int u = lst, v; len[lst = ++tot] = len[u] + 1;
        dat[len[lst]] = x; end[len[lst]] = lst;
        for (; !son[u][x]; u = fail[u]) { son[u][x] = lst; }
        if (u) {
            v = son[u][x];
            if (len[u] + 1 == len[v]) { fail[lst] = v; } else {
                len[++tot] = len[u] + 1; fail[tot] = fail[v];
                memcpy(son[tot], son[v], C << 2); fail[v] = fail[lst] = tot;
                for (; son[u][x] == v; u = fail[u]) { son[u][x] = tot; }
            }
        } else { fail[lst] = 1; }
    }
    void build() { for (int i = 2; i <= tot; i++) { e.insert(fail[i], i); } }
} sam;

int dfs1(int u) {
    fa[0][u] = sam.fail[u]; dfn[u] = ++tms; siz[u] = 1;
    for (int i = 1; i <= lgt; i++) { fa[i][u] = fa[i - 1][fa[i - 1][u]]; }
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) { siz[u] += dfs1(e.to[i]); }
    return siz[u];
}
int dfs2(int u) {
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) { siz[u] += dfs2(e.to[i]); }
    return siz[u];
}

int findPos(int l, int r) {
    int u = sam.end[r], len = r - l + 1;
    for (int i = lgt; ~i; i--) { if (len <= sam.len[fa[i][u]]) { u = fa[i][u]; } }
    return u;
}

void modify(int l) {
    int r = dfn[l] + siz[l] - 1; l = dfn[l];
    if (bel[l] + 1 >= bel[r]) {
        for (int i = l; i <= r; i++) { f[i]++; }
        return;
    }
    for (int i = l; i <= br[bel[l]]; i++) { f[i]++; }
    for (int i = r; i >= bl[bel[r]]; i--) { f[i]++; }
    for (int i = bel[l] + 1; i < bel[r]; i++) { g[i]++; }
}
inline int query(int u) { u = dfn[u]; return f[u] + g[bel[u]]; }

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str); sl[i] = sr[i - 1] + 1; sr[i] = sl[i] + strlen(str);
        for (int j = 0; str[j]; j++) { sam.insert(str[j] - 'a'); } sam.insert(26);
    }
    lgt = std::log(sam.tot) / std::log(2); sqt = std::sqrt(sam.tot); sam.build(); dfs1(1);
    for (int i = 1; i <= n; i++) { pos[i] = findPos(sl[i], sr[i] - 1); }
    for (int i = 1; i <= sam.tot; i++) {
        bel[i] = (i - 1) / sqt + 1; br[bel[i]] = i;
        if (!bl[bel[i]]) { bl[bel[i]] = i; }
    }
    for (int i = 1, l, r, u; i <= m; i++) {
        scanf("%d%d%d", &l, &r, &u);
        if (sr[u] - sl[u] <= sqt) {
            q1[++m1] = (Query) {u, r, i};
            if (l > 1) { q1[++m1] = (Query) {u, l - 1, -i}; }
        } else {
            q2[++m2] = (Query) {u, r, i};
            if (l > 1) { q2[++m2] = (Query) {u, l - 1, -i}; }
        }
    }
    std::sort(q1 + 1, q1 + m1 + 1, cmp1); std::sort(q2 + 1, q2 + m2 + 1, cmp2);
    for (int i = 1, u, v; i <= m1; i++) {
        u = q1[i].u; v = q1[i].v; now = 0;
        for (int j = q1[i - 1].v + 1; j <= v; j++) { modify(pos[j]); }
        for (int j = sl[u], w = 1; j < sr[u]; j++) { w = sam.son[w][sam.dat[j]]; now += query(w); }
        if (q1[i].i > 0) { ans[q1[i].i] += now; } else { ans[-q1[i].i] -= now; }
    }
    for (int i = 1, u, v; i <= m2; i++) {
        u = q2[i].u; v = q2[i].v;
        if (q2[i - 1].u != u) {
            memset(siz, 0, sizeof(int) * (sam.tot + 1)); now = q2[i - 1].v = 0;
            for (int j = sl[u]; j < sr[u]; j++) { siz[sam.end[j]]++; } dfs2(1);
        }
        for (int j = q2[i - 1].v + 1; j <= v; j++) { now += siz[pos[j]]; }
        if (q2[i].i > 0) { ans[q2[i].i] += now; } else { ans[-q2[i].i] -= now; }
    }
    for (int i = 1; i <= m; i++) { printf("%I64d\n", ans[i]); }
    return 0;
}