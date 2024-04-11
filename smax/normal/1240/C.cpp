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

    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<vector<pair<int, int>>> adj(n);
        for (int i=0; i<n-1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        // 0/1 - saturated or not
        vector<vector<long long>> dp(n, vector<long long>(2));

        auto dfs = [&] (auto &self, int u, int p) -> void {
            vector<long long> all;
            for (auto [v, w] : adj[u])
                if (v != p) {
                    self(self, v, u);
                    dp[u][0] += max(dp[v][0], dp[v][1]);
                    all.push_back(w + dp[v][0] - max(dp[v][0], dp[v][1]));
                }
            sort(all.rbegin(), all.rend());
            for (int i=0; i<min(k, (int)all.size()); i++) {
                if (i == k - 1) {
                    dp[u][1] = max(dp[u][1], dp[u][0] + all[i]);
                } else {
                    dp[u][0] += max(all[i], 0LL);
                    dp[u][1] = max(dp[u][1], dp[u][0]);
                }
            }
        };

        dfs(dfs, 0, -1);
        cout << max(dp[0][0], dp[0][1]) << "\n";
    }

    return 0;
}