#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
LL n, dp[50][50][2];
void ADD(LL &x, LL y) {
    x=(x+y)%MOD;
}
int main() {
    cin>>n;
    dp[32][0][1]=1;
    for(int i=32;i>=1;i--){
        for(int j=0;j<=32-i+1;j++){
            ADD(dp[i-1][j+1][0],dp[i][j][0]);
            ADD(dp[i-1][j][0],dp[i][j][0]*(1LL<<j));
            LL t0=j?(1<<(j-1)):1;
            LL t1=j?(1<<(j-1)):0;
            if(n>>(i-1)&1){
                ADD(dp[i-1][j][1],dp[i][j][1]*t1);
                ADD(dp[i-1][j][0],dp[i][j][1]*t0);
                ADD(dp[i-1][j+1][1],dp[i][j][1]);
            }else{
                ADD(dp[i-1][j][1],dp[i][j][1]*t0);
            }
        }
    }
    LL ans=0;
    for(int i=0;i<=32;i++){
        ADD(ans,dp[0][i][0]+dp[0][i][1]);
    }
    cout<<ans<<endl;
}