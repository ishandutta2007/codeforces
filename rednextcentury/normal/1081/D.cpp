#include <bits/stdc++.h>
using namespace std;
vector<int> G[1000000];
int group[1000000];
int spec[1000000];
int has[1000000];
int ret;
int k;
void Merge(int u,int v,int w)
{
    for (int i=0;i<G[u].size();i++)
    {
        G[v].push_back(G[u][i]);
        group[G[u][i]]=v;
    }
    has[v]+=has[u];
    if (has[v]==k && ret==-1)ret=w;
}
void dsu(int x,int y,int w)
{
    if (group[x]==group[y])return;
    int u=group[x],v=group[y];
    if (G[u].size()<G[v].size())
        Merge(u,v,w);
    else
        Merge(v,u,w);
}
pair<int,pair<int,int> > e[1000000];
int main()
{
    ret=-1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        G[i].push_back(i),group[i]=i;
    for (int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        has[x]=1;
    }
    for (int i=0;i<m;i++)
    {
        cin>>e[i].second.first>>e[i].second.second>>e[i].first;
    }
    sort(e,e+m);
    for (int i=0;i<m;i++)
        dsu(e[i].second.first,e[i].second.second,e[i].first);
    for (int i=0;i<k;i++)
        cout<<ret<<' ';
    cout<<endl;
}