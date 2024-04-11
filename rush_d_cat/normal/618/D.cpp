#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;

LL n, x, y, a, b;
vector<int> G[200000+10];
LL dis[200000+10], deg[200000+10], vis[200000+10];  
set<int> leaf;

int dp[200000+10][2];

void dfs(int u) {
    vis[u] = 1;

    int sum = 0; int has_son = 0;
    
    vector<int> mx;

    for(int i = 0; i < G[u].size(); i ++) {
        int v = G[u][i];
        if(vis[v]) continue;
        dfs(v); sum += dp[v][0];
        mx.push_back(dp[v][1] - dp[v][0]);
        has_son = 1;
    }
    sort(mx.begin(), mx.end());
    if(!has_son) {
        dp[u][0] = dp[u][1] = 0;
        return;
    }

    int mx1 = -10000000, mx2 = -10000000;

    dp[u][1] = dp[u][0] = sum;
    
    if(mx.size() >= 1) {
        mx1 = mx[mx.size() - 1];  
        dp[u][1] = max(sum + mx1 + 1, dp[u][1]); 
        dp[u][0] = max(sum + mx1 + 1, dp[u][0]); 
    }

    if(mx.size() >= 2) {
        mx2 = mx[mx.size() - 2]; 
        dp[u][0] = max(sum + mx1 + mx2 + 2, dp[u][0]); 
    }
    
    //printf("%d %d %d\n", u, dp[u][0], dp[u][1]);
}

int main() {
    
    scanf("%lld %lld %lld", &n, &x, &y);

    for(int i = 1; i < n; i ++) 
    {
        scanf("%lld %lld", &a, &b);
        G[a].push_back(b); G[b].push_back(a);
        deg[a] ++, deg[b] ++;
    }

    int ok = 0;
    
    for(int i = 1; i <= n; i ++) 
    {
        if(G[i].size() == n-1) ok = 1;
    }

    LL ans = 0;
    if(x > y) 
    {
        ans = (n - 1) * y;
        if(ok) ans = ans - y + x;

    } else {

        dfs(1); LL t = max(dp[1][0], dp[1][1]);
        ans = t * x + (n - 1 - t) * y;
    
    }
    cout << ans << endl;

}
/*
8 1 10
1 2
2 3
4 5
5 6
2 7
7 5
7 8
*/