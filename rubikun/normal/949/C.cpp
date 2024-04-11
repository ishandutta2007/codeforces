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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;
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

vector<int> tree[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,H;cin>>N>>M>>H;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    V=N;
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        if((A[a]+1)%H==A[b]) add_edge(a,b);
        if((A[b]+1)%H==A[a]) add_edge(b,a);
    }
    
    int k=scc();
    
    pair<int,int> ans=mp(N,N+1);
    
    vector<int> cnt(k);
    for(int i=0;i<N;i++){
        cnt[cmp[i]]++;
    }
    
    for(int i=0;i<N;i++){
        for(int to:G[i]){
            int a=cmp[i],b=cmp[to];
            if(a==b) continue;
            cnt[a]=N+1;
        }
    }
    
    for(int i=0;i<k;i++){
        chmin(ans,mp(cnt[i],i));
    }
    
    cout<<ans.fi<<endl;
    
    for(int i=0;i<N;i++){
        if(cmp[i]==ans.se){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
}