#include<bits/stdc++.h>
#define MAXN 5005
#define MOD 998244353
using namespace std;
typedef long long ll;
ll dp[MAXN][MAXN];
ll cal(ll a,ll b)
{
    dp[1][0]=1;
    dp[1][1]=b;
    for(int i=2;i<=a;i++)
        for(int j=0;j<=i;j++)
        {
            if(j==0) dp[i][j]=1;
            else dp[i][j]=(dp[i-1][j-1]*(b-j+1)+dp[i-1][j])%MOD;
        }
    ll s=0;
    for(int i=0;i<=a;i++)
        s=(s+dp[a][i])%MOD;
    return s;
}
ll a[3];
ll ans=1;
int main()
{
    for(int i=0;i<3;i++)
        scanf("%I64d",&a[i]);
    sort(a,a+3);
    ans=ans*cal(a[0],a[1])%MOD;
    ans=ans*cal(a[0],a[2])%MOD;
    ans=ans*cal(a[1],a[2])%MOD;
    printf("%I64d\n",ans);
    return 0;
}