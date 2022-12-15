#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
const int inf=1e12;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vector dp(n+1,vector(n+1,vector<int>(n+1,-inf)));
    vector pre(n+1,vector<int>(n+1));
    vector pre2(n+1,vector<int>(n+1));
    dp[1][1][0]=a[1];
    dp[1][2][1]=a[2];
    int ans=max(a[1],a[2]);
    for(int i=2;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            for(int k=0;k<=n;++k)
            {
                pre[j][k]=dp[i-1][j][k];
                if(k>0) pre[j][k]=max(pre[j][k],pre[j][k-1]);
                pre2[j][k]=dp[i-1][j][k];
                if(j>0) pre2[j][k]=max(pre2[j][k],pre2[j-1][k]);
            }
        }
        for(int j=1;j<=n;++j)
        {
            for(int k=0;k<=i;++k)
            {
                if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[j]);
                if(i>j)
                {
                    if(k>=1) dp[i][j][k]=max(dp[i][j][k],pre2[j-1][k-1]+a[j]);
                }
                else
                {
                    //dp[i][j][k]=max(dp[i-1][1][k-(j-i)],dp[i-1][2][k-(j-i)],)
                    if(k>=j-i) dp[i][j][k]=max(dp[i][j][k],pre2[j-1][k-(j-i)]+a[j]);
                }
                // for(int jj=1;jj<j;++jj)
                // {
                //     int tmp=1;
                //     if(j>=i) tmp=j-i;
                //     if(k>=tmp)
                //     dp[i][j][k]=max(dp[i][j][k],dp[i-1][jj][k-tmp]+a[j]);
                // }
                // cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<"!!"<<endl;
                ans=max(ans,dp[i][j][k]);
            }
        }
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;//cin>>T;
    while(T--) solve();
    return 0;
}