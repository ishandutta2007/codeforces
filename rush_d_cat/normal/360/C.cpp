#include <iostream>
using namespace std;
typedef long long LL;
const int N=2002;
const int MOD=1e9+7;

char s[N]; int n,k;
LL dp[N][N][2],sum[N][N];

int main() {
    scanf("%d%d%s",&n,&k,s+1);
    dp[0][0][0] = 1; for(int i=0;i<N;i++) sum[0][i]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j][0] = sum[j][i-1] * (s[i]-'a') % MOD; 
            dp[i][j][1] = 0;
            for(int x=i-1;x>=0;x--) {
                int pos=j-(i-x)*(n-i+1); if(pos<0) break;
                dp[i][j][1] = (dp[i][j][1] + (dp[x][pos][0] + dp[x][pos][1])) % MOD;
            }
            dp[i][j][1] = dp[i][j][1] * ('z'-s[i]) % MOD;
            sum[j][i] = (sum[j][i-1] + dp[i][j][0] + dp[i][j][1]) % MOD;
        }
    }
    LL ans=0;
    for(int i=0;i<=n;i++) ans=(ans+dp[i][k][0]+dp[i][k][1])%MOD;
    cout<<ans<<endl;
}