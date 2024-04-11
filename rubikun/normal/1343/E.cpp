#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;
vector<int> G[MAX];
ll dis[MAX][3];
void BFS(int u,int k){
    dis[u][k]=0;
    queue<int> Q;
    Q.push(u);
    
    while(!Q.empty()){
        int a=Q.front();Q.pop();
        for(int to:G[a]){
            if(dis[to][k]==INF){
                dis[to][k]=dis[a][k]+1;
                Q.push(to);
            }
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
        int N,M,A,B,C;cin>>N>>M>>A>>B>>C;
        A--;B--;C--;
        vector<ll> cost(M+1);
        for(int i=0;i<M;i++) cin>>cost[i+1];
        sort(all(cost));
        for(int i=1;i<=M;i++) cost[i]+=cost[i-1];
        
        for(int i=0;i<N;i++){
            G[i].clear();
            dis[i][0]=dis[i][1]=dis[i][2]=INF;
        }
        for(int i=0;i<M;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        BFS(A,0);
        BFS(B,1);
        BFS(C,2);
        
        ll ans=INF;
        
        for(int i=0;i<N;i++){
            ll sum=0;
            int a=dis[i][1];
            if(a>M) sum=INF;
            else sum+=2*cost[a];
            
            int b=dis[i][0]+dis[i][2];
            if(a+b>M) sum=INF;
            else sum+=cost[a+b]-cost[a];
            
            chmin(ans,sum);
            
            //cout<<a<<" "<<b<<endl;
        }
        
        cout<<ans<<"\n";
    }
}