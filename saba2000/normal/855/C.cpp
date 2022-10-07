#include<bits/stdc++.h>
using namespace std;
long long n,m,k,X;
long long M=1000000007;
long long dp[100009][19];
long long dp1[100009][19];
long long dp0[100009][19];
long long f[100009];
vector<long long> v[100009];
long long dfs(long long x)
{
    f[x]=1;
    dp0[x][0]=k-1;
    dp[x][0]=m-k;
    dp1[x][1]=1;
    long long r[19]={0};
    for (long long i=0; i<v[x].size(); i++)
    {
        if(f[v[x][i]]) continue;
        dfs(v[x][i]);
        long long r0[19]={0},r1[19]={0},r[19]={0};
        for (long long j=0; j<=X; j++){
            for (long long p=0; p<=j; p++){
                r0[j]=(r0[j]+dp0[x][p]*(dp0[v[x][i]][j-p]+dp[v[x][i]][j-p]+dp1[v[x][i]][j-p]))%M;
                r1[j]=(r1[j]+dp1[x][p]*dp0[v[x][i]][j-p])%M;
                r[j]=(r[j]+dp[x][p]*(dp0[v[x][i]][j-p]+dp[v[x][i]][j-p]))%M;
//cout<<x<<"  "<<j<<" "<<p<<" "<<v[x][i]<<" "<<dp0[x][p]<<" "<<(dp0[v[x][i]][j-p]+dp[v[x][i]][j-p]+dp1[v[x][i]][j-p])<<" "<<r0[j]<<endl;
                }

        }
        for (long long j=0; j<=X; j++)
        {
            dp0[x][j]=r0[j];
            dp1[x][j]=r1[j];
            dp[x][j]=r[j];

        }

    }
   //
    //    {dp0[x][j]+=dp[x][j];
      //  dp[x][j]=dp0[x][j]+dp1[x][j];}
     // for (long long j=0; j<=X; j++)
      //  cout<<x<<" "<<j<<" "<<dp0[x][j]<<" "<<dp1[x][j]<<" "<<dp[x][j]<<endl;
}
main()
{cin>>n>>m;
for(long long i=0; i<n-1; i++)
{
    long long a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}
cin>>k>>X;
dfs(1);
long long ans=0;
for (long long i=0; i<=X; i++)
   {
    ans=(ans+dp[1][i]+dp1[1][i]+dp0[1][i])%M;
   // cout<<dp[1][i]<<" "<<dp1[1][i]<<" "<<dp0[1][i]<<endl;
   }
cout<<ans<<endl;
}