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
const int mod=1000000007,MAX=1200005,MAX_N=1<<17,M=300000;
const ll INF=1LL<<60;
vector<pair<int,ll>> G[MAX];
ll dis[MAX];

void add_edge(int from,int to,ll cost){
    G[from].push_back(mp(to,cost));
}

void dijkstra(int u){
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
            if(dis[c]>dis[b]+d){
                dis[c]=dis[b]+d;
                PQ.push(make_pair(dis[c],c));
            }
        }
    }
    return;
}//a,d

void query1(int a,int b,int k,int l,int r,int node){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b) add_edge(node,k,0);
    else{
        query1(a,b,2*k+1,l,(l+r)/2,node);
        query1(a,b,2*k+2,(l+r)/2,r,node);
    }
}

void query2(int a,int b,int k,int l,int r,int node){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b) add_edge(M+k,node,0);
    else{
        query2(a,b,2*k+1,l,(l+r)/2,node);
        query2(a,b,2*k+2,(l+r)/2,r,node);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q,s;cin>>N>>Q>>s;
    s--;
    
    for(int i=0;i<MAX_N-1;i++){
        add_edge(i,i*2+1,0);
        add_edge(i,i*2+2,0);
        
        add_edge(M+i*2+1,M+i,0);
        add_edge(M+i*2+2,M+i,0);
    }
    for(int i=MAX_N-1;i<MAX_N+MAX_N-1;i++){
        add_edge(i,M*2+(i-(MAX_N-1)),0);
        add_edge(M*2+(i-(MAX_N-1)),M+i,0);
    }
    
    int now=3*M;
    
    while(Q--){
        int t;cin>>t;
        if(t==1){
            int a,b,c;cin>>a>>b>>c;
            a--;b--;
            add_edge(M*2+a,M*2+b,c);
        }else{
            int v,l,r,c;cin>>v>>l>>r>>c;
            v--;l--;
            
            if(t==2){
                add_edge(M*2+v,now,0);
                add_edge(now,now+1,c);
                query1(l,r,0,0,MAX_N,now+1);
            }else{
                add_edge(now+1,M*2+v,0);
                add_edge(now,now+1,c);
                query2(l,r,0,0,MAX_N,now);
            }
            
            now+=2;
        }
    }
    
    for(int i=0;i<MAX;i++) dis[i]=INF;
    
    dijkstra(2*M+s);
    
    for(int i=0;i<N;i++){
        if(dis[2*M+i]==INF) cout<<-1<<" ";
        else cout<<dis[2*M+i]<<" ";
    }
    cout<<endl;
}