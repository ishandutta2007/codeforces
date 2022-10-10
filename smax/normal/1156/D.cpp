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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int dp[200005][2];
vector<pair<int, int>> adj[200005];

void dfs1(int u, int p) {
    dp[u][0] = dp[u][1] = 1;
    for (auto [v, w] : adj[u])
        if (v != p) {
            dfs1(v, u);
            if (w == 0) {
                dp[u][0] += dp[v][0];
            } else {
                dp[u][0] += dp[v][1];
                dp[u][1] += dp[v][1];
            }
        }
}

long long dfs2(int u, int p) {
    long long ret = dp[u][0] - 1;
    for (auto [v, w] : adj[u])
        if (v != p) {
            if (w == 0) {
                dp[u][0] -= dp[v][0];
                dp[v][0] += dp[u][0];
            } else {
                dp[u][0] -= dp[v][1];
                dp[u][1] -= dp[v][1];
                dp[v][0] += dp[u][1];
                dp[v][1] += dp[u][1];
            }
            ret += dfs2(v, u);
            if (w == 0) {
                dp[v][0] -= dp[u][0];
                dp[u][0] += dp[v][0];
            } else {
                dp[v][0] -= dp[u][1];
                dp[v][1] -= dp[u][1];
                dp[u][0] += dp[v][1];
                dp[u][1] += dp[v][1];
            }
        }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        adj[x].emplace_back(y, c);
        adj[y].emplace_back(x, c);
    }

    dfs1(0, -1);
    cout << dfs2(0, -1) << "\n";

    return 0;
}