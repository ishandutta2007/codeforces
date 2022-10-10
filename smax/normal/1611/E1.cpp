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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> dist(n, -1);
        queue<int> que;
        for (int i=0; i<k; i++) {
            int x;
            cin >> x;
            x--;
            dist[x] = 0;
            que.push(x);
        }
        vector<vector<int>> adj(n);
        for (int i=0; i<n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v : adj[u])
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    que.push(v);
                }
        }

        int ret = 0;

        auto dfs = [&] (auto &self, int u, int p, int d) -> bool {
            if (dist[u] <= d) {
                ret++;
                return true;
            }
            if (u != 0 && adj[u].size() == 1)
                return false;
            for (int v : adj[u])
                if (v != p && !self(self, v, u, d + 1))
                    return false;
            return true;
        };

        if (dfs(dfs, 0, -1, 0)) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}