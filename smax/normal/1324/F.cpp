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

int a[200000], dp[200000], ret[200000];
vector<int> adj[200000];

int dfsDP(int u, int p) {
    dp[u] = (a[u] ? 1 : -1);
    for (int v : adj[u])
        if (v != p)
            dp[u] += max(dfsDP(v, u), 0);
    return dp[u];
}

void dfsReroot(int u, int p) {
    ret[u] = dp[u];
    for (int v : adj[u])
        if (v != p) {
            dp[u] -= max(dp[v], 0);
            dp[v] += max(dp[u], 0);

            dfsReroot(v, u);

            dp[v] -= max(dp[u], 0);
            dp[u] += max(dp[v], 0);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dfsDP(0, -1);
    dfsReroot(0, -1);

    for (int i=0; i<n; i++)
        cout << ret[i] << " ";
    cout << "\n";

    return 0;
}