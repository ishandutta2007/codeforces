#include <iostream>
#include <vector>
using namespace std;
const int N = 100000+10;
int n, m, e[N];
vector<int> g[N];

int dp[N];

void dfs(int u, int p) {
    if (dp[u] != -1)
        return;

    int mx = 0;
    for (int i = 0; i < g[u].size(); i ++) {
        int v = g[u][i];
        dfs(v, u);
        mx = max(mx, (e[u] == 1 && e[v] == 0) + dp[v]);
    }
    if (g[u].size() == 0 && e[u] == 1) {
        dp[u] = 1; return;
    }
    dp[u] = mx;
}



int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &e[i]);
    
    for (int i = 1; i <= m; i ++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u ++, v ++;
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i ++) {
        dp[i] = -1;
    }
    for (int i = 1; i <= n; i ++) {
        dfs(i, -1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}