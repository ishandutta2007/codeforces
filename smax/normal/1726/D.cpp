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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n), extra(n);
        DSU dsu(n);
        SecondOnPath sec(n);
        int cnt = 0;
        vector<int> vv;
        vector<pair<int, int>> edges;
        for (int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (dsu.unite(u, v)) {
                adj[u].emplace_back(v, i);
                adj[v].emplace_back(u, i);
                sec.addEdge(u, v);
            } else {
                extra[u].emplace_back(v, cnt);
                extra[v].emplace_back(u, cnt);
                cnt++;
                vv.push_back(i);
            }
            edges.emplace_back(u, v);
        }

        int mn = INT_MAX;
        string ret;
        sec.init(0);
        for (int mask=0; mask<1<<cnt; mask++) {
            string s(m, '?');
            // int coverRed = 0, coverBlue = 0, comps = 2;
            for (int i=0; i<cnt; i++)
                s[vv[i]] = mask >> i & 1 ? '1' : '0';

            // auto dfs = [&] (auto &self, int u, int p) -> void {
            //     for (auto [v, i] : adj[u])
            //         if (v != p) {
            //             for (auto [x, y] : extra[u])
            //                 if (v == sec.query(u, x))
            //                     (mask >> y & 1 ? coverRed : coverBlue)++;
            //             DEBUG(u, v, coverRed, coverBlue);
            //             if (coverRed)
            //                 s[i] = '0';
            //             else if (coverBlue)
            //                 s[i] = '1';
            //             else
            //                 comps++;
            //             self(self, v, u);
            //             for (auto [x, y] : extra[u])
            //                 if (v == sec.query(u, x))
            //                     (mask >> y & 1 ? coverRed : coverBlue)--;
            //         }
            // };

            // dfs(dfs, 0, -1);
            // if (comps < mn) {
            //     mn = comps;
            //     ret = s;
            // }

            int comps = 2 * n;
            DSU red(n), blue(n);
            for (int i : vv) {
                if (s[i] == '0') {
                    if (blue.unite(edges[i].first, edges[i].second))
                        comps--;
                } else {
                    if (red.unite(edges[i].first, edges[i].second))
                        comps--;
                }
            }
            for (int i=0; i<m; i++)
                if (s[i] == '?') {
                    if (blue.same(edges[i].first, edges[i].second)) {
                        s[i] = '1';
                        if (red.unite(edges[i].first, edges[i].second))
                            comps--;
                    } else if (red.same(edges[i].first, edges[i].second)) {
                        s[i] = '0';
                        if (blue.unite(edges[i].first, edges[i].second))
                            comps--;
                    } else {
                        s[i] = '0';
                        if (blue.unite(edges[i].first, edges[i].second))
                            comps--;
                    }
                }
            if (comps < mn) {
                mn = comps;
                ret = s;
            }
        }
        DEBUG(mn, vv);
        cout << ret << "\n";
    }

    return 0;
}