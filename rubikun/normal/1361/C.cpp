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
const int mod=1000000007,MAX=1<<20,INF=1<<30;

vector<pair<int,int>> G[MAX];

bool visited[MAX];

void DFS(int u, vector<int> &trail,int p) {
    while(!G[u].empty()) {
        int v=G[u].back().fi,id=G[u].back().se;
        G[u].pop_back();
        
        if(visited[id/2]) continue;
        
        visited[id/2]=1;
        
        /*for(int i=0;i<G[v].size();i++){
            if(G[v][i].fi==u){
                swap(G[v][i],G[v].back());
                G[v].pop_back();
                //G[v].erase(G[v].begin()+i);
                break;
            }
        }*/
        
        DFS(v,trail,id);
    }
    if(p!=-1){
        trail.push_back(p);
        trail.push_back(p^1);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(2*N);
    for(int i=0;i<2*N;i++) cin>>A[i];
    
    for(int k=20;k>=0;k--){
        int mask=(1<<k)-1;
        
        for(int i=0;i<=mask;i++) G[i].clear();
        
        for(int i=0;i<N;i++){
            G[A[2*i]&mask].push_back(mp(A[2*i+1]&mask,2*i+1));
            G[A[2*i+1]&mask].push_back(mp(A[2*i]&mask,2*i));
        }
        
        bool ok=true;
        
        for(int i=0;i<=mask;i++){
            if(si(G[i])&1){
                ok=false;
                break;
            }
        }
        
        if(!ok) continue;
        
        memset(visited,0,sizeof(visited));
        
        vector<int> ans;
        
        for(int i=0;i<=mask;i++){
            if(si(G[i])){
                DFS(i,ans,-1);
                break;
            }
        }
        
        if(si(ans)!=2*N) continue;
        
        cout<<k<<endl;
        for(int a:ans) cout<<a+1<<" ";
        cout<<endl;
        return 0;
    }
}