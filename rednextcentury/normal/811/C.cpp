#include <bits/stdc++.h>

using namespace std;
int s[10000];
int e[10000];
bool vis[5001][5001];
int dp[5001];
int a[10000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (s[a[i]]==0)
            s[a[i]]=e[a[i]]=i;
        else
            s[a[i]]=min(s[a[i]],i),e[a[i]]=max(e[a[i]],i);
    }
    dp[0]=0;
    for (int i=1;i<=n;i++)
    {
        int mn=s[a[i]],mx=e[a[i]];
        int com=a[i];
        vis[i][a[i]]=1;
        if (mn==i && mx==i)
            dp[i]=dp[i-1]+com;
        for (int j=i-1;j>=1;j--)
        {
            mn=min(mn,s[a[j]]);
            mx=max(mx,e[a[j]]);
            if (!vis[i][a[j]])
                com^=a[j];
            vis[i][a[j]]=1;
            if (mn>=j && mx<=i)
                dp[i]=max(dp[j-1]+com,dp[i]);
        }
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout<<dp[n]<<endl;
}