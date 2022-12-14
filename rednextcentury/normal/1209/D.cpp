#include<bits/stdc++.h>
using namespace std;
int sz=0;
bool vis[1000000];
vector<int> adj[1000000];
void dfs(int v)
{
    vis[v]=1;
    sz++;
    for (auto u:adj[v])
    {
        if (vis[u])continue;
        dfs(u);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ret=0;
    for (int i=1;i<=n;i++){
        if (vis[i]==0)
        {
            sz=0;
            dfs(i);
            ret+=sz-1;
        }
    }
    cout<<k-ret<<endl;
}