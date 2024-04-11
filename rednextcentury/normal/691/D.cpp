
 #include <bits/stdc++.h>
using namespace std;
vector<int> adj[1010000];
int a[1000010];
int ret[1000010];
vector<int> id,val;
bool vis[1000100];
void dfs(int v)
{
    vis[v]=1;
    id.push_back(v);
    val.push_back(a[v]);
    for (auto u:adj[v])
        if (!vis[u])
            dfs(u);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            id.clear(),val.clear();
            dfs(i);
            sort(id.begin(),id.end());
            sort(val.begin(),val.end());
            reverse(val.begin(),val.end());
            for (int j=0;j<id.size();j++)
                ret[id[j]]=val[j];
        }
    }
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<' ';
}