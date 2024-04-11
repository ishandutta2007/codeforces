#include <bits/stdc++.h>
 
const int N = 4e5 + 5, C = 26;
 
int n, st[N], ed[N];
int ft[N], dep[N], siz[N], hs[N], top[N], tms, dfn[N], id[N];
long long ans, f[N];
char str[N];
std::vector<int> e[N];
std::set<int> set[N];
bool used[N];
 
struct SuffixAutomaton {
    int tot, lst, len[N], son[N][C], fail[N], ord[N];
 
    SuffixAutomaton() {
        memset(son[0], -1, C * 4);
        len[0] = -1; tot = lst = 1;
    }
 
    void insert(int x) {
        int u = lst; lst = ++tot;
        len[lst] = len[u] + 1; siz[lst] = 1;
        for (; son[u][x] == 0; u = fail[u]) {
            son[u][x] = lst;
        }
        if (u == 0) { fail[lst] = 1; return; }
        int v = son[u][x];
        if (len[v] == len[u] + 1) { fail[lst] = v; return; }
        int w = ++tot;
        len[w] = len[u] + 1; fail[w] = fail[v];
        fail[v] = fail[lst] = w;
        memcpy(son[w], son[v], C * 4);
        for (; son[u][x] == v; u = fail[u]) {
            son[u][x] = w;
        }
    }
 
    void sort() {
        int buc[n + 1] = {};
        for (int u = 1; u <= tot; u++) {
            buc[len[u]]++;
        }
        for (int i = 1; i <= n; i++) {
            buc[i] += buc[i - 1];
        }
        for (int u = 1; u <= tot; u++) {
            ord[buc[len[u]]--] = u;
        }
    }
} sam, pam;
 
void dfs1(int u, int fa) {
    ft[u] = fa; dep[u] = dep[fa] + 1; siz[u] = 1;
    for (auto v : e[u]) {
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[hs[u]] < siz[v]) {
            hs[u] = v;
        }
    }
}
void dfs2(int u, int tp) {
    top[u] = tp; dfn[u] = ++tms; id[tms] = u;
    if (hs[u] > 0) { dfs2(hs[u], tp); }
    for (auto v : e[u]) {
        if (v == hs[u]) { continue; }
        dfs2(v, v);
    }
}
 
int findLca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            u = ft[top[u]];
        } else {
            v = ft[top[v]];
        }
    }
    return dep[u] < dep[v] ? u : v;
}
int distance(int u, int v) {
    return pam.len[u] + pam.len[v] - pam.len[findLca(u, v)] * 2;
}
 
int main() {
    scanf("%s", str + 1);
    n = strlen(str + 1);
    ed[0] = sam.lst;
    for (int i = 1; i <= n; i++) {
        sam.insert(str[i] - 'a');
        ed[i] = sam.lst;
    }
    st[n + 1] = pam.lst;
    for (int i = n; i >= 1; i--) {
        pam.insert(str[i] - 'a');
        st[i] = pam.lst;
    }
    sam.sort(); pam.sort();
    for (int u = 1; u <= sam.tot; u++) {
        ans += sam.len[u] - sam.len[sam.fail[u]];
    }
    for (int i = 2; i <= pam.tot; i++) {
        e[pam.fail[pam.ord[i]]].push_back(pam.ord[i]);
    }
    dfs1(1, 0); dfs2(1, 1);
    for (int i = 1; i <= n; i++) {
        set[ed[i - 1]].insert(dfn[st[i + 1]]);
        used[ed[i - 1]] = true;
    }
    for (int u = 1; u <= sam.tot; u++) {
        set[u].insert(1);
        f[u] = distance(id[*set[u].begin()], id[*set[u].rbegin()]);
        int lst = -1;
        for (auto x : set[u]) {
            if (lst == -1) { lst = x; continue; }
            f[u] += distance(id[lst], id[x]); lst = x;
        }
    }
    for (int i = sam.tot; i >= 1; i--) {
        int u = sam.ord[i], v = sam.fail[u];
        if (used[u]) { ans += 1ll * (f[u] / 2 + 1) * (sam.len[u] - sam.len[v]); }
        if (i == 1) { continue; }
        if (set[v].size() < set[u].size()) {
            set[v].swap(set[u]);
            std::swap(f[v], f[u]);
        }
        f[v] -= distance(id[*set[v].begin()], id[*set[v].rbegin()]);
        for (auto x : set[u]) {
            if (set[v].count(x)) { continue; }
            auto it = set[v].insert(x).first;
            if (it == set[v].begin()) {
                auto r = it; r++;
                f[v] += distance(id[*it], id[*r]);
            } else if (it == --set[v].end()) {
                auto l = it; l--;
                f[v] += distance(id[*l], id[*it]);
            } else {
                auto l = it, r = it; l--; r++;
                f[v] += distance(id[*it], id[*r]);
                f[v] += distance(id[*l], id[*it]);
                f[v] -= distance(id[*l], id[*r]);
            }           
        }
        f[v] += distance(id[*set[v].begin()], id[*set[v].rbegin()]);
        used[v] |= used[u];
    }
    printf("%lld\n", ans);
    return 0;
}