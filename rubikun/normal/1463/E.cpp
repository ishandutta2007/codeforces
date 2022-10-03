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
const int mod=1000000007,MAX=300005;
const int INF=1<<30;

int V,cmp[MAX];
vector<int> G[MAX],rG[MAX],vs;//vs
bool used[MAX];

void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void add_clause(int i,bool f,int j,bool g){
    add_edge(2*i+(!f),2*j+g);
    add_edge(2*j+(!g),2*i+f);
}

void DFS(int v){
    used[v]=1;
    for(int i=0;i<G[v].size();i++){
        if(used[G[v][i]]==0) DFS(G[v][i]);
    }
    vs.push_back(v);
}

void rDFS(int v,int k){
    used[v]=1;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++){
        if(used[rG[v][i]]==0) rDFS(rG[v][i],k);
    }
}

int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++){
        if(used[v]==0) DFS(v);
    }
    
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(used[vs[i]]==0) rDFS(vs[i],k++);
    }
    return k;
}

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

vector<int> w[MAX];
int nex[MAX],ng[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    V=N;
    int ro;
    
    set<pair<int,int>> SE;
    
    vector<pair<int,int>> EE;
    
    for(int i=0;i<N;i++){
        int p;cin>>p;
        if(p){
            p--;
            add_edge(p,i);
            EE.push_back(mp(p,i));
            SE.insert(mp(p,i));
        }else{
            ro=i;
        }
    }
    
    vector<pair<int,int>> E(M),B;
    for(int i=0;i<M;i++){
        cin>>E[i].fi>>E[i].se;
        E[i].fi--;E[i].se--;
        add_edge(E[i].fi,E[i].se);
        SE.insert(E[i]);
    }
    
    int k=scc();
    
    if(k!=N){
        cout<<0<<endl;
        return 0;
    }
    
    UF uf;
    uf.init(N);
    
    memset(nex,-1,sizeof(nex));
    
    for(int i=0;i<M;i++){
        uf.unite(E[i].fi,E[i].se);
        nex[E[i].fi]=E[i].se;
        ng[E[i].se]=1;
    }
    
    set<pair<int,int>> SE2;
    
    for(auto e:SE){
        if(!uf.check(e.fi,e.se)) SE2.insert(mp(uf.root(e.fi),uf.root(e.se)));
    }
    
    vs.clear();
    memset(cmp,0,sizeof(cmp));
    memset(used,0,sizeof(used));
    for(int i=0;i<N;i++){
        G[i].clear();
        rG[i].clear();
    }
    
    for(auto e:SE2){
        add_edge(e.fi,e.se);
    }
    
    scc();
    
    reverse(all(vs));
    
    vector<int> vs2;
    
    for(int i=0;i<N;i++){
        if(!ng[i]){
            int now=i;
            while(now!=-1){
                w[uf.root(i)].push_back(now);
                now=nex[now];
            }
        }
    }
    
    for(int a:vs){
        for(int b:w[a]) vs2.push_back(b);
    }
    
    vs=vs2;
    
    vector<int> wh(N);
    for(int i=0;i<N;i++) wh[vs[i]]=i;
    
    bool ok=true;
    
    for(int i=0;i<M;i++){
        if(wh[E[i].fi]+1!=wh[E[i].se]) ok=false;
    }
    
    for(int i=0;i<si(EE);i++){
        if(wh[EE[i].fi]>wh[EE[i].se]) ok=false;
    }
    
    if(ok){
        for(int a:vs) cout<<a+1<<" ";
        cout<<endl;
    }else{
        cout<<0<<endl;
    }
}