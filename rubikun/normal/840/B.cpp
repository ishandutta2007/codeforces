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
const int mod=1000000007,MAX=300005,INF=1<<30;
vector<pair<int,int>> G[MAX];
int S[MAX];
bool use[MAX],visited[MAX];

bool ans=1;

void DFS(int u,int p,int e){
    
    visited[u]=1;
    
    for(auto to:G[u]){
        if(to.fi==p) continue;
        if(visited[to.fi]) continue;
        
        DFS(to.fi,u,to.se);
    }
    
    if(S[u]==1){
        if(e==-1) ans=0;
        else{
            use[e]=1;
            S[u]^=1;
            if(S[p]>=0) S[p]^=1;
        }
    }
}



int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(mp(b,i));
        G[b].push_back(mp(a,i));
    }
    
    for(int i=0;i<N;i++){
        if(S[i]==-1){
            DFS(i,-1,-1);
            break;
        }
        
        if(i==N-1) DFS(N-1,-1,-1);
    }
    
    if(ans){
        int cnt=0;
        for(int i=0;i<M;i++) if(use[i]) cnt++;
        cout<<cnt<<endl;
        for(int i=0;i<M;i++) if(use[i]) cout<<i+1<<"\n";
    }else cout<<-1<<endl;
    
    
}