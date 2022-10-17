
#include <bits/stdc++.h>
using namespace std;
const long long int mod=1e9+7;
long long int dp[200100][10];
int main()
{
    long long int n,l,r;
    scanf("%lld%lld%lld",&n,&l,&r);
    long long int a,b,c;//1,2,0;
    a=(r-l+1)/3;
    b=(r-l+1)/3;
    c=(r-l+1)/3;
    //long long int temp=(r-l+1)%3;
    for(int i=0;i<(r-l+1)%3;i++)
    {
        if((l+i)%3==0)
            c++;
        if((l+i)%3==2)
            b++;
        if((l+i)%3==1)
            a++;
    }
    dp[1][0]=c,dp[1][1]=a,dp[1][2]=b;
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=((dp[i-1][0]*c%mod+dp[i-1][1]*b%mod)%mod+dp[i-1][2]*a%mod)%mod;
        dp[i][1]=((dp[i-1][0]*a%mod+dp[i-1][1]*c%mod)%mod+dp[i-1][2]*b%mod)%mod;
        dp[i][2]=((dp[i-1][0]*b%mod+dp[i-1][1]*a%mod)%mod+dp[i-1][2]*c%mod)%mod;
    }
    printf("%I64d\n",dp[n][0]);
    return 0;
}