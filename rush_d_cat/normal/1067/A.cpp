#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=100000+10;
const int MOD=998244353;
int n,dp[N][202][3],s[202][3],a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(a[1]==-1){
        for(int i=1;i<=200;i++)dp[1][i][1]=1;
    } else {
        dp[1][a[1]][1]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=200;j++)for(int k=0;k<3;k++)
            s[j][k]=(s[j-1][k]+dp[i-1][j][k])%MOD;
        int l,r; 
        if(a[i]==-1) l=1,r=200;
        else l=a[i],r=a[i];
        for(int j=l;j<=r;j++){
            dp[i][j][0]=(1LL*dp[i-1][j][0]+1LL*dp[i-1][j][1]+1LL*dp[i-1][j][2])%MOD;
            dp[i][j][1]=(1LL*s[j-1][0]+1LL*s[j-1][1]+1LL*s[j-1][2])%MOD;
            dp[i][j][2]=(1LL*s[200][0]-s[j][0] + 1LL*s[200][2]-s[j][2])%MOD;
        }
    }
    int ans=0;
    for(int i=1;i<=200;i++){
        ans=(ans+1LL*dp[n][i][0]+dp[n][i][2])%MOD;
        ans=(ans%MOD+MOD)%MOD;
    }
    cout<<ans<<endl;
}