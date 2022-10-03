#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=3000005,INF=1<<30;

int V,cmp[MAX];
vector<int> G[MAX],rG[MAX],vs;//vs
bool used[MAX];

int size[MAX];

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

int incnt[MAX];
bool visited[MAX];

void solve(int u,int p){
    if(visited[u]) return;
    for(int to:G[u]){
        if(to==p) continue;
        //if(visited[to]) continue;
        solve(to,u);
        size[u]=max(size[u],size[to]);
    }
    visited[u]=1;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    V=2520*N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]<0) A[i]=2520-abs(A[i])%2520;
        A[i]%=2520;
    }
    
    vector<pair<int,int>> C;
    
    for(int i=0;i<N;i++){
        int M;cin>>M;
        vector<int> B(M);
        for(int j=0;j<M;j++){
            cin>>B[j];
            B[j]--;
        }
        for(int k=0;k<2520;k++){
            int kk=k;
            kk+=A[i];
            if(kk>=2520) kk-=2520;
            add_edge(i*2520+k,B[kk%M]*2520+kk);
            C.push_back({i*2520+k,B[kk%M]*2520+kk});
        }
    }
    
    int K=scc();
    
    for(int i=0;i<K;i++){
        G[i].clear();
        //rG[i].clear();
    }
    
    vector<set<int>> SE(K);
    
    for(int i=0;i<V;i++){
        SE[cmp[i]].insert(i/2520);
    }
    
    for(int i=0;i<K;i++){
        size[i]=SE[i].size();
    }
    //set<pair<int,int>> done;
    
    for(int i=0;i<C.size();i++){
        int a=C[i].first,b=C[i].second;
        //if(done.count({cmp[a],cmp[b]})) continue;
        G[cmp[a]].push_back(cmp[b]);
        //done.insert({cmp[a],cmp[b]});
        incnt[cmp[b]]++;
    }
    
    for(int i=0;i<K;i++){
        if(incnt[i]==0) solve(i,-1);
    }
    
    int Q;cin>>Q;
    while(Q--){
        int x,y;cin>>x>>y;
        x--;
        if(y<0) y=2520-abs(y)%2520;
        else y%=2520;
        if(y==2520) y=0;
        cout<<size[cmp[x*2520+y]]<<"\n";
    }
}