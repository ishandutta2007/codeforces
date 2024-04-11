#include <bits/stdc++.h>
using namespace std;

#define N 500050

const int mod = 998244353;

struct expe{
    int sum, cnt;
    expe(long long s = 0, long long c = 0) {
        sum = s % mod, cnt = c % mod;
    }
    expe operator + (expe x) {
        return expe(sum + x.sum, cnt + x.cnt);
    }
    expe operator * (expe x) {
        return expe(1ll * sum * x.cnt + 1ll * x.sum * cnt, 1ll * cnt * x.cnt);
    }
} dp[N][2];

int n;
vector <int> adj[N];

void dfs(int u, int pa = 0) {
    dp[u][1] = expe(0, 1);
    for (auto v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
        expe x = dp[u][0], y = dp[u][1];
        dp[u][0] = x * (dp[v][0] + dp[v][1]);
        dp[u][1] = y * (dp[v][0] + dp[v][1]);
        dp[u][1] = dp[u][1] + y * dp[v][0];
        dp[u][0] = dp[u][0] + x * (dp[v][0] + dp[v][1]) + y * dp[v][1] + expe(1ll * y.cnt * dp[v][1].cnt);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i ++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    printf("%d\n", 2 * (dp[1][0] + dp[1][1]).sum % mod);
}