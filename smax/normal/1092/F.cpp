#include <bits/stdc++.h>
using namespace std;

int a[200000];
long long mx = 0, ret = 0, dp[200000];
vector<int> adj[200000];

long long init(int u, int p, int d) {
    ret += (long long) d * a[u];
    dp[u] = a[u];
    for (int v : adj[u])
        if (v != p)
            dp[u] += init(v, u, d + 1);
    return dp[u];
}

void dfs(int u, int p) {
    mx = max(mx, ret);
    for (int v : adj[u])
        if (v != p) {
            ret -= dp[v];
            dp[u] -= dp[v];
            ret += dp[u];
            dp[v] += dp[u];

            dfs(v, u);

            dp[v] -= dp[u];
            ret -= dp[u];
            dp[u] += dp[v];
            ret += dp[v];
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

    init(0, -1, 0);
    dfs(0, -1);

    cout << mx << "\n";

    return 0;
}