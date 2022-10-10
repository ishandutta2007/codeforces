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

struct LCA {
    int n;
    vector<int> in, out, depth, path, ret;
    vector<vector<int>> adj;
    RMQ<int> rmq;

    LCA(int _n) : n(_n), in(n, -1), out(n), depth(n), adj(n), rmq({}) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int r = -1) {
        if (r == -1) {
            for (int u=0; u<n; u++)
                if (in[u] == -1)
                    dfs(u, -1);
        } else {
            dfs(r, -1);
        }
        rmq = RMQ<int>(ret);
    }

    void dfs(int u, int p) {
        in[u] = (int) path.size();
        path.push_back(u);
        ret.push_back(in[u]);
        for (int v : adj[u])
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
                path.push_back(u);
                ret.push_back(in[u]);
            }
        out[u] = (int) path.size();
    }

    int lca(int u, int v) {
        if (in[u] > in[v])
            swap(u, v);
        return path[rmq.query(in[u], in[v])];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    bool anc(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector inp(n, vector(n, vector<bool>(n)));
        for (int i=1; i<n; i++)
            for (int j=1; j<=n-i; j++) {
                string s;
                cin >> s;
                for (int k=0; k<n; k++)
                    if (s[k] == '1')
                        inp[k][i-1][i+j-1] = inp[k][i+j-1][i-1] = true;
            }

        vector<pair<int, int>> cur;
        vector<bool> vis(n);

        auto dfs = [&] (auto &self, int u, int p) -> bool {
            vis[u] = true;
            for (int v=0; v<n; v++)
                if (v != u && v != p && inp[u][p][v]) {
                    if (vis[v] || !self(self, v, u))
                        return false;
                    cur.emplace_back(u, v);
                }
            return true;
        };

        auto check = [&] () -> bool {
            LCA lca(n);
            for (auto [u, v] : cur)
                lca.addEdge(u, v);
            lca.init(0);
            for (int z=0; z<n; z++)
                for (int x=0; x<n; x++)
                    for (int y=x+1; y<n; y++)
                        if ((lca.dist(x, z) == lca.dist(y, z)) != inp[z][x][y])
                            return false;
            return true;
        };

        bool yes = false;
        for (int u=0; u<n; u++)
            for (int v=u+1; v<n; v++) {
                cur.clear();
                fill(vis.begin(), vis.end(), false);
                vis[u] = true;
                bool ok = true;
                for (int w=0; w<n; w++)
                    if (w != u && (w == v || inp[u][v][w])) {
                        if (vis[w]) {
                            ok = false;
                            break;
                        }
                        cur.emplace_back(u, w);
                        ok &= dfs(dfs, w, u);
                        if (!ok)
                            break;
                    }
                if (ok && (int) cur.size() == n - 1 && check()) {
                    yes = true;
                    goto done;
                }
            }
        done:;

        if (yes) {
            cout << "Yes\n";
            for (auto [u, v] : cur)
                cout << u + 1 << " " << v + 1 << "\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}