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
const int mod=1000000007,MAX=200005,INF=1<<30;
vector<int> G[MAX];
int color[MAX];

void DFS(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        if(color[to]) continue;
        
        color[to]=3-color[u];
        
        DFS(to,u);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    
    vector<pair<int,int>> S(N);
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[i]=mp(a,b);
        
        G[a].push_back(b);
        G[b].push_back(a);
        
        G[2*i].push_back(2*i+1);
        G[2*i+1].push_back(2*i);
    }
    
    for(int i=0;i<2*N;i++){
        if(color[i]==0){
            color[i]=1;
            DFS(i,-1);
        }
    }
    
    for(int i=0;i<N;i++){
        cout<<color[S[i].fi]<<" "<<color[S[i].se]<<"\n";
    }
    
    
}