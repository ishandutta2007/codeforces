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
const int mod=998244353,MAX=300005;
const int INF=1<<30;

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

vector<int> E[MAX];
int color[MAX];

void solve(int u){
    for(int to:E[u]){
        if(color[to]==0){
            color[to]=3-color[u];
            solve(to);
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    V=N;
    UF uf;uf.init(2*N);
    vector<vector<int>> S(M);
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        b--;c--;
        S[i]={a,b,c};
        uf.unite(b,N+c);
        uf.unite(c,N+b);
        E[b].push_back(c);
        E[c].push_back(b);
    }
    
    for(int i=0;i<N;i++){
        if(uf.check(i,N+i)){
            cout<<"NO\n";
            return 0;
        }
    }
    
    for(int i=0;i<N;i++){
        if(color[i]==0){
            color[i]=1;
            solve(i);
        }
    }
    
    vector<pair<int,int>> state(N);
    
    for(int i=0;i<N;i++){
        //int a=uf.root(i),b=uf.root(N+i);
        if(color[i]==1){
            state[i]=mp(0,i);
        }else{
            state[i]=mp(1,i);
        }
    }
    
    //for(int i=0;i<N;i++) cout<<state[i].fi<<" "<<state[i].se<<endl;
    
    for(int i=0;i<M;i++){
        int a=S[i][1],b=S[i][2];
        if(S[i][0]==1){
            if(state[a].fi==0){
                add_edge(a,b);
            }else{
                add_edge(b,a);
            }
        }else{
            if(state[a].fi==0){
                add_edge(b,a);
            }else{
                add_edge(a,b);
            }
        }
    }
    
    int k=scc();
    
    if(k<N){
        cout<<"NO\n";
        return 0;
    }
    
    reverse(all(vs));
    
    vector<int> ans(N);
    for(int i=0;i<N;i++){
        ans[vs[i]]=i;
    }
    
    cout<<"YES\n";
    for(int i=0;i<N;i++){
        if(state[i].fi) cout<<'R';
        else cout<<'L';
        cout<<" ";
        cout<<ans[i]<<"\n";
    }
}