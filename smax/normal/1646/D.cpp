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

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 2) {
        cout << "2 2\n1 1\n";
        return 0;
    }

    vector<vector<pair<int, long long>>> dp(n, vector<pair<int, long long>>(2));

    auto dfs1 = [&] (auto &self, int u, int p) -> void {
        dp[u][0] = {0, 1};
        dp[u][1] = {1, adj[u].size()};
        for (int v : adj[u])
            if (v != p) {
                self(self, v, u);
                int mx = max(dp[v][0].first, dp[v][1].first);
                long long mn = LLONG_MAX;
                if (dp[v][0].first == mx)
                    mn = min(mn, dp[v][0].second);
                if (dp[v][1].first == mx)
                    mn = min(mn, dp[v][1].second);
                dp[u][0].first += mx;
                dp[u][0].second += mn;
                dp[u][1].first += dp[v][0].first;
                dp[u][1].second += dp[v][0].second;
            }
    };

    vector<bool> good(n);

    auto dfs2 = [&] (auto &self, int u, int p, bool c) -> void {
        good[u] = c;
        if (c) {
            for (int v : adj[u])
                if (v != p)
                    self(self, v, u, false);
        } else {
            for (int v : adj[u])
                if (v != p) {
                    int mx = max(dp[v][0].first, dp[v][1].first);
                    long long mn = LLONG_MAX;
                    if (dp[v][0].first == mx)
                        mn = min(mn, dp[v][0].second);
                    if (dp[v][1].first == mx)
                        mn = min(mn, dp[v][1].second);
                    self(self, v, u, dp[v][1].first == mx && dp[v][1].second == mn);
                }
        }
    };

    dfs1(dfs1, 0, -1);
    int mx = max(dp[0][0].first, dp[0][1].first);
    long long mn = LLONG_MAX;
    if (dp[0][0].first == mx)
        mn = min(mn, dp[0][0].second);
    if (dp[0][1].first == mx)
        mn = min(mn, dp[0][1].second);
    dfs2(dfs2, 0, -1, dp[0][1].first == mx && dp[0][1].second == mn);
    cout << mx << " " << mn << "\n";
    for (int i=0; i<n; i++)
        cout << (good[i] ? adj[i].size() : 1) << " ";
    cout << "\n";

    return 0;
}