#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = 1000020, INF = (int)1e9;
const int LOG_N = 20;
int root = 0;
int n,m,a,b;
int val[N];

vector<int> G[N];
int dp[2][N];
int up[N], down[N];


void get(int v){
    dp[0][v] = val[v];

    for(int nxt : G[v]){
        get(nxt);
        dp[0][v] += dp[0][nxt];
        dp[1][v] = max(dp[1][v], dp[1][nxt]);
    }
    if(up[v] == -1){
        dp[1][v] = dp[1][v] + dp[0][v];
        dp[0][v] = 0;
    }
}

int dfs_val(int v, int p){
    if(G[v].size() == 0){
        down[v] = 0;
        val[v] = 1;
    }
    else{
        down[v] = INF;
        for(int nxt : G[v]){
            if(nxt != p){
                down[v] = min(down[v], dfs_val(nxt, v) + 1);
            }
        }
    }
    up[v] = (down[v] < m ? 1 : -1);
    return down[v];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++){
        int x;
        scanf("%d", &x);
//        cout << i + 1 << " " << x << endl;
        x--;
        G[x].push_back(i);
    }
    dfs_val(0, -1);
    get(0);
    cout << dp[0][0] + dp[1][0] << endl;

}