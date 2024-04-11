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
const int mod=1000000007,MAX=100005;
const int INF=1<<30;
//const ll INF=1LL<<60;

struct UF{
    int n;
    vector<int> par,size,ed;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        ed.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        ed[root(a)]++;
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

map<pair<int,int>,int> MA;

vector<pair<int,int>> G[MAX];

vector<int> T[MAX];
bool seen[MAX];

void DFS(int u,int ro){
    seen[u]=1;
    for(int to:T[u]){
        if(seen[to]) continue;
        if(MA.count(mp(ro,to))) MA[mp(ro,to)]++;
        DFS(to,ro);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;c--;
        G[c].push_back(mp(a,b));
    }
    
    int Q;cin>>Q;
    
    vector<pair<int,int>> S(Q);
    vector<int> ans(Q);
    
    for(int i=0;i<Q;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        MA[mp(a,b)]=0;
        S[i]=mp(a,b);
    }
    
    for(int i=0;i<M;i++){
        if(si(G[i])>=100){
            UF uf;
            uf.init(N);
            for(auto x:G[i]) uf.unite(x.fi,x.se);
            
            for(int i=0;i<Q;i++){
                if(uf.check(S[i].fi,S[i].se)) ans[i]++;
            }
        }else{
            vector<int> use;
            for(auto x:G[i]){
                T[x.fi].push_back(x.se);
                T[x.se].push_back(x.fi);
                use.push_back(x.fi);
                use.push_back(x.se);
            }
            sort(all(use));
            use.erase(unique(all(use)),use.end());
            
            for(int a:use){
                for(int b:use) seen[b]=0;
                
                DFS(a,a);
            }
            
            for(int a:use) T[a].clear();
        }
    }
    
    for(int i=0;i<Q;i++){
        cout<<ans[i]+MA[S[i]]<<"\n";
    }
    
    
}