#include <bits/stdc++.h>

using namespace std;

struct RootedTree {
    using len_type = long long;
    using pr = pair<len_type, int>;
    static const int MAXD = 21; // for LCA; (1 << (MAXD - 1)) >= N
    vector<vector<pr> >e;
    vector<int> fa;
    vector<len_type> dis_to_root; // dis from root
    vector<int> dep; // Root has a dep of 1
    vector<vector<int> > anc; // anc[i][j] is the (2^j) ancestor of i
    vector<int> dfn, dfnL, dfnR;

    int N, Root;
    RootedTree() {}
    RootedTree(int _N, int _Root = 1) : N(_N), Root(_Root) {
        e.assign(N + 1, vector<pr>());
        fa.assign(N + 1, 0);
        dis_to_root.assign(N + 1, 0);
        dep.assign(N + 1, 0);
        dfn.assign(N + 1, 0); // If need multiple dfn, modify to 2 * N + 1?
        dfnL.assign(N + 1, 0);
        dfnR.assign(N + 1, 0);
    }
    void add_edge(int u, int v, len_type w = 1) {
        e[u].push_back(pr(w, v));
        e[v].push_back(pr(w, u));
    }
    void dfs(int x, int FA, bool calc_lca, int &time_tag) {
        dfn[++time_tag] = x;
        dfnL[x] = time_tag;
        fa[x] = FA;
        if (calc_lca) {
            anc[x][0] = FA;
            for (int i = 1; i < MAXD; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
        }
        for (auto &t : e[x]) {
            if (t.second == FA) continue;
            dep[t.second] = dep[x] + 1;
            dis_to_root[t.second] = dis_to_root[x] + t.first;
            dfs(t.second, x, calc_lca, time_tag);
        }
        dfnR[x] = time_tag;
    }
    void init(bool calc_lca = false) {
        dep[Root] = 1;
        dis_to_root[Root] = 0;
        if (calc_lca) anc.assign(N + 1, vector<int>(MAXD, 0));
        int time_tag = 0;
        dfs(Root, 0, calc_lca, time_tag);
    }
    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int delta = dep[u] - dep[v];
        for (int i = MAXD - 1; i >= 0; i--) {
            if (delta & (1 << i)) {
                u = anc[u][i];
            }
        }
        if (u == v) return u;
        for (int i = MAXD - 1; i >= 0; i--) {
            if (anc[u][i] != anc[v][i]) {
                u = anc[u][i];
                v = anc[v][i];
            }
        }
        return anc[u][0];
    }
    int unweighted_dis(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    len_type weighted_dis(int u, int v) {
        return dis_to_root[u] + dis_to_root[v] - 2 * dis_to_root[lca(u, v)];
    }
};

struct VirtualTree : RootedTree {
    int N;
    vector<int> id; // new_id --> original_id
    map<int, int> id_map; // original_id --> new_id
    VirtualTree() {}
    VirtualTree(vector<int> nodes, RootedTree &T) : RootedTree(nodes.size() * 2 - 1), N(nodes.size() * 2 - 1) {
        id.assign(N + 1, 0);
        int m = nodes.size();
        sort(nodes.begin(), nodes.end(), [&](const int &id1, const int &id2) {
            return T.dfnL[id1] < T.dfnL[id2];
        });
        vector<int> stk(1, 0);
        auto dis_function = [&](int u, int v) {
            return T.unweighted_dis(u, v);
        };
        auto VT_add_edge = [&](int u, int v) {
            if (u == 0 || v == 0) return;
            if (u == v) return;
            len_type w = dis_function(u, v);
            u = get_id(u);
            v = get_id(v);
            e[u].push_back(pr(w, v));
            e[v].push_back(pr(w, u));
        };
        for (int i = 0; i < m; i++) {
            int new_node = nodes[i];
            int LCA = T.lca(new_node, stk.back());
            if (LCA == stk.back()) {
                stk.push_back(new_node);
                continue;
            } else {
                while(stk.size() >= 2 && T.dep[stk[stk.size() - 2]] > T.dep[LCA]) {
                    int u = stk.back();
                    int v = stk[stk.size() - 2];
                    VT_add_edge(u, v);
                    stk.pop_back();
                }
                int u = stk.back();
                int v = stk[stk.size() - 2];
                VT_add_edge(LCA, u);
                stk.pop_back();
                if (LCA != v) {
                    stk.push_back(LCA);
                }
                stk.push_back(new_node);
            }
        }
        for (int i = 1; i + 1 < stk.size(); i++) {
            VT_add_edge(stk[i], stk[i + 1]);
        }
        N = id_map.size();
        Root = 1;
        for (int i = 2; i <= N; i++) {
            if (T.dep[id[i]] < T.dep[id[Root]]) {
                Root = i;
            }
        }
        init();
    }
    int get_id(int x) {
        if (id_map.find(x) == id_map.end()) {
            int tmp = id_map.size() + 1;
            id_map[x] = tmp;
            id[tmp] = x;
        }
        return id_map[x];
    }

    // problem-specified
    using pii = pair<int,int>;
    static const int INF = 1e9;
    pii dfs(int x, vector<int> &ori) {
        int ret = 0;
        int cnt = 0;
        for (auto &t : e[x]) {
            int to = t.second;
            if (dep[to] < dep[x]) continue;
            auto tmp = dfs(to, ori);
            ret += tmp.first;
            if (ori[id[x]]) {
                ret += tmp.second;
            } else {
                cnt += tmp.second;
            }   
        }
        if (cnt > 1) {
            return pii(ret + 1, 0);
        } else {
            return pii(ret, ori[id[x]] | cnt);
        }
    }
};


//test code for: http://codeforces.com/contest/613/problem/D

int main() {
    int n;
    scanf("%d",&n);
    RootedTree Tree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        Tree.add_edge(u, v);
    }
    Tree.init(true);
    int Q;
    vector<int> ori(n + 1, 0);
    scanf("%d",&Q);
    while(Q--) {
        int K;
        scanf("%d",&K);
        vector<int> nodes(K);
        for (int i = 0; i < K; i++) {
            scanf("%d",&nodes[i]);
            ori[nodes[i]] = 1;
        }
        bool ok = true;
        for (int i = 0; i < K; i++) {
            if (ori[Tree.fa[nodes[i]]]) ok = false;
        }
        if (ok) {
            VirtualTree V(nodes, Tree);
            auto ans = V.dfs(V.Root, ori);
            printf("%d\n",ans.first);
        } else {
            puts("-1");
        }
        for (int i = 0; i < K; i++) {
            ori[nodes[i]] = 0;
        }
    }
}