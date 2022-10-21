#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct Kruskal{
    struct edge{
        int from,to,used; T cost;
        edge(int from,int to,T cost):
            from(from),to(to),cost(cost),used(0){}
        bool operator<(const edge &e) const{
            if (cost!=e.cost) return cost<e.cost;
            else if (from!=e.from) return from<e.from;
            else return to<e.to;
        }
    };
    int num;
    vector<int> par,rank;
    vector<edge> es;
    Kruskal(int n):num(n),par(n),rank(n,1){
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
    int size(int x){
        return rank[root(x)];
    }
    int count(){
        return num;
    }
    void add_edge(int u,int v,T c){
        es.emplace_back(u,v,c);
    }
    T build(){
        sort(es.begin(),es.end());
        T res=0;
        for (auto &e:es){
            if (!same(e.from,e.to)){
                res+=e.cost;
                merge(e.from,e.to);
                e.used=1;
            }
        }
        return res;
    }
    vector<int> used_es(T &c){
        int E=es.size();
        map<edge,int> m;
        for (int i=0;i<E;++i) m[es[i]]=i;
        c=build();
        vector<int> list(E);
        for (int i=0;i<E;++i) list[m[es[i]]]=es[i].used;
        return list;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<ll> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    Kruskal<ll> K(n);
    int center=min_element(a.begin(),a.end())-a.begin();
    for (int i=0;i<n;++i) if (i!=center){
        K.add_edge(center,i,a[center]+a[i]);
    }
    for (int i=0;i<m;++i){
        int x,y; ll w; cin >> x >> y >> w;
        K.add_edge(--x,--y,w);
    }
    cout << K.build() << '\n';
}