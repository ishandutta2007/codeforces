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
const int mod=998244353,MAX=300005,INF=1<<30;

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

int dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;ll K;cin>>N>>M>>K;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    vector<pair<int,int>> E(M);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        E[i]=mp(a,b);
    }
    V=N;
    int left=0,right=INF;
    while(right-left>1){
        int mid=(left+right)/2;
        for(int i=0;i<N;i++){
            G[i].clear();
            rG[i].clear();
            cmp[i]=used[i]=0;
            dp[i]=0;
        }
        vs.clear();
        for(int i=0;i<M;i++){
            if(A[E[i].fi]<=mid&&A[E[i].se]<=mid){
                add_edge(E[i].fi,E[i].se);
            }
        }
        int k=scc();
        //cout<<mid<<" "<<k<<endl;
        if(k<N){
            right=mid;
            continue;
        }
        
        reverse(all(vs));
        
        //for(int a:vs) cout<<a<<" ";
        //cout<<endl;
        
        for(int a:vs){
            if(A[a]>mid) continue;
            chmax(dp[a],1);
            for(int to:G[a]){
                chmax(dp[to],dp[a]+1);
            }
        }
        int ma=0;
        for(int i=0;i<N;i++) chmax(ma,dp[i]);
        
        if((ll)ma>=K) right=mid;
        else left=mid;
    }
    
    if(right==INF) right=-1;
    cout<<right<<endl;
}