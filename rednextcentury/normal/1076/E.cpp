#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid (l+r)/2
#define L (x<<1)
#define R (L+1)
ll tree[4000000];
void upd(int x,int l,int r,int v,int val){
    if (l==r)tree[x]+=val;
    else {
        if (v<=mid)upd(L,l,mid,v,val);
        else upd(R,mid+1,r,v,val);
        tree[x]=tree[L]+tree[R];
    }
}
ll Q(int x,int l,int r,int s,int e){
    if (l>e || r<s)return 0;
    if (l>=s && r<=e)return tree[x];
    return Q(L,l,mid,s,e)+Q(R,mid+1,r,s,e);
}
vector<int> adj[1000000];
vector<pair<int,int> > q[1000000];
ll val[1000000];
int n;
void dfs(int v,int p,int lev){
    for (auto x:q[v]){
        upd(1,0,2*n,lev,x.second);
        upd(1,0,2*n,lev+x.first+1,-x.second);
    }
    val[v] = Q(1,0,2*n,0,lev);
    for (auto u:adj[v]){
        if (u==p)continue;
        dfs(u,v,lev+1);
    }
    for (auto x:q[v]){
        upd(1,0,2*n,lev,-x.second);
        upd(1,0,2*n,lev+x.first+1,x.second);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int m;
    cin>>m;
    while(m--){
        int v,d,x;
        cin>>v>>d>>x;
        q[v].push_back({d,x});
    }
    dfs(1,-1,0);
    for (int i=1;i<=n;i++)cout<<val[i]<<' ';
}