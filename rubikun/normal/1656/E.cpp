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
const int mod=998244353,MAX=100005;
const ll INF=1LL<<60;
vector<int> G[MAX];
int color[MAX];

void DFS(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        color[to]=color[u]^1;
        DFS(to,u);
    }
}

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        for(int i=0;i<N;i++){
            G[i].clear();
            color[i]=0;
        }
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        DFS(0,-1);
        
        for(int i=0;i<N;i++){
            if(color[i]) cout<<si(G[i])<<" ";
            else cout<<-si(G[i])<<" ";
        }
        cout<<"\n";
    }
}