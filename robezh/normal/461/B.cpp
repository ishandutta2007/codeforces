#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 500;
const int mod = (int)1e9 + 7;

int n,a;
vector<int> G[N];
int clr[N];
ll dp[2][N];

void dfs(int v){
    dp[0][v] = 1 - clr[v];
    dp[1][v] = clr[v];

    for(int nxt : G[v]){
        ll old[2] = {dp[0][v], dp[1][v]};
        dp[0][v] = dp[1][v] = 0;
        dfs(nxt);

        dp[0][v] += dp[1][nxt] * old[0];
        dp[1][v] += dp[1][nxt] * old[1];

        dp[1][v] += dp[1][nxt] * old[0];
        dp[1][v] += dp[0][nxt] * old[1];

        dp[0][v] += dp[0][nxt] * old[0];

        dp[0][v] %= mod, dp[1][v] %= mod;
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d", &a);
        G[a].push_back(i);
    }
    for(int i = 0; i < n; i++) scanf("%d", &clr[i]);
    dfs(0);
    printf("%d\n", (int)dp[1][0]);
}