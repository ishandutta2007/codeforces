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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> par(n), depth(n), sz(n);

    auto dfs = [&] (auto &self, int u) -> void {
        sz[u] = 1;
        for (int v : adj[u])
            if (v != par[u]) {
                par[v] = u;
                depth[v] = depth[u] + 1;
                self(self, v);
                sz[u] += sz[v];
            }
    };

    par[0] = -1;
    dfs(dfs, 0);
    vector<int> nodes(n), cover(n);
    vector<bool> vis(n);
    iota(nodes.begin(), nodes.end(), 0);
    sort(nodes.begin(), nodes.end(), [&] (int u, int v) -> bool {
        return depth[u] > depth[v];
    });
    for (int u : nodes) {
        int v = u;
        while (v != -1 && !vis[v]) {
            cover[u]++;
            vis[v] = true;
            v = par[v];
        }
    }
    sort(nodes.begin(), nodes.end(), [&] (int u, int v) -> bool {
        return cover[u] > cover[v];
    });

    long long ret = (long long) -n / 2 * (n - n / 2);
    int blue = n;
    vector<bool> taken(n);
    taken[0] = true;
    fill(vis.begin(), vis.end(), false);
    for (int i=0; i<k; i++) {
        int u = nodes[i];
        while (u != -1 && !vis[u]) {
            vis[u] = true;
            if (taken[u]) {
                blue -= sz[u];
                taken[u] = false;
            }
            for (int v : adj[u])
                if (v != par[u] && !vis[v]) {
                    blue += sz[v];
                    taken[v] = true;
                }
            u = par[u];
        }
        ret = max(ret, (long long) (i + 1) * (n - i - 1) - (long long) min(blue, n / 2) * (n - min(blue, n / 2)));
    }
    cout << ret << "\n";

    return 0;
}