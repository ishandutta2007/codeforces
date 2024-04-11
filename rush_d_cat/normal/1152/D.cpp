#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
const int N=2002;
LL dp[N][N][2],vis[N][N];
int ok[N][N];
int n;

void dfs(int len,int lef) {
    //printf("len = %d, lef = %d\n", len,lef);
    if (vis[len][lef]) return;
    vis[len][lef] = 1;

    if(len==2*n) {
        if(lef == 0) {
            dp[len][0][0]=0;dp[len][0][1]=0;
        } 
        return;
    }

    
    dfs(len+1,lef+1);
    if(lef) {
        dfs(len+1,lef-1);
    } else {
        dp[len][lef][0] = max(dp[len+1][lef+1][0], dp[len+1][lef+1][1]);
        dp[len][lef][1] = dp[len+1][lef+1][0] + ok[len+1][lef+1];
        return;
    }

    dp[len][lef][0] = 
    (max(dp[len+1][lef+1][0], dp[len+1][lef+1][1])
    + max(dp[len+1][lef-1][0], dp[len+1][lef-1][1])) % MOD;

    dp[len][lef][1] =
    (dp[len+1][lef+1][1] + max(dp[len+1][lef-1][0]+ok[len+1][lef-1], dp[len+1][lef-1][1]))%MOD;

    dp[len][lef][1] = 
    max(dp[len][lef][1], (dp[len+1][lef-1][1] + max(dp[len+1][lef+1][0]+ok[len+1][lef+1], dp[len+1][lef+1][1]))%MOD);
        
}

int main() {
    memset(vis,0,sizeof(vis));
    cin>>n; 
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            if(i>=j && (2*n-i)>=j) ok[i][j]=1;
        }
    }
    dfs(0,0);
    cout<<max(dp[0][0][0],dp[0][0][1])<<endl;
    /*
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            printf("dp[%d][%d] = %lld,%lld\n", i,j,dp[i][j][0],dp[i][j][1]);
        }
    }
    */
}