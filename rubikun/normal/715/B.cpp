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
const int mod=998244353,MAX=1005;

const ll INF=1LL<<33;
vector<pair<int,ll>> G[MAX];
ll dis[MAX];
int p[MAX];

void dijkstra(int u,bool f){
    dis[u]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> PQ;
    
    PQ.push(make_pair(0,u));
    while(!PQ.empty()){
        ll a=PQ.top().first;
        int b=PQ.top().second;
        PQ.pop();
        if(dis[b]<a) continue;
        for(int i=0;i<G[b].size();i++){
            int c=G[b][i].first;
            ll d=G[b][i].second;
            if(f&&d==0) d=1;
            else if(d==0) d=INF;
            if(dis[c]>dis[b]+d){
                p[c]=b;
                dis[c]=dis[b]+d;
                PQ.push(make_pair(dis[c],c));
            }
        }
    }
    return;
}//a,d

ll kyo[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,L,s,t;cin>>N>>M>>L>>s>>t;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) kyo[i][j]=INF;
    vector<vector<int>> E(M);
    for(int i=0;i<M;i++){
        int a,b;
        ll c;cin>>a>>b>>c;
        E[i]={a,b,(int)c};
        if(c==0){
            G[a].push_back(mp(b,0));
            G[b].push_back(mp(a,0));
        }else{
            G[a].push_back(mp(b,c));
            G[b].push_back(mp(a,c));
        }
        kyo[a][b]=kyo[b][a]=c;
    }
    
    for(int j=0;j<N;j++) dis[j]=INF;
    dijkstra(s,0);
    if(dis[t]<L){
        cout<<"NO\n";
        return 0;
    }
    
    for(int j=0;j<N;j++) dis[j]=INF;
    memset(p,-1,sizeof(p));
    dijkstra(s,1);
    //cout<<dis[t]<<endl;
    if(dis[t]>L){
        cout<<"NO\n";
        return 0;
    }
    
    while(1){
        for(int i=0;i<N;i++){
            G[i].clear();
        }
        for(int i=0;i<M;i++){
            int a=E[i][0],b=E[i][1];
            G[a].push_back(mp(b,kyo[a][b]));
            G[b].push_back(mp(a,kyo[b][a]));
        }
        for(int j=0;j<N;j++) dis[j]=INF;
        memset(p,-1,sizeof(p));
        dijkstra(s,1);
        if(dis[t]==L) break;
        
        vector<int> trail;
        int now=t;
        while(now!=s){
            trail.push_back(now);
            now=p[now];
        }
        trail.push_back(s);
        reverse(all(trail));
        
        //for(int a:trail) cout<<a<<" ";
        //cout<<endl;
        
        ll rem=L-dis[t];
        
        for(int i=0;i+1<si(trail);i++){
            int a=trail[i],b=trail[i+1];
            if(kyo[a][b]) continue;
            kyo[a][b]=kyo[b][a]=rem+1;
            //cout<<a<<" "<<b<<" "<<rem<<endl;
            break;
            //cout<<can<<endl;
        }
    }
    
    cout<<"YES\n";
    
    for(int i=0;i<M;i++){
        int a=E[i][0],b=E[i][1],c=E[i][2];
        if(kyo[a][b]) cout<<a<<" "<<b<<" "<<kyo[a][b]<<"\n";
        else cout<<a<<" "<<b<<" "<<1<<"\n";
    }
}