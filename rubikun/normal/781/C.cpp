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
const int mod=1000000007,MAX=400005,INF=1<<30;

vector<int> G[MAX];

struct UF{
    int n;
    vector<int> par,size;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

vector<int> trail;

void DFS(int u,int p){
    trail.push_back(u);
    for(int to:G[u]){
        if(to==p) continue;
        DFS(to,u);
        trail.push_back(u);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    
    UF uf;
    uf.init(N);
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        if(!uf.check(a,b)){
            uf.unite(a,b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }
    
    DFS(0,-1);
    
    vector<vector<int>> ans(K);
    
    int lim=(2*N+K-1)/K;
    
    for(int i=0;i<2*N-1;i++){
        ans[i/lim].push_back(trail[i]);
    }
    
    for(int i=0;i<K;i++) if(si(ans[i])==0) ans[i].push_back(0);
    
    for(int i=0;i<K;i++){
        cout<<si(ans[i]);
        for(int a:ans[i]) cout<<" "<<a+1;
        cout<<"\n";
    }
}