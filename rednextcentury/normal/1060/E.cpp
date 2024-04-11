#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
long long totalSum=0;
long long oddPaths=0;
long long subtree[1000000];
int dep[1000000];
long long num[1000000][2];
vector<int> adj[1000000];
bool vis[1000000];
int pa[1000000];
int n;
void dfs(int v)
{
    vis[v]=1;
    subtree[v]=1;
    for (auto u:adj[v])
    {
        if (vis[u])continue;
        dep[u]=dep[v]+1;
        pa[u]=v;
        dfs(u);
        subtree[v]+=subtree[u];
        num[v][0]+=num[u][0];
        num[v][1]+=num[u][1];
    }
    totalSum+=(subtree[v]*(n-subtree[v]));
    for (auto u:adj[v])
    {
        if (u==pa[v])continue;
        oddPaths+=(num[v][0]-num[u][0])*num[u][1];
    }
    num[v][dep[v]%2]++;
    oddPaths+=num[v][1-(dep[v]%2)];
}
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout<<(totalSum-oddPaths)/2+oddPaths<<endl;
}