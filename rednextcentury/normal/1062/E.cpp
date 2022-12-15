#include <bits/stdc++.h>
using namespace std;
int in[1000000];
int vin[1000000];
int ain[1000000];
pair<int,int> tree[1000000];
pair<int,int> Merge(pair<int,int> a,pair<int,int> b)
{
    int A[4]={a.first,a.second,b.first,b.second};
    sort(A,A+4);
    return {A[0],A[1]};
}
void build(int x,int l,int r)
{
    if (l==r)
        tree[x]={ain[l],1000000};
    else
    {
        build(x*2,l,(l+r)/2);
        build(x*2+1,(l+r)/2+1,r);
        tree[x]=Merge(tree[x*2],tree[x*2+1]);
    }
}
pair<int,int> query(int x,int l,int r,int s,int e)
{
    if (s>r || e<l)
    return {1000000,1000000};
    if (l>=s && r<=e)
        return tree[x];
    return Merge(query(x*2,l,(l+r)/2,s,e),query(x*2+1,(l+r)/2+1,r,s,e));
}
vector<int> adj[1000000];
int cur=1;
int l[1000000];
void dfs(int v,int lev=0)
{
    l[v]=lev;
    vin[cur]=v;
    in[v]=cur++;
    for (auto u:adj[v])
        dfs(u,lev+1);
}
int p[1000000][21];
int LCA(int u,int v)
{
    if (l[u]<l[v])swap(u,v);
    int need = l[u]-l[v];
    for (int i=20;i>=0;i--)
        if ((1<<i)&need)
            u=p[u][i];
    if (u==v)return u;
    for (int i=20;i>=0;i--)
        if (p[v][i]!=p[u][i])
            u=p[u][i],v=p[v][i];
    return p[u][0];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=2;i<=n;i++)
    {
        cin>>p[i][0];
        adj[p[i][0]].push_back(i);
    }
    for (int i=1;i<=20;i++)
        for (int j=1;j<=n;j++)
            p[j][i]=p[p[j][i-1]][i-1];
    dfs(1);
    for (int i=1;i<=n;i++)
        ain[i]=in[i],ain[i+n]=-in[i];
    build(1,1,2*n);
    for (int i=0;i<q;i++)
    {
        int ll,rr;
        cin>>ll>>rr;
        pair<int,int> L = query(1,1,2*n,ll,rr);
        pair<int,int> R = query(1,1,2*n,ll+n,rr+n);
        L.first = vin[L.first] , L.second = vin[L.second];
        R.first = vin[-R.first] , R.second = vin[-R.second];
        int LCA1 = LCA(L.first,R.second);
        int LCA2 = LCA(L.second,R.first);
        if (l[LCA1]>l[LCA2])
        {
            cout<<R.first<<' '<<l[LCA1]<<endl;
        }
        else
            cout<<L.first<<' '<<l[LCA2]<<endl;
    }
}