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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct BinaryLift {
    int n, lg;
    vector<int> depth;
    vector<vector<int>> adj, up;

    BinaryLift(int _n) : n(_n), lg(__lg(n - 1) + 1), depth(n), adj(n), up(n, vector<int>(lg, -1)) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int r = 0) {
        dfs(r);
        for (int j=1; j<lg; j++)
            for (int i=0; i<n; i++)
                if (up[i][j-1] != -1)
                    up[i][j] = up[up[i][j-1]][j-1];
    }

    void dfs(int u) {
        for (int v : adj[u])
            if (v != up[u][0]) {
                depth[v] = depth[u] + 1;
                up[v][0] = u;
                dfs(v);
            }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);
        for (int j=lg-1; j>=0; j--)
            if (depth[u] - (1 << j) >= depth[v])
                u = up[u][j];
        if (u == v)
            return u;
        for (int j=lg-1; j>=0; j--)
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        return up[u][0];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    int kthAnc(int u, int k) {
        if (k > depth[u])
            return -1;
        for (int j=0; j<lg; j++)
            if (k & (1 << j))
                u = up[u][j];
        return u;
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
        BinaryLift bl(n);
        for (int i=0; i<n-1; i++) {
            int u, v;
            cin >> u >> v;
            bl.addEdge(u, v);
        }

        vector<int> sz(n);

        auto dfs = [&] (auto &self, int u, int p) -> int {
            sz[u] = 1;
            for (int v : bl.adj[u])
                if (v != p)
                    sz[u] += self(self, v, u);
            return sz[u];
        };

        vector<long long> ret(n + 1);
        ret[0] = (long long) n * (n - 1) / 2;
        int l = -1, r = -1;
        for (int u=0; u<n; u++) {
            if (l == -1) {
                l = u;
            } else if (r == -1) {
                r = u;
            } else {
                int lu = bl.dist(l, u), ru = bl.dist(r, u), lr = bl.dist(l, r);
                if (lu + lr == ru)
                    l = u;
                else if (lr + ru == lu)
                    r = u;
                else if (lu + ru != lr)
                    break;
            }
            if (r == -1) {
                bl.init(l);
                dfs(dfs, l, -1);
                ret[u+1] = n - 1;
                long long tot = 0;
                for (int v : bl.adj[l]) {
                    ret[u+1] += sz[v] * tot;
                    tot += sz[v];
                }
            } else {
                int w = bl.lca(l, r);
                if (w == r)
                    swap(l, r);
                if (w == l) {
                    int v = bl.kthAnc(r, bl.depth[r] - bl.depth[l] - 1);
                    ret[u+1] = (long long) sz[r] * (n - sz[v]);
                } else {
                    ret[u+1] = (long long) sz[l] * sz[r];
                }
            }
            ret[u] -= ret[u+1];
        }

        for (long long x : ret)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}