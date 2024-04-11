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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i=0; i<n-1; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // edge you have to cut, endpoints of path
        vector<array<int, 4>> paths;

        // find minimum path cover of tree by greedily matching paths
        auto dfs = [&] (auto &self, int u, int p) -> int {
            vector<pair<int, int>> all;
            for (int v : adj[u])
                if (v != p) {
                    int nd = self(self, v, u);
                    if (nd != -1)
                        all.emplace_back(nd, v);
                }
            if (all.empty())
                return u;
            if (all.size() == 1)
                return all[0].first;
            for (int i=2; i<(int)all.size(); i++)
                paths.push_back({all[i].second, u, all[i].first, all[i].second});
            paths.push_back({u, p, all[0].first, all[1].first});
            return -1;
        };

        int nd = dfs(dfs, 0, -1);
        if (nd != -1)
            paths.push_back({0, -1, nd, 0});

        cout << paths.size() - 1 << "\n";
        nd = paths.back()[2];
        for (int i=0; i<(int)paths.size()-1; i++) {
            cout << paths[i][0] + 1 << " " << paths[i][1] + 1 << " " << nd + 1 << " " << paths[i][3] + 1 << "\n";
            nd = paths[i][2];
        }
    }

    return 0;
}