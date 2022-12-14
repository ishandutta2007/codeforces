#include<bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long P(long long a,long long b)
{
    if (b==0)return 1;
    long long x = P(a,b/2);
    x=(x*x)%mod;
    if (b%2)x=(x*a)%mod;
    return x;
}
long long sz=0;
bool vis[1000000];
vector<int> adj[1000000];
void dfs(int v)
{
    vis[v]=1;sz++;
    for (auto u:adj[v]){
        if (vis[u])continue;
        dfs(u);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    long long n,k;
    cin>>n>>k;
    for (int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        if (w==0)adj[u].push_back(v),adj[v].push_back(u);
    }
    long long ret = P(n,k);
    for (int i=1;i<=n;i++)
    {
        sz=0;
        if (!vis[i])
        {
            dfs(i);
            long long x=P(sz,k);
            ret=(ret-x+mod)%mod;
        }
    }
    cout<<ret<<endl;
}