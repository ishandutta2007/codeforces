#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500;

int n,a,b;
vector<int> G[N];
ll dp[2][N];
int sub[2][N];
ll res = 0;

void dfs(int v, int par = -1){
    sub[0][v] = 0, sub[1][v] = 0;
    dp[0][v] = dp[1][v] = 0;

    for(int nxt : G[v]){
        if(nxt == par) continue;
        dfs(nxt, v);
        sub[0][v] += sub[1][nxt];
        sub[1][v] += sub[0][nxt];
        dp[0][v] += dp[1][nxt];
        dp[1][v] += dp[0][nxt] + sub[0][nxt];
    }
    sub[0][v] += 1;
}

void ndfs(int v, int par = -1, ll p0 = 0, ll p1 = 0, int sub0 = 0, int sub1 = 0){
    ll tot[2] = {p1 + dp[0][v], p0 + sub0 + dp[1][v]};
    int subtot[2] = {sub1 + sub[0][v], sub0 + sub[1][v]};

    res += tot[0] + tot[1];
    for(int nxt : G[v]){
        if(nxt == par) continue;
        tot[0] -= dp[1][nxt];
        tot[1] -= dp[0][nxt] + sub[0][nxt];
        subtot[0] -= sub[1][nxt];
        subtot[1] -= sub[0][nxt];
        ndfs(nxt, v, tot[0], tot[1], subtot[0], subtot[1]);
        tot[0] += dp[1][nxt];
        tot[1] += dp[0][nxt] + sub[0][nxt];
        subtot[0] += sub[1][nxt];
        subtot[1] += sub[0][nxt];
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0);
    ndfs(0);
    cout << res / 2 << endl;
}