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

int V,cmp[MAX];
vector<int> G[MAX],rG[MAX],vs;//vs
bool used[MAX];

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

vector<int> G2[MAX];
int ans[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    V=H*W;
    vector<vector<int>> S(H,vector<int>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>S[i][j];
        }
    }
    
    for(int i=0;i<H;i++){
        vector<pair<int,int>> A(W);
        for(int j=0;j<W;j++) A[j]=mp(S[i][j],j);
        sort(all(A));
        
        for(int j=0;j+1<W;j++){
            if(A[j].fi==A[j+1].fi){
                add_edge(i*W+A[j].se,i*W+A[j+1].se);
                add_edge(i*W+A[j+1].se,i*W+A[j].se);
            }else{
                add_edge(i*W+A[j].se,i*W+A[j+1].se);
            }
        }
    }
    
    for(int j=0;j<W;j++){
        vector<pair<int,int>> A(H);
        for(int i=0;i<H;i++) A[i]=mp(S[i][j],i);
        sort(all(A));
        
        for(int i=0;i+1<H;i++){
            if(A[i].fi==A[i+1].fi){
                add_edge(A[i].se*W+j,A[i+1].se*W+j);
                add_edge(A[i+1].se*W+j,A[i].se*W+j);
            }else{
                add_edge(A[i].se*W+j,A[i+1].se*W+j);
            }
        }
    }
    
    int K=scc();
    
    for(int i=0;i<H*W;i++){
        for(int to:G[i]){
            if(cmp[i]!=cmp[to]) G2[cmp[i]].push_back(cmp[to]);
        }
    }
    
    for(int i=0;i<K;i++){
        if(ans[i]==0) ans[i]=1;
        for(int to:G2[i]) chmax(ans[to],ans[i]+1);
    }
    
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout<<ans[cmp[i*W+j]]<<" ";
        }
        cout<<"\n";
    }
}