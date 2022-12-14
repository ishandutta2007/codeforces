#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mid (l+r)/2
#define L x*2
#define R x*2+1
int group[1000000];
vector<int> G[1000000];
vector<int> groups[1000000];
vector<int> vec[1000000];
int ans[1000000];
void add(int u,int v)
{
    for (int i=0;i<G[u].size();i++)
    {
        G[v].push_back(G[u][i]);
        group[G[u][i]]=v;
    }
    G[u].clear();
}
void dsu(int u,int v)
{
    u = group[u];
    v = group[v];
    if (u==v)return;
    if (G[u].size()<G[v].size())
        add(u,v);
    else add(v,u);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int k;
        cin>>k;
        for (int j=0;j<k;j++)
        {
            int x;
            cin>>x;
            groups[x].push_back(i);
            vec[i].push_back(x);
        }
        group[i]=i;
        G[i].push_back(i);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<groups[i].size();j++)
            dsu(groups[i][j],groups[i][j-1]);
    for (int i=1;i<=m;i++)
    {
        set<int> s;
        for (auto x:G[i])
            for (auto y:vec[x])
                s.insert(y);
        for (auto x:s)
            ans[x]=s.size();
    }
    for (int i=1;i<=n;i++)
        cout<<max(ans[i],1)<<' ';
}