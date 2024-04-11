#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,MAX_LOG=20;
const ll INF=1LL<<60;
vector<pair<int,ll>> G[MAX];
int N,par[MAX_LOG][MAX],depth[MAX];
ll dis[MAX][51];
int cnt[MAX];
int id[51],now=1;

void BFS(int u){
    for(int i=0;i<N;i++){
        depth[i]=-1;
        dis[i][0]=0;
        for(int j=0;j<20;j++){
            par[j][i]=-1;
        }
    }
    queue<int> Q;
    Q.push(u);
    depth[u]=0;
    dis[u][0]=0;
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        for(int i=0;i<G[a].size();i++){
            int b=G[a][i].first;
            ll c=G[a][i].second;
            if(depth[b]==-1){
                depth[b]=depth[a]+1;
                dis[b][0]=dis[a][0]+c;
                par[0][b]=a;
                Q.push(b);
                cnt[a]--;
                cnt[b]--;
            }
        }
    }
    return;
}

void init(){
    for(int k=0;k+1<MAX_LOG;k++){
        for(int i=0;i<N;i++){
            if(par[k][i]<0) par[k+1][i]=-1;
            else par[k+1][i]=par[k][par[k][i]];
        }
    }
}

int lca(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
    for(int i=0;i<20;i++){
        if(((depth[v]-depth[u])>>i)&1) v=par[i][v];
    }
    if(u==v) return u;
    
    for(int i=19;i>=0;i--){
        if(par[i][u]!=par[i][v]){
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}
//BFS(u)->init()

void dijkstra(int u){
    dis[u][now]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> PQ;
    
    PQ.push(make_pair(0,u));
    while(!PQ.empty()){
        ll a=PQ.top().first;
        int b=PQ.top().second;
        PQ.pop();
        if(dis[b][now]<a) continue;
        for(int i=0;i<G[b].size();i++){
            int c=G[b][i].first;
            ll d=G[b][i].second;
            if(dis[c][now]>dis[b][now]+d){
                dis[c][now]=dis[b][now]+d;
                PQ.push(make_pair(dis[c][now],c));
            }
        }
    }
    return;
}//a,d

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    int M;cin>>M;
    for(int i=0;i<M;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        //scanf("%d%d%lld",&a,&b,&c);
        a--;b--;
        cnt[a]++;
        cnt[b]++;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    
    BFS(0);
    init();
    
    for(int j=1;j<=50;j++){
        for(int i=0;i<N;i++){
            dis[i][j]=INF;
        }
    }
    
    for(int i=0;i<N;i++){
        if(cnt[i]){
            dijkstra(i);
            id[now]=i;
            now++;
        }
    }
    
    int Q;cin>>Q;
    while(Q){
        int a,b;
        cin>>a>>b;
        //scanf("%d%d",&a,&b);
        a--;b--;
        ll ans=dis[a][0]+dis[b][0]-2*dis[lca(a,b)][0];
        for(int i=1;i<now;i++){
            for(int j=1;j<now;j++){
                ans=min(ans,dis[a][i]+dis[b][j]+dis[id[j]][i]);
            }
        }
        
        cout<<ans<<"\n";
        
        Q--;
    }
}