#include<bits/stdc++.h>
using namespace std;
#define N 105

const int mod = 1e9 + 7;
vector <int> adj[N];
int n, k, dp[N][50], tmp[50];

void dfs(int u, int p){
    dp[u][0] = dp[u][k+1] = 1;
    for (int x = 0; x < adj[u].size(); x ++) {
        int v = adj[u][x];
        if (v == p) continue;
        dfs(v, u);
        memset(tmp, 0, sizeof tmp);
        for (int i  =  0; i <= 2 * k; i ++) {
            for (int j = 0; j <= 2 * k; j ++) {
                if (i + j <=  2 * k) tmp[min(i,j+1)] = (tmp[min(i,j+1)] + 1ll * dp[u][i] * dp[v][j]) % mod;
                else tmp[max(i,j+1)] = (tmp[max(i,j+1)] + 1ll * dp[u][i] * dp[v][j]) % mod;
            }
        }
        for (int i = 0; i <= 2 * k; i ++) dp[u][i] = tmp[i];
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    scanf("%d %d", &n, &k);
    int i, ans = 0;
    for (i = 1; i < n; i ++) {
       int u, v;
       scanf("%d %d", &u, &v);
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    dfs(1, 0);
    for (i = 0; i <= k; i ++)
        ans = (ans + dp[1][i]) % mod;
    printf("%d\n", ans);

//    for (i = 1; i <= n; i ++) {
//        for (int j = 0; j <= 2 * k; j ++)
//            printf("dp[%d][%d] = %2d ", i, j, dp[i][j]);
//        puts("");
//    }
    return 0;
}