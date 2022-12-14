
#include <bits/stdc++.h>
using namespace std;
int a[1000];
long long dp[1001][11];
long long c[1001][1001];
long long C()
{
    for (int i=0;i<=100;i++)c[i][0]=1,c[i][i]=1;
    for (int i=1;i<=100;i++)
    {
        for (int j=1;j<i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%1000000007;
        }
    }
}
long long DP(int n,int i)
{
    if (i==9)return (a[i]<=n);
    if (dp[n][i]!=-1)
        return dp[n][i];
    long long ret=0;
    for (int j=a[i];j<=n;j++)
        ret+=(DP(n-j,i+1)*c[n-(i==0)][j])%1000000007,ret%=1000000007;
    dp[n][i]=ret;
    return ret;
}
int main()
{
    int n;
    cin>>n;
    C();
    memset(dp,-1,sizeof(dp));
    for (int i=0;i<=9;i++)
        cin>>a[i];
    long long ret=0;
    for (int i=1;i<=n;i++)
    {
        ret+=DP(i,0);
        ret%=1000000007;
    }
    cout<<ret<<endl;
}