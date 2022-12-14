#include <bits/stdc++.h>
using namespace std;
int col[1000000];
bool vis[1000000];
vector<int> adj[1000000];
int num[10];
long long mod = 998244353;
bool ok;
long long P(long long a,long long b)
{
    if (b==0)return 1;
    long long x = P(a,b/2);
    x = (x*x)%mod;
    if (b%2)x=(x*a)%mod;
    return x;
}
void dfs(int v,int c)
{
    col[v]=c;
    vis[v]=1;
    num[c]++;
    for (auto u:adj[v])
    {
        if (vis[u] && col[v]==col[u])
            ok=0;
        if (!vis[u])dfs(u,1-c);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        ok=true;
        num[0]=num[1]=num[2]=0;
        for (int i=1;i<=n;i++)
            col[i]=0,adj[i].clear(),vis[i]=0;
        for (int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ret=1;
        for (int i=1;i<=n;i++)
        {
            if (!vis[i])
            {
                num[0]=0,num[1]=0;
                dfs(i,1);
                ret*=((P(2,num[1])+P(2,num[0]))%mod);
                ret%=mod;
            }
        }
        if (ok)cout<<ret<<endl;
        else cout<<0<<endl;
    }
}