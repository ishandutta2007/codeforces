#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=10005,INF=1<<29;
vector<pair<int,int>> G[MAX];
int dis[MAX][1005];
int x,y;

void dijkstra(int u){
    dis[u][0]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> PQ;
    
    PQ.push(make_pair(0,make_pair(u,0)));
    while(!PQ.empty()){
        int a=PQ.top().fi;
        int b=PQ.top().se.fi;
        int c=PQ.top().se.se;
        PQ.pop();
        if(dis[b][c]<a) continue;
        for(int i=0;i<G[b].size();i++){
            int d=G[b][i].first;
            int e=G[b][i].second;
            
            int f,g;
            if(c+e>x){
                continue;
            }else if(c+e==x){
                f=0;
                g=a+1;
            }else{
                f=c+e;
                g=a;
            }
            if(dis[d][f]>g){
                dis[d][f]=g;
                PQ.push(make_pair(g,make_pair(d,f)));
            }
        }
    }
    return;
}//a,d


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> A(M+1);
    for(int i=0;i<M;i++) cin>>A[i+1];
    cin>>x>>y;
    
    for(int i=0;i<=M;i++){
        for(int j=0;j<=x;j++){
            dis[i][j]=INF;
        }
    }
    
    sort(all(A));
    
    for(int i=0;i+1<M+1;i++){
        if(A[i+1]-A[i]<=x){
            G[i].push_back({i+1,A[i+1]-A[i]});
            G[i+1].push_back({i,A[i+1]-A[i]});
        }
    }
    
    dijkstra(0);
    
    ll ans=1LL<<60;
    
    for(int i=0;i<=M;i++){
        if(dis[i][0]!=INF){
            if(N-A[i]<=x){
                chmin(ans,ll(dis[i][0])*(x+y)+N-A[i]);
            }
        }
    }
    
    if(ans==1LL<<60) cout<<-1<<endl;
    else cout<<ans<<endl;
}