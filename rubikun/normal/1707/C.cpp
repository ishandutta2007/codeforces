#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=100005;
const ll INF=1LL<<60;

//Union Find


struct UF{
    int n;
    vector<int> par,size,edge;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        edge.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        edge[root(a)]++;
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            edge[root(a)]+=edge[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

struct HeavyLightDecomposition{
    int n;
    vector<int> sz,in,out,nxt,par,depth;
    vector<vector<int>> G;
    
    HeavyLightDecomposition(){}
    
    HeavyLightDecomposition(int n_){
        n=n_;
        sz.assign(n,0);
        in.assign(n,0);
        out.assign(n,0);
        nxt.assign(n,0);
        par.assign(n,0);
        depth.assign(n,0);
        G.assign(n,vector<int>());
    }
    
    void add_edge(int u,int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    void dfs_sz(int u,int p){
        par[u]=p;
        sz[u]=1;
        if(G[u].size()&&G[u][0]==p) swap(G[u][0],G[u].back());
        for(auto &a:G[u]){
            if(a==p) continue;
            depth[a]=depth[u]+1;
            dfs_sz(a,u);
            sz[u]+=sz[a];
            if(sz[a]>sz[G[u][0]]){
                swap(a,G[u][0]);
            }
        }
    }
    
    void dfs_hld(int u,int p,int &t){
        in[u]=t++;
        for(auto a:G[u]){
            if(a==p) continue;
            nxt[a]=(a==G[u][0] ? nxt[u] : a);
            dfs_hld(a,u,t);
        }
        out[u]=t;
    }
    
    void build(int u){
        int t=0;
        dfs_sz(u,-1);
        dfs_hld(u,-1,t);
    }
    
    int lca(int u,int v){
        if(in[u]>in[v]) swap(u,v);
        if(nxt[u]==nxt[v]) return u;
        return lca(u,par[nxt[v]]);
    }
    
    int mov1(int a,int b){
        if(a==b) return a;
        int c=lca(a,b);
        if(c==a){
            int l=0,r=si(G[a]);
            while(r-l>1){
                int m=(l+r)/2;
                if(par[a]==G[a][m]){
                    if(m+1<r){
                        if(r-l==2){
                            l=m+1;
                            break;
                        }
                        if(in[G[a][m+1]]<=in[b]) l=m+1;
                        else r=m;
                    }else{
                        if(r-l==2){
                            l=m-1;
                            break;
                        }
                        if(in[G[a][m-1]]<=in[b]) l=m-1;
                        else r=m-1;
                    }
                }else{
                    if(in[G[a][m]]<=in[b]) l=m;
                    else r=m;
                }
            }
            if(par[a]!=G[a][l]) return G[a][l];
            else return G[a][l+1];
            //return G[a][l];
        }else{
            return par[a];
        }
    }
    //ab1
};
//query(in[a],out[a])
//query(in[a],in[a]+1)

//atcoder::lazy_segtree<T,f,ti,E,g,h,ei> seg;
HeavyLightDecomposition hld;

//hld=HeavyLightDecomposition(N)main;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    hld=HeavyLightDecomposition(N);
    UF uf;uf.init(N);
    vector<pair<int,int>> ng;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        if(uf.check(a,b)){
            ng.push_back(mp(a,b));
        }else{
            uf.unite(a,b);
            hld.add_edge(a,b);
        }
    }
    
    hld.build(0);
    
    
    //for(int i=0;i<N;i++) cout<<hld.in[i]<<" "<<hld.out[i]<<endl;
    
    vector<int> imo(N+2);
    
    auto ad=[&](int u,int c){
        imo[hld.in[u]]+=c;
        imo[hld.out[u]]-=c;
    };
    
    for(int t=0;t<si(ng);t++){
        int a=ng[t].fi,b=ng[t].se;
        if(hld.depth[a]>hld.depth[b]) swap(a,b);
        if(hld.lca(a,b)==a){
            int c=hld.mov1(a,b);
            ad(0,1);
            ad(c,-1);
            ad(b,1);
        }else{
            ad(a,1);
            ad(b,1);
        }
    }
    
    for(int i=1;i<=N;i++) imo[i]+=imo[i-1];
    
    for(int i=0;i<N;i++){
        if(imo[hld.in[i]]==si(ng)) cout<<1;
        else cout<<0;
    }
    
    cout<<"\n";
}