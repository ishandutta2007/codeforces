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

int deg[MAX];
int cnt;

vector<pair<int,int>> G[MAX];
bool alive[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    vector<pair<int,int>> E(M);
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        deg[a]++;
        deg[b]++;
        E[i]=mp(a,b);
        G[a].push_back(mp(b,i));
        G[b].push_back(mp(a,i));
        alive[i]=1;
    }
    
    vector<int> ans(M);
    
    queue<int> Q;
    for(int i=0;i<N;i++){
        if(deg[i]<K) Q.push(i);
        else cnt++;
    }
    
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(auto to:G[u]){
            if(!alive[to.se]) continue;
            alive[to.se]=0;
            deg[to.fi]--;
            if(deg[to.fi]==K-1){
                cnt--;
                Q.push(to.fi);
            }
        }
    }
    
    for(int t=M-1;t>=0;t--){
        ans[t]=cnt;
        
        if(!alive[t]) continue;
        
        deg[E[t].fi]--;
        if(deg[E[t].fi]==K-1){
            cnt--;
            Q.push(E[t].fi);
        }
        
        swap(E[t].fi,E[t].se);
        
        deg[E[t].fi]--;
        if(deg[E[t].fi]==K-1){
            cnt--;
            Q.push(E[t].fi);
        }
        
        alive[t]=0;
        
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            for(auto to:G[u]){
                if(!alive[to.se]) continue;
                alive[to.se]=0;
                deg[to.fi]--;
                if(deg[to.fi]==K-1){
                    cnt--;
                    Q.push(to.fi);
                }
            }
        }
    }
    
    for(int i=0;i<M;i++) cout<<ans[i]<<"\n";
}