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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n, vector<int>(k + 2));

    auto dfs = [&] (auto &self, int u, int p) -> void {
        for (int v : adj[u])
            if (v != p) {
                self(self, v, u);
                vector<int> ndp(k + 2);
                for (int j=0; j<=k+1; j++)
                    for (int l=0; l<=k+1; l++)
                        if (j + l + 1 > k)
                            ndp[min({j, l + 1, k + 1})] = max(ndp[min({j, l + 1, k + 1})], dp[u][j] + dp[v][l]);
                dp[u].swap(ndp);
            }
        dp[u][0] = max(dp[u][0], dp[u][k+1] + a[u]);
    };

    dfs(dfs, 0, -1);
    cout << *max_element(dp[0].begin(), dp[0].end()) << "\n";

    return 0;
}