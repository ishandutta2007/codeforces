#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int N=200000+10;
typedef long long LL;
int T,n,a,b;LL dp[N][2];
char s[N]; 
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%s",&n,&a,&b,s+1);
        dp[0][0]=b; dp[0][1]=1e18;
        for(int i=1;i<=n;i++){
            dp[i][0]=min(dp[i-1][0]+a+b, dp[i-1][1]+2*a+b);
            dp[i][1]=dp[i-1][1]+a+2*b;
            if(s[i]=='1') {
                dp[i][0]=1e18;
            } else {
                dp[i][1]=min(dp[i-1][0]+2*a+2*b, dp[i][1]);
            }
            //printf("dp[%d] %lld %lld\n", i,dp[i][0],dp[i][1]);
        }
        printf("%lld\n", dp[n][0]);
    }
}