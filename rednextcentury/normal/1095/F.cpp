#include<bits/stdc++.h>
using namespace std;
vector<int> G[1000000];
vector<pair<long long,pair<int,int> > > E;
int group[1000000];
long long ret=0;
void add(int u,int v)
{
    for (auto x:G[u])
    {
        group[x]=v;
        G[v].push_back(x);
    }
}
void dsu(int x,int y,long long w)
{
    x=group[x],y=group[y];
    if (x==y)return;
    ret+=w;
    if (G[x].size()<G[y].size())add(x,y);
    else add(y,x);
}
pair<long long,int> a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i].first,a[i].second=i,group[i]=i,G[i].push_back(i);
    sort(a+1,a+n+1);
    for (int i=2;i<=n;i++)
        E.push_back({a[i].first+a[1].first,{a[i].second,a[1].second}});
    while(m--)
    {
        int u,v;
        long long w;
        cin>>u>>v>>w;
        E.push_back({w,{u,v}});
    }
    sort(E.begin(),E.end());
    for (auto e:E)
        dsu(e.second.first,e.second.second,e.first);
    cout<<ret<<endl;
}