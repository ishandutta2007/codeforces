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
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(2));
        for (int i=0; i<n; i++)
            cin >> a[i][0] >> a[i][1];
        vector<vector<int>> adj(n);
        for (int i=0; i<n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<long long>> dp(n, vector<long long>(2));

        auto dfs = [&] (auto &self, int u, int p) -> void {
            for (int v : adj[u])
                if (v != p)
                    self(self, v, u);
            for (int x=0; x<2; x++)
                for (int v : adj[u])
                    if (v != p)
                        dp[u][x] += max(abs(a[u][x] - a[v][0]) + dp[v][0], abs(a[u][x] - a[v][1]) + dp[v][1]);
        };

        dfs(dfs, 0, -1);
        cout << max(dp[0][0], dp[0][1]) << "\n";
    }

    return 0;
}