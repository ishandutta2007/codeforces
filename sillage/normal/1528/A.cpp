#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int l[maxn], r[maxn];
vector<int> g[maxn];
long long dp[maxn][2];
void dfs(int u, int fa){
    for (auto v : g[u]) if (v != fa) {
        dfs(v, u);
    }
    for (auto v: g[u]) if (v != fa){
        dp[u][0] += max(dp[v][0] + abs(l[v] - l[u]), dp[v][1] + abs(r[v] - l[u]));
        dp[u][1] += max(dp[v][0] + abs(l[v] - r[u]), dp[v][1] + abs(r[v] - r[u]));
    }
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear(), dp[i][0] = dp[i][1] = 0;
    for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
    for (int i = 1; i < n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    printf("%lld\n", max(dp[1][0], dp[1][1]));

}
int main(){
    int t;
    cin >> t;
    while (t--) solve();

}