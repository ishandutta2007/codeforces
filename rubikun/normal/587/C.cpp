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

const int mod=1000000007,MAX=1000005,INF=1<<30;

struct HeavyLightDecomposition{
    int n;
    vector<int> sz,in,out,nxt,par;
    vector<vector<int>> G;
    
    HeavyLightDecomposition(){}
    
    HeavyLightDecomposition(int n_){
        n=n_;
        sz.assign(n,0);
        in.assign(n,0);
        out.assign(n,0);
        nxt.assign(n,0);
        par.assign(n,0);
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
};

template<typename T>
struct SparseTable{
    using F=function<T(T,T)>;
    
    int n,logn;
    vector<vector<T>> dat;
    vector<int> loglen;
    F f;
    T ti;
    
    SparseTable(){}
    
    SparseTable(int n_,F f,T ti) :f(f),ti(ti){
        n=1;
        logn=1;
        while(n<n_){
            n*=2;
            logn++;
        }
        loglen.resize(n+3);
        n=n_;
        int j=0;
        for(int i=1;i<n+3;i++){
            loglen[i]=j;
            if(i+1>(1<<(j+1))) j++;
        }
        
        dat.resize(logn);
        
        for(int i=0;i<logn;i++){
            dat[i].assign(n+1,ti);
        }
    }
    
    void set(vector<T> &v){
        for(int j=0;j<n+1;j++){
            if(j<si(v)) dat[0][j]=v[j];
        }
    }
    
    void set(int j,T x){
        dat[0][j]=x;
    }
    
    void built(){
        for(int i=1;i<logn;i++){
            for(int j=0;j<n+1;j++){
                T vl=dat[i-1][j],vr;
                if(j+(1<<(i-1))>=n+1) vr=ti;
                else vr=dat[i-1][j+(1<<(i-1))];
                dat[i][j]=f(vl,vr);
            }
        }
    }
    
    T query(int l,int r){
        T vl=dat[loglen[r-l]][l],vr=dat[loglen[r-l]][r-(1<<loglen[r-l])];
        return f(vl,vr);
    }
};

vector<int> merge(vector<int> &a,vector<int> &b){
    vector<int> res(10,INF);
    int i=0,j=0,k=0;
    while(k<10){
        if(i>=10){
            if(j>=10) break;
            res[k]=b[j];
            j++;
        }else if(j>=10){
            res[k]=a[i];
            i++;
        }else if(a[i]<b[j]){
            res[k]=a[i];
            i++;
        }else if(a[i]>b[j]){
            res[k]=b[j];
            j++;
        }else if(a[i]==b[j]){
            res[k]=a[i];
            i++;
            j++;
        }
        
        k++;
    }
    
    /*for(int i=0;i<5;i++) cout<<a[i]<<" ";
    cout<<endl;
    
    for(int i=0;i<5;i++) cout<<b[i]<<" ";
    cout<<endl;
    
    for(int i=0;i<5;i++) cout<<res[i]<<" ";
    cout<<endl;
    
    cout<<endl;*/
    
    return res;
}

HeavyLightDecomposition hld;
SparseTable<vector<int>> spa;

vector<int> query(int a,int b){
    vector<int> res(10,INF);
    int c=hld.lca(a,b);
    
    //cout<<a<<" "<<b<<" "<<c<<endl;
    while(a!=-1){
        if(hld.nxt[a]==hld.nxt[c]){
            vector<int> x=spa.query(hld.in[c],hld.in[a]+1);
            res=merge(res,x);
            break;
        }
        vector<int> x=spa.query(hld.in[hld.nxt[a]],hld.in[a]+1);
        res=merge(res,x);
        a=hld.par[hld.nxt[a]];
    }
    while(b!=-1){
        if(hld.nxt[b]==hld.nxt[c]){
            vector<int> x=spa.query(hld.in[c],hld.in[b]+1);
            res=merge(res,x);
            break;
        }
        vector<int> x=spa.query(hld.in[hld.nxt[b]],hld.in[b]+1);
        res=merge(res,x);
        b=hld.par[hld.nxt[b]];
    }
    
    return res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,Q;cin>>N>>M>>Q;
    hld=HeavyLightDecomposition(N);
    
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        hld.add_edge(a,b);
    }
    
    hld.build(0);
    
    /*for(int i=0;i<N;i++){
        cout<<i<<" : "<<"in "<<hld.in[i]<<" : out "<<hld.out[i]<<" : nxt "<<hld.nxt[i]<<endl;
    }*/
    
    spa=SparseTable<vector<int>> (N,
                                     [](auto a,auto b){
                                         return merge(a,b);
                                     },
                                     vector<int>(10,INF));
    
    vector<vector<int>> X(N,vector<int>());
    
    for(int i=0;i<M;i++){
        int a;cin>>a;
        a--;
        X[a].push_back(i);
    }
    
    for(int i=0;i<N;i++){
        vector<int> re(10,INF);
        sort(all(X[i]));
        
        for(int j=0;j<min(si(X[i]),10);j++) re[j]=X[i][j];
        spa.set(hld.in[i],re);
    }
    
    spa.built();
    
    while(Q--){
        int u,v,a;cin>>u>>v>>a;
        u--;v--;
        
        vector<int> res=query(u,v);
        
        while(si(res)>a) res.pop_back();
        while(si(res)&&res.back()==INF) res.pop_back();
        
        cout<<si(res);
        for(int a:res) cout<<" "<<a+1;
        cout<<"\n";
    }
}