# include <iostream>
# include <algorithm>
# include <ios>
# include <stdio.h>
using namespace std;
int dp[1000001];
int a[1000001];
int is[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int m;
    cin>>m;
    int ans=0;
    for (int i=0;i<m;i++)
        cin>>a[i],is[a[i]]=1;
    for (int i=0;i<m;i++)
    {
        dp[a[i]]=max(dp[a[i]],1);
        ans=max(ans,dp[a[i]]);
        for (int j=2;;j++)
        {
            if (a[i]*j>1000000)
                break;
            if (is[a[i]])
            dp[a[i]*j]=max(dp[a[i]]+1,dp[a[i]*j]);
        }
    }
    cout<<ans<<endl;
}