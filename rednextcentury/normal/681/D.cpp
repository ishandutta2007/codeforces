#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000000];
vector<int> adj2[1000000];
bool is[1000000];
int a[1000000];
bool ok = true;
bool vis[1000000];
int deg2[1000000];
void dfs(int v,int last)
{
    vis[v]=1;
    if (is[v])
    {
        if (last!=-1)
            adj2[v].push_back(last);
        last = v;
    }
    if (a[v]!=last)ok=0;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        dfs(u,last);
    }
}
queue<int> Q;
vector<int> topo;
int deg[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int p,q;
        cin>>p>>q;
        adj[p].push_back(q);
        deg2[q]++;
    }
    int num=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (!is[a[i]])num++;
        is[a[i]]=1;
    }
    for (int i=1;i<=n;i++)
        if (!vis[i] && deg2[i]==0)
            dfs(i,-1);
    if (!ok)
    {
        cout<<-1<<endl;
        return 0;
    }
    for (int i=1;i<=n;i++)
        for (int j=0;j<adj2[i].size();j++)
            deg[adj2[i][j]]++;
    for (int i=1;i<=n;i++)
    {
        if (is[i] && deg[i]==0)
            Q.push(i);
    }
    for (int i=0;i<num;i++)
    {
        if (Q.empty())
        {
            cout<<-1<<endl;
            return 0;
        }
        int v = Q.front();
        Q.pop();
        topo.push_back(v);
        for (int j=0;j<adj2[v].size();j++)
        {
            if(--deg[adj2[v][j]]==0)
                Q.push(adj2[v][j]);
        }
    }
    cout<<num<<endl;
    for (int i=0;i<num;i++)
        cout<<topo[i]<<endl;
}