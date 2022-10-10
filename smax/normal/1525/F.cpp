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

struct Matching {
    int n, m;
    vector<int> matchL, matchR, dist;
    vector<vector<int>> adj;

    Matching(int _n, int _m) : n(_n), m(_m), matchL(n + 1), matchR(m + 1), dist(n + 1), adj(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int u=1; u<=n; u++) {
            if (!matchL[u]) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = INT_MAX;
            }
        }
        dist[0] = INT_MAX;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (dist[u] < dist[0])
                for (int v : adj[u])
                    if (dist[matchR[v]] == INT_MAX) {
                        dist[matchR[v]] = dist[u] + 1;
                        q.push(matchR[v]);
                    }
        }
        return dist[0] != INT_MAX;
    }

    bool dfs(int u) {
        if (u != 0) {
            for (int v : adj[u])
                if (dist[matchR[v]] == dist[u] + 1 && dfs(matchR[v])) {
                    matchL[u] = v;
                    matchR[v] = u;
                    return true;
                }
            dist[u] = INT_MAX;
            return false;
        }
        return true;
    }

    int solve() {
        int ret = 0;
        while (bfs())
            for (int u=1; u<=n; u++)
                if (!matchL[u] && dfs(u))
                    ret++;
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    Matching matching(n, n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        matching.addEdge(u, v);
    }
    vector<int> x(k), y(k);
    for (int i=0; i<k; i++)
        cin >> x[i] >> y[i];

    int o = matching.solve();
    vector<int> seq;
    vector<bool> visL(n + 1), visR(n + 1);

    auto dfs = [&] (auto &self, int u) -> void {
        visL[u] = true;
        for (int v : matching.adj[u])
            if (v != matching.matchL[u] && !visR[v]) {
                visR[v] = true;
                if (matching.matchR[v] && !visL[matching.matchR[v]])
                    self(self, matching.matchR[v]);
            }
    };

    for (int u=1; u<=n; u++)
        if (!matching.matchL[u])
            dfs(dfs, u);

    for (int u=1; u<=n; u++)
        if (!visL[u])
            seq.push_back(u);
    for (int v=1; v<=n; v++)
        if (visR[v])
            seq.push_back(-v);

    auto ckmax = [&] (long long &a, long long b) -> bool {
        return a < b ? a = b, true : false;
    };

    vector<vector<long long>> dp(k + 1, vector<long long>(o + 1, -1e18));
    vector<vector<int>> par(k + 1, vector<int>(o + 1));
    dp[0][0] = 0;
    for (int i=0; i<k; i++)
        for (int j=0; j<=o; j++)
            for (int t=max(i+2-(n-o+j), 0); t<=o-j; t++)
                if (ckmax(dp[i+1][j+t], dp[i][j] + max(0LL, x[i] - (long long) t * y[i])))
                    par[i+1][j+t] = t;

    int best = -1;
    long long mx = -1e18;
    for (int j=0; j<=o; j++)
        if (ckmax(mx, dp[k][j]))
            best = j;

    vector<int> ret;
    for (int i=k; i>0; i--) {
        ret.push_back(0);
        int t = par[i][best];
        while (t--)
            ret.push_back(seq[--best]);
    }

    cout << ret.size() << "\n";
    for (int i=(int)ret.size()-1; i>=0; i--)
        cout << ret[i] << " ";
    cout << "\n";

    return 0;
}