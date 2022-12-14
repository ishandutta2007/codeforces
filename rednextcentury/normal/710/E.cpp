#include<bits/stdc++.h>
using namespace std;
long long dp[10000009];
deque<int> q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    long long x,y;
    cin>>n>>x>>y;
    dp[0]=0;
    for (int i=1;i<=n;i++)dp[i]=1e18;
    for (int i=0;i<n;i++)
    {
       if (i)
       {
           if (i*2<=n)
            dp[i*2]=min(dp[i*2],dp[i]+y);
           if (i*2-1<=n)
            dp[i*2-1]=min(dp[i*2-1],dp[i]+y+x);
       }
       dp[i+1]=min(dp[i+1],dp[i]+x);
    }
    cout<<dp[n]<<endl;
}