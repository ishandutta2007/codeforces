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
const int mod=998244353,MAX=200005;
const int INF=1<<30;
//const ll INF=1LL<<60;
vector<int> G[MAX],revG[MAX];
bool can[MAX][23];
int N;
ll dis[MAX][23];
ll rui[3*MAX];

void check(){
    queue<pair<int,int>> Q;
    Q.push(mp(0,0));
    can[0][0]=1;
    while(!Q.empty()){
        auto u=Q.front();Q.pop();
        if(u.se&1){
            for(int to:revG[u.fi]){
                if(can[to][u.se]==0){
                    can[to][u.se]=1;
                    Q.push(mp(to,u.se));
                }
            }
        }else{
            for(int to:G[u.fi]){
                if(can[to][u.se]==0){
                    can[to][u.se]=1;
                    Q.push(mp(to,u.se));
                }
            }
        }
        if(u.se+1<20&&can[u.fi][u.se+1]==0){
            can[u.fi][u.se+1]=1;
            Q.push(mp(u.fi,u.se+1));
        }
    }
}

void dijkstra(){
    dis[0][0]=0LL;
    priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>> PQ;
    PQ.push(mp(0LL,mp(0,0)));
    
    while(!PQ.empty()){
        auto u=PQ.top();PQ.pop();
        ll d=dis[u.se.fi][u.se.se];
        
        //cout<<u.fi<<" "<<u.se.fi<<" "<<u.se.se<<" "<<d<<endl;
        if(u.fi>d) continue;
        
        if(u.se.se&1){
            for(int to:revG[u.se.fi]){
                //cout<<u.se.fi<<" "<<to<<" "<<u.se.se<<endl;
                if(chmin(dis[to][u.se.se],d+1)){
                    PQ.push(mp(dis[to][u.se.se],mp(to,u.se.se)));
                }
            }
        }else{
            for(int to:G[u.se.fi]){
                //cout<<u.se.fi<<" "<<to<<" "<<u.se.se<<endl;
                if(chmin(dis[to][u.se.se],d+1)){
                    PQ.push(mp(dis[to][u.se.se],mp(to,u.se.se)));
                }
            }
        }
        if(u.se.se+1<20&&chmin(dis[u.se.fi][u.se.se+1],d+rui[u.se.se])){
            PQ.push(mp(dis[u.se.fi][u.se.se+1],mp(u.se.fi,u.se.se+1)));
        }
    }
}

pair<int,int> dis2[MAX][2];

void BFS(){
    dis2[0][0]=mp(0,0);
    priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>> PQ;
    PQ.push(mp(mp(0,0),mp(0,0)));
    
    while(!PQ.empty()){
        auto u=PQ.top();PQ.pop();
        auto d=dis2[u.se.fi][u.se.se];
        
        //cout<<u.fi<<" "<<u.se.fi<<" "<<u.se.se<<" "<<d<<endl;
        if(u.fi>d) continue;
        
        if(u.se.se&1){
            for(int to:revG[u.se.fi]){
                //cout<<u.se.fi<<" "<<to<<" "<<u.se.se<<endl;
                if(chmin(dis2[to][u.se.se&1],mp(u.fi.fi,u.fi.se+1))){
                    PQ.push(mp(dis2[to][u.se.se&1],mp(to,u.se.se&1)));
                }
            }
        }else{
            for(int to:G[u.se.fi]){
                //cout<<u.se.fi<<" "<<to<<" "<<u.se.se<<endl;
                if(chmin(dis2[to][u.se.se&1],mp(u.fi.fi,u.fi.se+1))){
                    PQ.push(mp(dis2[to][u.se.se&1],mp(to,u.se.se&1)));
                }
            }
        }
        if(chmin(dis2[u.se.fi][(u.se.se&1)^1],mp(u.fi.fi+1,u.fi.se))){
            PQ.push(mp(dis2[u.se.fi][(u.se.se&1)^1],mp(u.se.fi,(u.se.se&1)^1)));
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    rui[0]=1;
    for(int i=1;i<3*MAX;i++) rui[i]=(rui[i-1]*2)%mod;
    
    int M;cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        revG[b].push_back(a);
    }
    
    check();
    
    int mi=INF;
    for(int j=0;j<20;j++) if(can[N-1][j]) chmin(mi,j);
    
    if(mi!=INF){
        for(int i=0;i<N;i++) for(int j=0;j<23;j++) dis[i][j]=INF;
        dijkstra();
        ll ans=INF;
        for(int j=0;j<23;j++) chmin(ans,dis[N-1][j]);
        cout<<ans<<endl;
        
        return 0;
    }
    
    for(int i=0;i<N;i++) dis2[i][0]=dis2[i][1]=mp(INF,INF);
    dis2[0][0]=mp(0,0);
    
    BFS();
    
    if(dis2[N-1][0].fi<dis2[N-1][1].fi){
        cout<<(rui[dis2[N-1][0].fi]-1+dis2[N-1][0].se)%mod<<endl;
    }else{
        cout<<(rui[dis2[N-1][1].fi]-1+dis2[N-1][1].se)%mod<<endl;
    }
    
}