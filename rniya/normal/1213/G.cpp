#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind{
    int num;
    vector<int> par,rank;
    UnionFind(int n):num(n),par(n),rank(n,1){
        iota(par.begin(),par.end(),0);
    }
    int root(int x){
        if (par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    bool merge(int x, int y){
        x=root(x),y=root(y);
        if (x==y) return false;
        if (rank[x]<rank[y]) swap(x,y);
        par[y]=x;
        rank[x]+=rank[y];
        --num;
        return true;
    }
    bool same(int x, int y){
        return root(x)==root(y);
    }
    int sz(int x){
        return rank[root(x)];
    }
    int count(){
        return num;
    }
};

ll f(ll x){return x*(x-1)/2;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<pair<int,pair<int,int>>> G;
    for (int i=0;i<n-1;++i){
        int u,v,w; cin >> u >> v >> w;
        G.push_back({w,{--u,--v}});
    }
    sort(G.begin(),G.end());
    vector<int> ws(n);
    vector<ll> ans(n);
    UnionFind uf(n);
    ll now=0; ws[0]=ans[0]=0;
    for (int i=0;i<n-1;++i){
        ws[i+1]=G[i].first;
        int u=G[i].second.first,v=G[i].second.second;
        now-=f((ll)uf.sz(u));
        if (!uf.same(u,v)) now-=f((ll)uf.sz(v));
        uf.merge(u,v); now+=f((ll)uf.sz(u));
        ans[i+1]=now;
    }
    for (int i=0;i<m;++i){
        int q; cin >> q;
        int pos=upper_bound(ws.begin(),ws.end(),q)-ws.begin();
        cout << ans[pos-1] << (i+1==m?'\n':' ');
    }
}