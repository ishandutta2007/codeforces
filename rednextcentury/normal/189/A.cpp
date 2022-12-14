#include<bits/stdc++.h>
using namespace std;
int dp[100000];
int main()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    for (int i=0;i<=n;i++)
        dp[i]=-1000000;
    dp[a]=dp[b]=dp[c]=1;
    for (int i=0;i<=n;i++)
    {
        if (i>=a)
            dp[i]=max(dp[i],dp[i-a]+1);
        if (i>=b)
            dp[i]=max(dp[i],dp[i-b]+1);
        if (i>=c)
            dp[i]=max(dp[i],dp[i-c]+1);
    }
    cout<<dp[n]<<endl;
}