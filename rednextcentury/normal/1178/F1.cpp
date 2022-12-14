#include <bits/stdc++.h>
using namespace std;
long long dp[555][555];
int mn[555][555];
long long mod=998244353;
int a[1000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i],dp[i][i]=1,dp[i][i-1]=1,dp[i+1][i]=1;
        mn[i][i]=i;
        for (int j=i+1;j<=n;j++)
            mn[i][j]=(a[j]<a[mn[i][j-1]])?j:mn[i][j-1];
    }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            mn[i][j]=(a[j]<a[mn[i][j-1]])?j:mn[i][j-1];
    for (int i=2;i<=n;i++)
    {
        for (int l=1;l+i-1<=n;l++)
        {
            int r = i+l-1;
            int c = mn[l][r];
            long long L=0,R=0;
            for (int j=c;j>=l;j--)
                L+=(dp[l][j-1]*dp[j][c-1])%mod,L%=mod;
            for (int j=c;j<=r;j++)
                R+=(dp[c+1][j]*dp[j+1][r])%mod,R%=mod;
            dp[l][r]=(L*R)%mod;
        }
    }
    cout<<dp[1][n]<<endl;


}