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

vector<int> G[MAX],GG[MAX];
int sz[MAX];

void pre(int u,int p){
    sz[u]++;
    for(int to:GG[u]){
        if(to==p) continue;
        G[u].push_back(to);
        pre(to,u);
        sz[u]+=sz[to];
    }
}

int solve(int u){
    if(si(G[u])==0) return 0;
    else if(si(G[u])==1) return sz[G[u][0]]-1;
    else{
        int a=sz[G[u][0]]-1+solve(G[u][1]);
        int b=sz[G[u][1]]-1+solve(G[u][0]);
        return max(a,b);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        for(int i=0;i<N;i++){
            G[i].clear();
            GG[i].clear();
            sz[i]=0;
        }
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;a--;b--;
            GG[a].push_back(b);
            GG[b].push_back(a);
        }
        pre(0,-1);
        cout<<solve(0)<<"\n";
        
    }
}