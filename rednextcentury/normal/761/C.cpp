#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dp[100][10];
int main()
{
    fast
    int n,m;
    cin>>n>>m;
    dp[0][0]=0;
    for (int j=1;j<8;j++)dp[0][j]=1000000;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<8;j++)
            dp[i][j]=1000000;
    }
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int cost=0;
        dp[i][0]=0;
        for (int j=0;j<s.size();j++)
        {
            cost=min(j,(int)s.size()-j);
            int cur;
            if (s[j]>='0' && s[j]<='9')
                cur=1;
            else if (s[j]>='a' && s[j]<='z')
                cur=2;
            else if (s[j]=='#' || s[j]=='*' || s[j]=='&')
                cur=4;
            else continue;
            for (int x=0;x<8;x++)
            {
                dp[i][x]=min(dp[i][x],dp[i-1][x]);
                if (x&cur)continue;
                dp[i][x+cur]=min(dp[i-1][x]+cost,dp[i][x+cur]);
            }
        }
    }
    cout<<dp[n][7]<<endl;
}