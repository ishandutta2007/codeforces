#include <bits/stdc++.h>

using namespace std;
int a[1000000];
vector<pair<int,int> > adj[1000000];
int app[1000000];
int n;
int b[1000000];
int tot=1;
bool vis[1000000];
bool bfs(int v)
{
    queue<int> q;
    q.push(v);
    vis[1]=1;
    while(!q.empty())
    {
        v=q.front();
        q.pop();
        b[tot++]=v;
        for (int i=0;i<adj[v].size();i++)
        {
            int u=adj[v][i].second;
            if (vis[u])continue;
            q.push(u);
            vis[u]=1;
        }
    }
    for (int i=1;i<=n;i++)
        if (a[i]!=b[i])return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back({0,y});
        adj[y].push_back({0,x});
    }
    for (int i=1;i<=n;i++)
        cin>>a[i],app[a[i]]=i;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<adj[i].size();j++)
            adj[i][j].first = app[adj[i][j].second];
        sort(adj[i].begin(),adj[i].end());
    }
    if (bfs(1))
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}