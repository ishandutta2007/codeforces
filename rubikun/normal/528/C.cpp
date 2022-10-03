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
const int mod=1000000007,MAX=100005,INF=1<<29;

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

vector<pair<int,int>> ans;

vector<int> G[MAX];

int parity[MAX];

void solve(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        
        solve(to,u);
        
        if(parity[to]){
            ans.push_back(mp(to,u));
            //cout<<to+1<<" "<<u+1<<"\n";
            parity[to]^=1;
        }else{
            ans.push_back(mp(u,to));
            //cout<<u+1<<" "<<to+1<<"\n";
            parity[u]^=1;
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> deg(N);
    vector<pair<int,int>> E(M);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        deg[a]++;
        deg[b]++;
        E[i]=mp(a,b);
    }
    
    vector<int> ki;
    for(int i=0;i<N;i++){
        if(deg[i]&1) ki.push_back(i);
    }
    
    for(int i=0;i<si(ki);i+=2){
        E.push_back(mp(ki[i],ki[i+1]));
    }
    
    M=si(E);
    
    UF uf;uf.init(N);
    
    for(auto e:E){
        if(uf.check(e.fi,e.se)){
            parity[e.fi]^=1;
            ans.push_back(e);
            //cout<<e.fi+1<<" "<<e.se+1<<"\n";
        }else{
            uf.unite(e.fi,e.se);
            G[e.fi].push_back(e.se);
            G[e.se].push_back(e.fi);
        }
    }
    
    solve(0,-1);
    
    if(parity[0]){
        ans.push_back(mp(0,0));
    }
    
    cout<<si(ans)<<"\n";
    for(auto e:ans) cout<<e.fi+1<<" "<<e.se+1<<"\n";
}