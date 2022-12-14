#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dp[1000000];
int t[1000000];
int main()
{
    fast_io
    int n;
    cin>>n;
    dp[0]=0;
    t[0]=-10000000;
    for (int i=1;i<=n;i++)
    {
        cin>>t[i];
        int c1,c2,c3;
        int x=i;
        for (int j=20;j>=0;j--)
        {
            if (x-(1<<j)<0) continue;
            if (t[x-(1<<j)]>=t[i]-89)
                x-=(1<<j);
        }
        c1=dp[x-1]+50;
        x=i;
        for (int j=20;j>=0;j--)
        {
            if (x-(1<<j)<0) continue;
            if (t[x-(1<<j)]>=t[i]-1439)
                x-=(1<<j);
        }
        c2=dp[x-1]+120;
        c3=dp[i-1]+20;
        dp[i]=min(c1,min(c2,c3));
        cout<<dp[i]-dp[i-1]<<endl;
    }
}