#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
bool vis[1000000];
vector<int> adj[1000000];
void dfs(int v)
{
    vis[v]=1;
    vec.push_back(v);
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        dfs(u);
        vec.push_back(v);
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int num=(2*n)/k + ((2*n)%k>0);
    int cur=0;
    for (int i=1;i<=k;i++)
    {
        int ret=min(num,(int)vec.size()-cur);
        if (ret==0)
            cout<<1<<' '<<1<<endl;
        else{
        cout<<ret;
        for (int i=0;i<ret;i++)
        {
            cout<<' '<<vec[cur];
            cur++;
        }
        cout<<endl;
        }
    }
}