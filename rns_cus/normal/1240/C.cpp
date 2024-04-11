#include <bits/stdc++.h>
using namespace std;

#define N 500500
typedef pair <int, int> pii;
typedef long long ll;
int n, k;
ll dp[N][2];
vector <pii> adj[N];

void dfs(int u, int pa = 0) {
    vector <ll> vec;
    dp[u][0] = 0;
    for (auto p : adj[u]) {
        int v = p.first, w = p.second;
        if (v == pa) continue;
        dfs(v, u);
        vec.push_back(dp[v][0] + w - dp[v][1]);
        dp[u][0] += dp[v][1];
    }
    sort(vec.begin(), vec.end(), greater <ll> () );
    int sz = vec.size();
    for (int i = 0; i < sz && i < k - 1; i ++) if (vec[i] > 0) dp[u][0] += vec[i];
    dp[u][1] = dp[u][0];
    if (k - 1 < sz && vec[k-1] > 0) dp[u][1] += vec[k-1];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i ++) adj[i].clear();
        for (int i = 1, u, v, w; i < n; i ++) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        dfs(1);
        printf("%I64d\n", dp[1][1]);
    }
}