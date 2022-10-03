#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int V,cmp[MAX];
vector<int> G[MAX],rG[MAX],vs;//vs
bool used[MAX];
int cost[MAX];
bool done[MAX];

void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
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

int par[MAX],size[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        size[i]=1;
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

int maxi=INF;

void solve(int u,int p){
    used[u]=1;
    maxi=min(maxi,cost[u]);
    
    for(int to:G[u]){
        if(to==p) continue;
        if(used[to]) continue;
        
        solve(to,u);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>V;
    init(V);
    
    for(int i=0;i<V;i++) cin>>cost[i];
    
    for(int i=0;i<V;i++){
        int a;cin>>a;
        a--;
        add_edge(i,a);
        unite(i,a);
    }
    
    scc();
    
    int ans=0;
    
    memset(used,0,sizeof(used));
    
    for(int a:vs){
        if(done[root(a)]) continue;
        done[root(a)]=1;
        
        maxi=INF;
        
        solve(a,-1);
        
        ans+=maxi;
    }
    
    cout<<ans<<endl;
}