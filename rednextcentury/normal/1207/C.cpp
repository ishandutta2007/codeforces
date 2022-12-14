#include <bits/stdc++.h>
using namespace std;
long long dp[300000][2];
int vis[300000][2];
int T;
string s;
int n;
long long A,B;
long long DP(int i,int j)
{
    if (i==n)
    {
        if (j==0)return B;
        else return 1e15;
    }
    if (s[i]=='1' && j==0)return 1e15;
    if (vis[i][j]==T)
        return dp[i][j];
    dp[i][j]=1e15;
    vis[i][j]=T;
    long long cost = B*(j+1);
    if (s[i]!='1')
        dp[i][j]=min(dp[i][j],DP(i+1,0)+(j!=0)*A);
        dp[i][j]=min(dp[i][j],DP(i+1,1)+(j!=1)*A);
    dp[i][j]+=cost;
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>A>>B>>s;
        T++;
        cout<<DP(0,0)+n*A<<endl;
    }
}