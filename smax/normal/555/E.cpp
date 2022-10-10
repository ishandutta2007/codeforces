#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct BridgeTree {
    int n, eid, ti;
    vector<int> num, id, stk;
    vector<vector<int>> tree, comp;
    vector<vector<pair<int, int>>> adj;

    BridgeTree(int _n) : n(_n), eid(0), ti(0), num(n), id(n), adj(n) {}

    void addEdge(int u, int v) {
        adj[u].emplace_back(v, eid);
        adj[v].emplace_back(u, eid);
        eid++;
    }

    void init() {
        for (int u=0; u<n; u++)
            if (!num[u]) {
                dfs(u, -1);
                comp.emplace_back();
                while (!stk.empty()) {
                    id[stk.back()] = (int) comp.size() - 1;
                    comp.back().push_back(stk.back());
                    stk.pop_back();
                }
            }
        tree.resize(comp.size());
        for (auto &c : comp)
            for (int u : c)
                for (auto [v, i] : adj[u])
                    if (id[u] != id[v])
                        tree[id[u]].push_back(id[v]);
    }

    int dfs(int u, int p) {
        int low = num[u] = ++ti;
        stk.push_back(u);
        for (auto [v, i] : adj[u])
            if (i != p) {
                if (!num[v]) {
                    int ret = dfs(v, i);
                    low = min(low, ret);
                    if (num[u] < ret) {
                        comp.emplace_back();
                        while (comp.back().empty() || comp.back().back() != v) {
                            id[stk.back()] = (int) comp.size() - 1;
                            comp.back().push_back(stk.back());
                            stk.pop_back();
                        }
                    }
                } else {
                    low = min(low, num[v]);
                }
            }
        return low;
    }
};

template<typename T>
struct RMQ {
    vector<vector<T>> spt;

    RMQ() {}

    RMQ(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = min(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return min(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

struct LCA {
    int n, cid;
    vector<int> pos, depth, comp, path, ret;
    vector<vector<int>> adj;
    RMQ<int> rmq;

    LCA(int _n) : n(_n), cid(0), pos(n), depth(n), comp(n), adj(n) {}

    LCA(const vector<vector<int>> &_adj) : n((int) _adj.size()), cid(0), pos(n), depth(n), comp(n), adj(_adj) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init() {
        for (int u=0; u<n; u++)
            if (!comp[u]) {
                cid++;
                dfs(u, -1);
            }
        rmq = RMQ<int>(ret);
    }

    void dfs(int u, int p) {
        pos[u] = (int) path.size();
        comp[u] = cid;
        path.push_back(u);
        ret.push_back(pos[u]);
        for (int v : adj[u])
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
                path.push_back(u);
                ret.push_back(pos[u]);
            }
    }

    int lca(int u, int v) {
        if (pos[u] > pos[v])
            swap(u, v);
        return path[rmq.query(pos[u], pos[v])];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    bool same(int u, int v) {
        return comp[u] == comp[v];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    BridgeTree bt(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        bt.addEdge(u, v);
    }

    bt.init();
    LCA lca(bt.tree);
    lca.init();
    int o = (int) bt.tree.size();
    vector<pair<int, int>> dir(o, {o, -1});
    for (int i=0; i<q; i++) {
        int s, d;
        cin >> s >> d;
        s--, d--;
        s = bt.id[s], d = bt.id[d];
        if (!lca.same(s, d)) {
            cout << "No\n";
            return 0;
        }
        int w = lca.lca(s, d);
        if (s != w) {
            if (dir[s].second != -1 && dir[s].second != 0) {
                cout << "No\n";
                return 0;
            }
            dir[s] = min(dir[s], {lca.depth[w], 0});
        }
        if (d != w) {
            if (dir[d].second != -1 && dir[d].second != 1) {
                cout << "No\n";
                return 0;
            }
            dir[d] = min(dir[d], {lca.depth[w], 1});
        }
    }

    vector<bool> vis(o);

    auto dfs = [&] (auto &self, int u, int p) -> void {
        vis[u] = true;
        for (int v : bt.tree[u])
            if (v != p) {
                self(self, v, u);
                if (dir[v].second != -1 && dir[v].first < lca.depth[u]) {
                    if (dir[u].second != -1 && dir[u].second != dir[v].second) {
                        cout << "No\n";
                        exit(0);
                    }
                    dir[u] = min(dir[u], dir[v]);
                }
            }
    };

    for (int u=0; u<o; u++)
        if (!vis[u])
            dfs(dfs, u, -1);
    cout << "Yes\n";

    return 0;
}