#include<bits/stdc++.h>
#define MAXN 5005
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,k;
ll dp[MAXN][MAXN];
ll sum[MAXN];
char str[2];
int main()
{
    scanf("%I64d",&n);
    memset(dp,0,sizeof(dp));
    bool f=true;
    for(ll i=0;i<n;i++)
    {
        scanf("%s",str);
        if(i==0)
            dp[i][0]=1;
        else
        {
            if(f)
            {
                dp[i][0]=0;
                for(ll j=1;j<MAXN;j++)
                    dp[i][j]=dp[i-1][j-1];
            }
            else
                for(ll j=MAXN-1;j>=0;j--)
                    if(j==MAXN-1) dp[i][j]=dp[i-1][j]; else dp[i][j]=(dp[i][j+1]+dp[i-1][j])%MOD;
        }
        if(str[0]=='f') f=true; else f=false;
    }
    ll res=0;
    for(ll i=0;i<MAXN;i++)
        res=(res+dp[n-1][i])%MOD;
    printf("%I64d\n",res);
    return 0;
}