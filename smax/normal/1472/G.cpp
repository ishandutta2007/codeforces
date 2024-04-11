#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int dist[200005], dp[200005][2];
vector<int> adj[200005];

int solve(int u, int b) {
    if (u == 0)
        return 0;
    if (dp[u][b] != -1)
        return dp[u][b];
    dp[u][b] = dist[u];
    for (int v : adj[u]) {
        if (dist[u] < dist[v])
            dp[u][b] = min(dp[u][b], solve(v, b));
        else if (!b)
            dp[u][b] = min(dp[u][b], solve(v, 1));
    }
    return dp[u][b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i=0; i<n; i++)
            adj[i].clear();
        for (int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
        }

        memset(dist, -1, sizeof(int) * n);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
        }

        for (int i=0; i<n; i++)
            for (int j=0; j<2; j++)
                dp[i][j] = -1;
        for (int i=0; i<n; i++)
            cout << solve(i, 0) << " ";
        cout << "\n";
    }

    return 0;
}