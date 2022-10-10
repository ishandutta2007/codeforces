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

const int MAX = 2e5 + 5;
const int SZ = 450;

int dp[MAX][SZ], ndp[SZ], sz[MAX], ret[MAX];
vector<int> adj[MAX];
vector<array<int, 3>> queries[2];

void dfs1(int u, int p) {
    dp[u][0] = 0;
    sz[u] = 1;
    for (int v : adj[u])
        if (v != p) {
            dfs1(v, u);
            memset(ndp, 0, sizeof(int) * min(sz[u] + sz[v], SZ));
            for (int i=0; i<sz[u]; i++)
                for (int j=0; j<min(sz[v], SZ-i+1); j++) {
                    ndp[i+j] = max(ndp[i+j], dp[u][i] + 1);
                    if (i + j + 1 < SZ)
                        ndp[i+j+1] = max(ndp[i+j+1], dp[u][i] + dp[v][j]);
                }
            sz[u] = min(sz[u] + sz[v], SZ);
            memcpy(dp[u], ndp, sizeof(int) * sz[u]);
        }
}

void dfs2(int u, int p) {
    for (int v : adj[u])
        if (v != p) {
            dfs2(v, u);
            for (int k=0; k<SZ; k++)
                dp[u][k] += max(dp[v][k] - k, 1);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int v, k;
        cin >> v >> k;
        v--;
        queries[k < SZ].push_back({v, k, i});
    }

    dfs1(0, -1);
    for (auto [v, k, i] : queries[0])
        for (int j=0; j<sz[v]; j++)
            ret[i] = (int) max((long long) ret[i], dp[v][j] - (long long) j * k);

    memset(dp, 0, sizeof(dp));
    dfs2(0, -1);
    for (auto [v, k, i] : queries[1])
        ret[i] = dp[v][k];

    for (int i=0; i<q; i++)
        cout << ret[i] << "\n";

    return 0;
}