#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxN = 400005, maxC = 26;

int n, f[maxN], g[maxN];
char str[maxN];

struct SegmentTree {
    int tot, root[maxN], sl[maxN << 5], sr[maxN << 5];

    void modify(int &u, int l, int r, int pos) {
        if (!u) { u = ++tot; }
        if (l == r) { return; }
        int mid = l + r >> 1;
        if (pos <= mid) { modify(sl[u], l, mid, pos); }
        else { modify(sr[u], mid + 1, r, pos); }
    }
    bool query(int u, int l, int r, int pl, int pr) {
        if (!u || pl > pr) { return false; }
        if (l == pl && r == pr) { return true; }
        int mid = l + r >> 1;
        if (pr <= mid) { return query(sl[u], l, mid, pl, pr); }
        else if (pl > mid) { return query(sr[u], mid + 1, r, pl, pr); }
        else { return query(sl[u], l, mid, pl, mid) | query(sr[u], mid + 1, r, mid + 1, pr); }
    }
    int merge(int u, int v, int l, int r) {
        if (!u || !v) { return u | v; }
        int mid = l + r >> 1, w = ++tot;
        sl[w] = merge(sl[u], sl[v], l, mid);
        sr[w] = merge(sr[u], sr[v], mid + 1, r);
        return w;
    }
} tr;

struct SuffixAutomaton {
    int tot, lst, son[maxN][maxC], fail[maxN], len[maxN], end[maxN], buc[maxN], ord[maxN];

    SuffixAutomaton() { memset(son[0], -1, maxC << 2); tot = lst = 1; }
    void insert(int x) {
        int u = lst, v; len[lst = ++tot] = len[u] + 1; end[lst] = end[u] + 1;
        tr.modify(tr.root[lst], 1, n, end[lst]);
        for (; !son[u][x]; u = fail[u]) { son[u][x] = lst; }
        if (u) {
            v = son[u][x];
            if (len[u] + 1 == len[v]) { fail[lst] = v; } else {
                len[++tot] = len[u] + 1; fail[tot] = fail[v]; end[tot] = end[v];
                memcpy(son[tot], son[v], maxC << 2); fail[v] = fail[lst] = tot;
                for (; son[u][x] == v; u = fail[u]) { son[u][x] = tot; }
            }
        } else { fail[lst] = 1; }
    }
    void getRight() {
        for (int i = 1; i <= tot; i++) { buc[len[i]]++; }
        for (int i = 1; i <= n; i++) { buc[i] += buc[i - 1]; }
        for (int i = 1; i <= tot; i++) { ord[buc[len[i]]--] = i; }
        for (int i = tot; i; i--) { tr.root[fail[ord[i]]] = tr.merge(tr.root[fail[ord[i]]], tr.root[ord[i]], 1, n); }
    }
    void solve() {
        for (int i = 2, u, v; i <= tot; i++) {
            u = ord[i]; v = g[fail[u]];
            if (!v) { f[u] = 1; g[u] = u; }
            else if (tr.query(tr.root[v], 1, n, std::max(1, end[u] - len[u] + len[v]), end[u] - 1)) { f[u] = f[v] + 1; g[u] = u; }
            else { f[u] = f[v]; g[u] = g[v]; }
        }
    }
} sam;

int main() {
    scanf("%d%s", &n, str + 1);
    for (int i = 1; i <= n; i++) { sam.insert(str[i] - 'a'); }
    sam.getRight(); sam.solve(); printf("%d\n", *std::max_element(f, f + sam.tot + 1));
    return 0;
}