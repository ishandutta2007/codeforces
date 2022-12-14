#include <bits/stdc++.h>

using namespace std;
#pragma comment(linker, "/STACK: 2000000")
long long a[1000000];
vector<int> adj[1000000];
bool vis[1000000];
long long dp[1000000];
long long can[1000000];
bool c;
long long GCD(long long a,long long b)
{
    if (a%b==0)return b;
    if (b%a==0)return a;
    return GCD(b%a,a);
}
long long LCM(long long a,long long b)
{
    if (a==0 || b==0)return 0;
    return a*(b/GCD(a,b));
}
void dfs(int v)
{
    vis[v]=1;
    int x=0;
    dp[v]=-1;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        dfs(u);
        x++;
        if (dp[v]==-1)dp[v]=dp[u],can[v]=can[u];
        else
        {
            can[v]=LCM(can[v],can[u]);
            if (can[v]==0)
            {
                c=1;
            }
            else
            dp[v]=min(can[v]*(dp[v]/can[v]),can[v]*(dp[u]/can[v]));
        }
    }
    if (x!=0)
        dp[v]*=x;
    if (x!=0)
        can[v]*=x;
    if (dp[v]==-1)dp[v]=a[v],can[v]=1;
}
int main()
{
    int n;
    cin>>n;
    c=0;
    long long sum=0;
    for (int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    if (c)
    cout<<sum<<endl;
    else
    cout<<sum-dp[1]<<endl;
}