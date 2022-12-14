#include <bits/stdc++.h>
using namespace std;
long long C[1001][1001];
long long MOD = 998244353;
void init()
{
    C[0][0]=1;
    C[1][1]=1;
    C[1][0]=1;
    for (int i=2;i<=1000;i++)
    {
        C[i][0]=1;
        for (int j=1;j<=1000;j++)
        {
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
        }
    }
}
int n;
int a[1000000];
long long dp[1001];
long long DP(int i)
{
    if (i==n)
        return 1;
    if (dp[i]!=-1)
        return dp[i];
    dp[i]=DP(i+1);
    if (a[i]>0)
    {
        for (int j=i+1;j<n;j++)
        {
            long long num=0;
            int x=j-i;
            if (x>=a[i])
            {
                num=C[x-1][a[i]-1];
                dp[i]+=(DP(j+1)*num)%MOD;
                dp[i]%=MOD;
            }
        }
    }
    return dp[i];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    init();
    cout<<(DP(0)-1+MOD)%MOD<<endl;
}