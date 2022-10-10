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
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(2 * k));

    auto dfs1 = [&] (auto &self, int u, int p) -> void {
        dp[u][0] ^= a[u];
        for (int v : adj[u])
            if (v != p) {
                self(self, v, u);
                for (int j=0; j<2*k; j++)
                    dp[u][(j+1)%(2*k)] ^= dp[v][j];
            }
    };

    vector<int> ret(n);

    auto dfs2 = [&] (auto &self, int u, int p) -> void {
        for (int j=k; j<2*k; j++)
            ret[u] ^= dp[u][j];
        for (int v : adj[u])
            if (v != p) {
                for (int j=0; j<2*k; j++)
                    dp[u][(j+1)%(2*k)] ^= dp[v][j];
                for (int j=0; j<2*k; j++)
                    dp[v][(j+1)%(2*k)] ^= dp[u][j];
                self(self, v, u);
                for (int j=0; j<2*k; j++)
                    dp[v][(j+1)%(2*k)] ^= dp[u][j];
                for (int j=0; j<2*k; j++)
                    dp[u][(j+1)%(2*k)] ^= dp[v][j];
            }
    };

    dfs1(dfs1, 0, -1);
    dfs2(dfs2, 0, -1);
    for (int i=0; i<n; i++)
        cout << (ret[i] > 0) << " ";
    cout << "\n";

    return 0;
}