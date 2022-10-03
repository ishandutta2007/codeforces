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
const int mod=998244353,MAX=605;
const ll INF=1LL<<60;

ll dis[MAX][MAX],cost[MAX];
vector<pair<int,ll>> G[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) dis[i][j]=INF;
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        G[a].push_back(mp(b,c));
    }
    
    for(int i=0;i<N;i++){
        dis[i][i]=0;
        vector<int> used(N);
        
        for(int ttt=0;ttt<N;ttt++){
            pair<ll,int> mi=mp(INF,-1);
            for(int j=0;j<N;j++){
                if(!used[j]) chmin(mi,mp(dis[i][j],j));
            }
            
            int u=mi.se;
            used[u]=1;
            ll d=dis[i][u];
            ll dd=d%N;
            
            for(int j=0;j<N;j++) cost[j]=INF;
            
            pair<ll,int> start=mp(INF,-1);
            
            for(auto to:G[u]){
                if(to.se==INF) continue;
                int toto=to.fi+dd;
                if(toto>=N) toto-=N;
                chmin(cost[toto],to.se);
                chmin(start,mp(to.se,toto));
            }
            
            for(int j=start.se,k=j-1;j<start.se+N;j++,k++){
                int jj=j,kk=k;
                if(jj>=N) jj-=N;
                if(kk<0) kk+=N;
                if(kk>=N) kk-=N;
                chmin(cost[jj],cost[kk]+1);
            }
            
            for(int j=0;j<N;j++){
                chmin(dis[i][j],d+cost[j]);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<"\n";
    }
}