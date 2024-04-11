#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

int sub[200000];
long long dp[200000];
vector<int> adj[200000];

int dfsDP(int u, int p) {
    sub[u] = 1;
    for (int v : adj[u])
        if (v != p)
            sub[u] += dfsDP(v, u);

    dp[u] = sub[u];
    for (int v : adj[u])
        if (v != p)
            dp[u] += dp[v];

    return sub[u];
}

long long dfsReroot(int u, int p) {
    long long ret = dp[u];
    for (int v : adj[u])
        if (v != p) {
            sub[u] -= sub[v];
            dp[u] -= sub[v] + dp[v];
            sub[v] += sub[u];
            dp[v] += sub[u] + dp[u];

            ret = max(ret, dfsReroot(v, u));

            dp[v] -= sub[u] + dp[u];
            sub[v] -= sub[u];
            dp[u] += sub[v] + dp[v];
            sub[u] += sub[v];
        }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dfsDP(0, -1);
    cout << dfsReroot(0, -1) << "\n";

    return 0;
}