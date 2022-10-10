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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

template<typename T>
struct RMQ {
    vector<vector<T>> spt;

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

struct SecondOnPath {
    int n;
    vector<int> par, in, out, depth;
    vector<array<int, 3>> ret;
    vector<vector<int>> adj;
    RMQ<array<int, 3>> rmq;

    SecondOnPath(int _n) : n(_n), par(n, -1), in(n), out(n), depth(n), adj(n), rmq({}) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int r = -1) {
        if (r == -1) {
            for (int u=0; u<n; u++)
                if (par[u] == -1)
                    dfs(u);
        } else {
            dfs(r);
        }
        rmq = RMQ<array<int, 3>>(ret);
    }

    void dfs(int u) {
        in[u] = (int) ret.size();
        ret.push_back({depth[u], -in[u], u});
        for (int v : adj[u])
            if (v != par[u]) {
                par[v] = u;
                depth[v] = depth[u] + 1;
                dfs(v);
            }
        out[u] = (int) ret.size();
    }

    bool anc(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }

    int query(int u, int v) {
        assert(u != v);
        if (anc(u, v))
            return rmq.query(in[u] + 1, in[v])[2];
        else
            return par[u];
    }
};

struct DSU {
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<bool> tree(m);
    DSU dsu(n);
    SecondOnPath sec(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        if (dsu.unite(u, v)) {
            tree[i] = true;
            sec.addEdge(u, v);
        }
    }

    int bad = 0;
    vector<bool> vis(n), up(m);
    string ret(n, '0');
    sec.init(0);

    auto dfs1 = [&] (auto &self, int u, int p) -> void {
        vis[u] = true;
        for (auto [v, i] : adj[u])
            if (i != p) {
                if (tree[i])
                    self(self, v, i);
                else if (vis[v])
                    up[i] = true;
            }
        for (auto [v, i] : adj[u])
            if (!tree[i] && !up[i])
                bad++;
        vis[u] = false;
    };

    auto dfs2 = [&] (auto &self, int u, int p) -> void {
        DEBUG(u, p, bad, tree, up);
        if (bad == 0)
            ret[u] = '1';
        map<int, vector<int>> mp;
        for (auto [v, i] : adj[u])
            if (tree[i])
                mp[v];
        for (auto [v, i] : adj[u])
            if (!tree[i] && !mp.count(v)) {
                assert(up[i]);
                mp[sec.query(u, v)].push_back(i);
            }
        for (auto [v, i] : adj[u])
            if (i != p && tree[i]) {
                bad += mp[v].size() * 2;
                for (int j : mp[v])
                    up[j] = false;
                vector<int> bruh;
                for (auto [w, j] : adj[v])
                    if (!tree[j] && !up[j]) {
                        bad -= 2;
                        bruh.push_back(j);
                        up[j] = true;
                    }
                self(self, v, i);
                for (int j : bruh) {
                    bad += 2;
                    up[j] = false;
                }
                bad -= mp[v].size() * 2;
                for (int j : mp[v])
                    up[j] = true;
            }
    };

    dfs1(dfs1, 0, -1);
    dfs2(dfs2, 0, -1);
    cout << ret << "\n";

    return 0;
}