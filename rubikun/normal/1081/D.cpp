#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100005,INF=1<<30;
vector<pair<int,int>> G[MAX];
int dis[MAX];

void dijkstra(int u){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
    PQ.push({dis[u],u});
    
    while(!PQ.empty()){
        pair<int,int> p=PQ.top();
        PQ.pop();
        
        if(p.first>dis[p.second]) continue;
        
        for(pair<int,int> to:G[p.second]){
            int ma=max(p.first,to.second);
            
            if(ma<dis[to.first]){
                dis[to.first]=ma;
                PQ.push({ma,to.first});
            }
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    vector<int> sp(K);
    for(int i=0;i<K;i++){
        cin>>sp[i];
        sp[i]--;
    }
    
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        if(a==b) continue;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    
    for(int i=0;i<N;i++){
        sort(all(G[i]),[](pair<int,int> a,pair<int,int> b){
            return a.second<b.second;
        });
    }
    
    for(int i=0;i<N;i++) dis[i]=INF;
    dis[sp[0]]=0;
    dijkstra(sp[0]);
    
    int ans=0;
    
    for(int i=1;i<K;i++) ans=max(ans,dis[sp[i]]);
    
    for(int i=0;i<K;i++) cout<<ans<<" ";
    cout<<endl;
}