#include <bits/stdc++.h>
#define MOD 998244353
#define ll long long
using namespace std;
long long dp[501][501][2];
long long sum[501];
long long num[501];
int n;
long long solve(int i,int j,bool ok)
{
    if (i>n)return 0;
    if (i==n)return ok;
    if (dp[i][j][ok]!=-1)
        return dp[i][j][ok];
    ll &ret = dp[i][j][ok];
    ret=solve(i+j,j,1);
    for (int x=1;x<j;x++)
        ret+=solve(i+x,j,ok),ret%=MOD;
    return ret;
}
int main ()
{
    memset(dp,-1,sizeof(dp));
    int k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        num[i]=(solve(0,i,0))%MOD;
        sum[i]=num[i]+sum[i-1];
        sum[i]%=MOD;
    }
    k--;
    ll ret=0;
    for (int i=1;i<=n;i++)
    {
        int l = min(k/i,n);
        ret+=(2*num[i]*sum[l])%MOD;
        ret%=MOD;
    }
    cout<<ret<<endl;
}