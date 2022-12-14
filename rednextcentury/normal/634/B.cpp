#include<bits/stdc++.h>
using namespace std;
int x[1000000];
int s[1000000];
bool vis[1000][2];
long long dp[1001][2];
long long DP(int i,int m)
{
    if (i==40)
        return m==0;
    if (vis[i][m])return dp[i][m];
    vis[i][m]=1,dp[i][m]=0;
    if (x[i]==1)
    {
        if ((m+1)%2!=s[i])
            return dp[i][m]=0;
        else
            return dp[i][m]=2*DP(i+1,(m+1)/2);
    }
    else
    {
        if (m%2==s[i])
            dp[i][m]+=DP(i+1,0);
        if ((m+2)%2==s[i])
            dp[i][m]+=DP(i+1,(m+2)/2);
        return dp[i][m];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,m;
    cin>>n>>m;
    int k=0;
    if (n==m)k-=2;
    int h=0;
    while(n)
    {
        s[h++]=n%2;
        n/=2;
    }
    h=0;
    while(m)
    {
        x[h++]=m%2;
        m/=2;
    }

    cout<<DP(0,0)+k<<endl;
}