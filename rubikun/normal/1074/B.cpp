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
const int mod=1000000007,MAX=1005,INF=1<<30;

struct HeavyLightDecomposition{
    int n;
    vector<int> sz,in,out,nxt,par,dis;
    vector<vector<int>> G;
    
    HeavyLightDecomposition(){}
    
    HeavyLightDecomposition(int n_){
        n=n_;
        sz.assign(n,0);
        in.assign(n,0);
        out.assign(n,0);
        nxt.assign(n,0);
        par.assign(n,0);
        dis.assign(n,0);
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
            dis[a]=dis[u]+1;
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

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        HeavyLightDecomposition hld(N);
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            hld.add_edge(a,b);
        }
        
        vector<int> A,B;
        int k1,k2;
        
        cin>>k1;
        A.resize(k1);
        for(int i=0;i<k1;i++){
            cin>>A[i];
            A[i]--;
        }
        
        cin>>k2;
        B.resize(k2);
        for(int i=0;i<k2;i++){
            cin>>B[i];
            B[i]--;
        }
        
        sort(all(A));
        sort(all(B));
        
        cout<<"B "<<B[0]+1<<endl;
        int x;cin>>x;x--;
        
        if(binary_search(all(A),x)){
            cout<<"C "<<x+1<<endl;
            continue;
        }
        
        hld.build(x);
        
        pair<int,int> mi=mp(INF,INF);
        
        for(int a:A) chmin(mi,mp(hld.dis[a],a));
        
        cout<<"A "<<mi.se+1<<endl;
        int y;cin>>y;y--;
        
        if(binary_search(all(B),y)){
            cout<<"C "<<mi.se+1<<endl;
        }else{
            cout<<"C "<<-1<<endl;
        }
    }
}