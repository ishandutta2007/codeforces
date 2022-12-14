#include <bits/stdc++.h>
using namespace std;
int group[1000000];
vector<int> G[1000000];
int n;
void add(int u,int v)
{
    for (auto x:G[u])
    {
        G[v].push_back(x);
        group[x]=v;
    }
    G[u].clear();
}
void dsu(int x,int y)
{
    int u=group[x];
    int v=group[y];
    if (u==v)return;
    if (G[u].size()<G[v].size())
        add(u,v);
    else add(v,u);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        G[i].push_back(i),group[i]=i;
    for (int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        dsu(u,v);
    }
    for (auto x:G[group[1]])
        cout<<x<<' ';
}