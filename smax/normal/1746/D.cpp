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
        vector<vector<int>> adj(n);
        for (int i=1; i<n; i++) {
            int p;
            cin >> p;
            adj[--p].push_back(i);
        }
        vector<int> s(n);
        for (int &x : s)
            cin >> x;

        vector<map<int, long long>> dp(n);

        auto solve = [&] (auto &self, int u, int k) -> void {
            if (dp[u].count(k))
                return;
            long long &ret = dp[u][k];
            ret += (long long) k * s[u];
            if (!adj[u].empty()) {
                int rem = k % adj[u].size();
                for (int v : adj[u]) {
                    self(self, v, k / adj[u].size());
                    if (rem)
                        self(self, v, k / adj[u].size() + 1);
                    ret += dp[v][k / adj[u].size()];
                }
                if (rem) {
                    vector<long long> all;
                    for (int v : adj[u])
                        all.push_back(dp[v][k / adj[u].size() + 1] - dp[v][k / adj[u].size()]);
                    sort(all.rbegin(), all.rend());
                    for (int i=0; i<rem; i++)
                        ret += all[i];
                }
            }
        };

        solve(solve, 0, k);
        cout << dp[0][k] << "\n";
    }

    return 0;
}