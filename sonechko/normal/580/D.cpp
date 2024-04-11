#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][270000];
ll a[20],b[20][20];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=k; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        b[l][r]=k;
    }
    int step=(1<<n)-1;
    for (int i=1; i<=n; i++)
    dp[i][(1<<(i-1))]=a[i];
    ll ans=0;
    for (int j=1; j<=step; j++)
    {
        int kol=0;
        for (int i=1; i<=n; i++)
            if ((j&(1<<(i-1)))>0) kol++;
        if (kol>m) continue;
        for (int i=1; i<=n; i++)
        {
            if (kol==m) ans=max(ans,dp[i][j]);
            if ((j&(1<<(i-1)))!=0)
                {
                    for (int p=1; p<=n; p++)
                        if ((j&(1<<(p-1)))==0) dp[p][j^(1<<(p-1))]=max(dp[p][j^(1<<(p-1))],dp[i][j]+a[p]+b[i][p]);
                }
        }
    }
    cout<<ans<<endl;
}