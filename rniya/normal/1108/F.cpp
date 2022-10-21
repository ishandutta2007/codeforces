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

template<typename Monoid,typename OperatorMonoid,typename F,typename G,typename H>
struct LazySegmentTree{
    int n,hi;
    F f;
    G g;
    H h;
    Monoid id0;
    OperatorMonoid id1;
    vector<Monoid> dat;
    vector<OperatorMonoid> laz;
    LazySegmentTree(int n_,F f,G g,H h,Monoid id0,OperatorMonoid id1):
                    f(f),g(g),h(h),id0(id0),id1(id1){init(n_);}
    void init(int n_){
        n=1,hi=0;
        while(n<n_) n<<=1,++hi;
        dat.assign(n<<1,id0);
        laz.assign(n<<1,id1);
    }
    void build(const vector<Monoid> &v){
        for (int i=0;i<v.size();++i) dat[i+n]=v[i];
        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
    }
    inline Monoid reflect(int k){
        return laz[k]==id1?dat[k]:g(dat[k],laz[k]);
    }
    inline void propagate(int k){
        if (laz[k]==id1) return;
        laz[k<<1|0]=h(laz[k<<1|0],laz[k]);
        laz[k<<1|1]=h(laz[k<<1|1],laz[k]);
        dat[k]=reflect(k);
        laz[k]=id1;
    }
    inline void thrust(int k){
        for (int i=hi;i;--i) propagate(k>>i);
    }
    inline void recalc(int k){
        while(k>>=1) dat[k]=f(reflect(k<<1|0),reflect(k<<1|1));
    }
    void update(int a,int b,OperatorMonoid x){
        if (a>=b) return;
        thrust(a+=n),thrust(b+=n-1);
        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if (l&1) laz[l]=h(laz[l],x),++l;
            if (r&1) --r,laz[r]=h(laz[r],x);
        }
        recalc(a),recalc(b);
    }
    void set_val(int k,Monoid x){
        thrust(k+=n);
        dat[k]=x,laz[k]=id1;
        recalc(k);
    }
    Monoid query(int a,int b){
        if (a>=b) return id0;
        thrust(a+=n),thrust(b+=n-1);
        Monoid vl=id0,vr=id0;
        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if (l&1) vl=f(vl,reflect(l++));
            if (r&1) vr=f(reflect(--r),vr);
        }
        return f(vl,vr);
    }
    Monoid operator[](int i){
        return query(i,i+1);
    }
};

class HeavyLightDecomposition{
    private:
    void dfs_sz(int v){
        if (G[v].size()&&G[v][0]==par[v]) swap(G[v][0],G[v].back());
        for (int &u:G[v]){
            if (u==par[v]) continue;
            par[u]=v; dep[u]=dep[v]+1;
            dfs_sz(u);
            sub[v]+=sub[u];
            if (sub[u]>sub[G[v][0]]) swap(u,G[v][0]);
        }
    }
    void dfs_hld(int v,int c,int &times){
        vid[v]=times++; type[v]=c;
        for (int u:G[v]){
            if (u==par[v]) continue;
            head[u]=(u==G[v][0]?head[v]:u);
            dfs_hld(u,c,times);
        }
    }
    public:
    vector<vector<int>> G;
    vector<int> vid,head,sub,par,dep,type;
    HeavyLightDecomposition(int n):
        G(n),vid(n,-1),head(n),sub(n,1),par(n,-1),dep(n,0),type(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void build(vector<int> rs={0}){
        int c=0,times=0;
        for (int r:rs){
            dfs_sz(r);
            head[r]=r;
            dfs_hld(r,c++,times);
        }
    }
    int lca(int u,int v){
        for (;;v=par[head[v]]){
            if (vid[u]>vid[v]) swap(u,v);
            if (head[u]==head[v]) return u;
        }
    }
    int distance(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }
    template<typename F>
    void update_path(int u,int v,const F &f,bool edge=false){
        for (;;v=par[head[v]]){
            if (vid[u]>vid[v]) swap(u,v);
            if (head[u]==head[v]) break;
            f(vid[head[v]],vid[v]+1);
        }
        f(vid[u]+edge,vid[v]+1);
    }
    template<typename F>
    void update_sub(int u,const F &f,bool edge=false){
        f(vid[u]+edge,vid[u]+sub[u]);
    }
    template<typename T,typename Q,typename F>
    T query(int u,int v,const T &id,const Q &q,const F &f,bool edge=false){
        T l=id,r=id;
        for (;;v=par[head[v]]){
            if (vid[u]>vid[v]) swap(u,v),swap(l,r);
            if (head[u]==head[v]) break;
            l=f(l,q(vid[head[v]],vid[v]+1));
        }
        return f(r,f(l,q(vid[u]+edge,vid[v]+1)));
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    vector<int> A(M),B(M);
    vector<ll> C(M);
    Kruskal<ll> K(N);
    for (int i=0;i<M;++i){
        cin >> A[i] >> B[i] >> C[i];
        K.add_edge(--A[i],--B[i],C[i]);
    }
    ll cost;
    vector<int> es=K.used_es(cost);
    vector<ll> ans(M,0);
    HeavyLightDecomposition HLD(N);
    for (int i=0;i<M;++i) if (es[i]){
        ans[i]=cost;
        HLD.add_edge(A[i],B[i]);
    }
    HLD.build();
    auto f=[](ll a,ll b){return max(a,b);};
    auto g=[](ll a,ll b){return b!=-1?b:a;};
    LazySegmentTree<ll,ll,decltype(f),decltype(g),decltype(g)> seg(N,f,g,g,0,-1);
    for (int i=0;i<M;++i) if (es[i]){
        HLD.update_path(A[i],B[i],[&](int l,int r){seg.update(l,r,C[i]);},true);
    }
    for (int i=0;i<M;++i) if (!es[i]){
        ll x=HLD.query(A[i],B[i],0LL,[&](int l,int r){return seg.query(l,r);},[](ll a,ll b){return max(a,b);},true);
        ans[i]=cost+C[i]-x;
    }
    int cnt=0;
    for (int i=0;i<M;++i) if (ans[i]==cost) ++cnt;
    cout << cnt-(N-1) << '\n';
}