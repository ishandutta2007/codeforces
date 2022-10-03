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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

vector<pair<int,int>> G[MAX];
int ansv[MAX],anse[MAX];
int N;
int t=1;

void DFS(int u,int p,int x){
    for(auto to:G[u]){
        if(to.fi==p) continue;
        if(x){
            anse[to.se]=N+t;
            ansv[to.fi]=t;
            t++;
            DFS(to.fi,u,0);
        }else{
            anse[to.se]=t;
            ansv[to.fi]=N+t;
            t++;
            DFS(to.fi,u,N);
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int P;cin>>P;
        N=(1<<P);
        t=1;
        for(int i=0;i<N;i++) G[i].clear();
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;a--;b--;
            G[a].push_back(mp(b,i));
            G[b].push_back(mp(a,i));
        }
        ansv[0]=N;
        DFS(0,-1,N);
        cout<<1<<"\n";
        for(int i=0;i<N;i++) cout<<ansv[i]<<" ";
        cout<<"\n";
        for(int i=0;i<N-1;i++) cout<<anse[i]<<" ";
        cout<<"\n";
    }
}