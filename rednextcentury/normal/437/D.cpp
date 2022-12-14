#include <bits/stdc++.h>
using namespace std;
pair<long long,int> a[1000000];
vector<int> adj[1000000];
bool added[1000000];
vector<int> groups[1000000];
int group[1000000];
long long tot =0;
void dsu(int u,int v)
{
    for (int i=0;i<groups[u].size();i++)
    {
        groups[v].push_back(groups[u][i]);
        group[groups[u][i]]=v;
    }
    groups[u].clear();
}
void add_edge(int x,int y , long long val)
{
    int u = group[x] , v = group[y];
    if (u==v)return;
    long long sz1 = groups[u].size() , sz2 = groups[v].size();
    tot+=2*sz1*sz2*val;
    if (groups[u].size()<groups[v].size())
        dsu(u,v);
    else
        dsu(v,u);
}
int main()
{
    long long n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i].first, a[i].second = i , group[i]=i,groups[i].push_back(i);
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sort(a+1,a+n+1,greater<pair<long long,int> >());
    for (int i=1;i<=n;i++)
    {
        int u = a[i].second;
        for (int j=0;j<adj[u].size();j++)
        {
            int v = adj[u][j];
            if (!added[v])continue;
            add_edge(u,v,a[i].first);
        }
        added[u]=1;
    }
    long double ret = tot;
    ret/=n*(n-1)*1.0;
    cout<<setprecision(10)<<fixed<<ret<<endl;
}