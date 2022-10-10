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

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> d(n, -1e9), ret;
    vector<bool> vis(n);

    auto dfs2 = [&] (auto &self, int u, int p, int r, bool s) -> bool {
        if (s && u == r)
            return true;
        if (d[u] == 1)
            s = true;
        if (vis[u])
            return false;
        vis[u] = true;
        for (int v : adj[u])
            if (v != p) {
                if (!s && d[v] == d[u] - 1) {
                    self(self, v, u, r, false);
                    ret.push_back(u);
                    return true;
                } else if (s && self(self, v, u, r, true)) {
                    ret.push_back(u);
                    return true;
                }
            }
        return false;
    };

    auto dfs1 = [&] (auto &self, int u, int p) -> int {
        vis[u] = true;
        for (int v : adj[u])
            if (v != p) {
                if (!vis[v])
                    d[u] = max(d[u], self(self, v, u) + 1);
                else
                    d[u] = max(d[u], 1);
            }
        if (d[u] >= k + 1) {
            fill(vis.begin(), vis.end(), false);
            dfs2(dfs2, u, -1, u, false);
            cout << ret.size() << "\n";
            for (int v : ret)
                cout << v + 1 << " ";
            cout << "\n";
            exit(0);
        }
        return d[u];
    };

    for (int u=0; u<n; u++)
        if (!vis[u])
            dfs1(dfs1, u, -1);

    return 0;
}