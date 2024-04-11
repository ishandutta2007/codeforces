#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[1000000];
#define mid (l+r)/2
#define L (x<<1)
#define R (L+1)
int S[1000000];
int E[1000000];
int tree[4000000];
int m;
void build(int x,int l,int r){
    if (l==r)tree[x]=1;
    else {
        build(L,l,mid);
        build(R,mid+1,r);
        tree[x]=tree[L]+tree[R];
    }
}
int query(int x,int l,int r,int s,int e){
    if (l>e || r<s)return 0;
    if (l>=s && r<=e)return tree[x];
    return query(L,l,mid,s,e)+query(R,mid+1,r,s,e);
}
int get(int x,int l,int r,int k) {
    if (l==r)return l;
    if (tree[L]>=k)return get(L,l,mid,k);
    else return get(R,mid+1,r,k-tree[L]);
}
void upd(int x,int l,int r,int v){
    if (v>r || v<l)return;
    if (l==r)tree[x]=0;
    else {
        upd(L,l,mid,v);
        upd(R,mid+1,r,v);
        tree[x]=tree[L]+tree[R];
    }
}
void Fill(int x){
    upd(1,1,m,x);
}
int Get(int x,int s) {
    s++;
    return get(1,1,m,s+query(1,1,m,1,x));
}
void dfs(int v,int p=0){
    E[v] = Get(S[v],adj[v].size() - (p!=0));
    Fill(E[v]);
    int num=0;
    for (auto u:adj[v]) {
        if (u==p)continue;
        num++;
        S[u] = E[v] - num;
        Fill(S[u]);
        dfs(u,v);
    }
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    scanf("%d",&n);
    m=n*2;
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    build(1,1,m);
    S[1]=1;
    Fill(1);
    dfs(1);
    for (int i=1;i<=n;i++){
        printf("%d %d\n",S[i],E[i]);
    }
}