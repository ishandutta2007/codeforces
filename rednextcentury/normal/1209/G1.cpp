#include<bits/stdc++.h>
using namespace std;
vector<int> G[1000000];
int group[1000000];
int sz[1000000];
int L[1000000];
int R[1000000];
long long ret=0;
void add(int u,int v)
{
    for (auto x:G[u])
    {
        G[v].push_back(x);
        group[x]=v;
    }
    ret+=min(sz[u],sz[v]);
    sz[v]=max(sz[v],sz[u]);
    R[v]=max(R[v],R[u]);
    L[v]=min(L[v],L[u]);
    G[u].clear();
}
int dsu(int u,int v)
{
    if (u==v)return v;
    if (G[u].size()<G[v].size())
    {
        add(u,v);
        return v;
    }
    else
    {
        add(v,u);
        return u;
    }
}
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        group[i]=a[i];
        G[a[i]].push_back(i);
        if (L[a[i]]==0)L[a[i]]=i;
        R[a[i]]=i;
        sz[a[i]]++;
    }
    for (int i=1;i<=n;)
    {
        int cur = group[i];
        int j=i;
        while(j<=R[cur])
        {
            cur=dsu(cur,group[j]);
            j++;
        }
        i=j;
    }
    cout<<ret<<endl;
}