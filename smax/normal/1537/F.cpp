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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> init(n), fin(n);
        vector<vector<int>> adj(n);
        for (int i=0; i<n; i++)
            cin >> init[i];
        for (int i=0; i<n; i++)
            cin >> fin[i];
        for (int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> color(n, -1);
        vector<bool> vis(n);

        auto dfs1 = [&] (auto &self, int u, int c) -> bool {
            if (color[u] != -1)
                return color[u] == c;
            color[u] = c;
            for (int v : adj[u])
                if (!self(self, v, c ^ 1))
                    return false;
            return true;
        };

        auto dfs2 = [&] (auto &self, int u) -> void {
            vis[u] = true;
            for (int v : adj[u])
                if (!vis[v]) {
                    self(self, v);
                    init[u] += fin[v] - init[v];
                    init[v] = fin[v];
                }
        };

        bool bipartite = dfs1(dfs1, 0, 0);
        dfs2(dfs2, 0);
        if (init[0] == fin[0] || ((fin[0] - init[0]) % 2 == 0 && !bipartite))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}