#include<bits/stdc++.h>
#define ll long long
using namespace std;
int in_stack[1000000];
int vis[1000000];
bool cycle=0;
int T=0;
vector<int> adj[1000000];
int col[1000000];
void dfs(int v)
{
    vis[v]=T;in_stack[v]=T;
    for (auto u:adj[v])
    {
        if (vis[u]==T && in_stack[u]==T)cycle=1;
        if (vis[u]==T)continue;
        dfs(u);
    }
    in_stack[v]=0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    bool ok=0;
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        T++;
        cycle=0;
        for (int j=1;j<=n;j++)
            if (vis[j]!=T)dfs(j);
        if (cycle)adj[u].pop_back(),col[i]=2,ok=1;
        else col[i]=1;
    }
    if (ok)cout<<2<<endl;
    else cout<<1<<endl;
    for (int i=0;i<m;i++)cout<<col[i]<<' ';
    cout<<endl;

}