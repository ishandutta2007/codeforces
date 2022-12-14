#include <bits/stdc++.h>
using namespace std;
vector<pair<int,long long> > adj[1000000];
long long w[1000000];
long long best[1000000][2];
long long ret=0;
void dfs(int v,int pa)
{
    for (auto p:adj[v])
    {
        int u=p.first;
        long long x = p.second;
        if (u==pa)continue;
        dfs(u,v);
        long long cur = best[u][0]-x;
        cur=max(cur,0LL);
        if (cur>best[v][0])
            best[v][1]=best[v][0],best[v][0]=cur;
        else if (cur>best[v][1])
            best[v][1]=cur;
    }
    ret=max(ret,best[v][0]+best[v][1]+w[v]);
    best[v][0]+=w[v];
    best[v][1]+=w[v];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>w[i];
    for (int i=2;i<=n;i++)
    {
        int u,v,x;
        cin>>u>>v>>x;
        adj[u].push_back({v,x});
        adj[v].push_back({u,x});
    }
    dfs(1,-1);
    cout<<ret<<endl;
}