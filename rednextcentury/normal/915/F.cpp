#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int,pair<int,int> >  > E;
int n;
int group[1000100];
vector<int> G[1000100];
long long cur=0;
void add(int u,int v)
{
    for (auto x:G[u]){
        G[v].push_back(x);
        group[x]=v;
    }
    G[u].clear();
}
void dsu(long long c,int u,int v)
{
    u=group[u];
    v=group[v];
    if (u==v)return;
    cur+=(G[u].size()*1LL*G[v].size())*1LL*c;
    if (G[u].size()<G[v].size())add(u,v);
    else add(v,u);
}
long long Solve()
{
    cur=0;
    for (int i=1;i<=n;i++) {
        G[i].clear();G[i].push_back(i);
        group[i]=i;
    }
    for (auto e:E) {
        dsu(e.first,e.second.first,e.second.second);
    }
    return cur;
}
vector<pair<int,int> > edges;
int a[1000500];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    for (int i=0;i+1<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        edges.push_back({u,v});
    }
    for (auto p:edges) {
        E.push_back({min(a[p.first],a[p.second]),p});
    }
    sort(E.begin(),E.end());
    reverse(E.begin(),E.end());
    long long ret = -Solve();
    E.clear();
    for (auto p:edges) {
        E.push_back({max(a[p.first],a[p.second]),p});
    }
    sort(E.begin(),E.end());
    ret+=Solve();
    printf("%lld\n",ret);
}