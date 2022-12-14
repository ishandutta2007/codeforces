# include <iostream>
# include <stdio.h>
# include <map>
# include <algorithm>
# include <vector>
#define INF (long long)(1e9)
using namespace std;
long long dp[1<<19][19];
long long adj[101][101];
long long a[1000];
int main()
{
    long long n,m,k;
    cin>>n>>m>>k;
    for (long long i=0;i<n;i++)
        cin>>a[i];
    for (long long i=0;i<k;i++)
    {
        long long s,e,c;
        cin>>s>>e>>c;
        adj[s-1][e-1]=c;
    }
    long long ans=0;
    long long tot=(1<<n)-1;
    for (long long i=0;i<=tot;i++)
        for (long long j=0;j<n;j++)
            dp[i][j]=-INF;
    for (long long i=0;i<n;i++)
        dp[(1<<i)][i]=a[i];
    for (long long x=1;x<=tot;x++)
    {
        long long num=0;
        long long h=x;
        for (long long i=0;i<n;i++)
        {
            long long u=h%2;
            h/=2;
            if (u)
            {
                num++;
                for (long long j=0;j<n;j++)
                {
                    dp[x][i]=max(dp[x][i],dp[x-(1<<i)][j]+adj[j][i]+a[i]);
                }
            }
        }
        if (num==m)
        {
            for (long long i=0;i<n;i++)
                ans=max(ans,dp[x][i]);
        }
    }
    cout<<ans<<endl;
}