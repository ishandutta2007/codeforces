#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int c[N],dp[N][2];
int n;
string a[N],b[N];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        reverse(b[i].begin(),b[i].end());
    }
    memset(dp,-1,sizeof(dp));
    dp[1][1]=c[1];
    dp[1][0]=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>=a[i-1]&&dp[i-1][0]!=-1)
        dp[i][0]=dp[i-1][0];
        if(a[i]>=b[i-1]&&dp[i-1][1]!=-1)
        {
            if(dp[i][0]!=-1)
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
            else
            dp[i][0]=dp[i-1][1];
        }
        if(b[i]>=a[i-1]&&dp[i-1][0]!=-1)
        dp[i][1]=dp[i-1][0]+c[i];
        if(b[i]>=b[i-1]&&dp[i-1][1]!=-1)
        {
            if(dp[i][1]!=-1)
            {
                dp[i][1]=min(dp[i-1][1],dp[i][1]-c[i])+c[i];
            }
            else
            dp[i][1]=dp[i-1][1]+c[i];
        }
        if(dp[i][0]==-1&&dp[i][1]==-1)break;
    }
    if(dp[n][0]==-1&&dp[n][1]==-1)
    printf("-1\n");
    else if(dp[n][0]!=-1&&dp[n][1]!=-1)cout<<min(dp[n][0],dp[n][1])<<endl;
    else if(dp[n][0]==-1)cout<<dp[n][1]<<endl;
    else cout<<dp[n][0]<<endl;
}