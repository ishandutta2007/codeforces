#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=300005;
const ll INF=1LL<<55;
vector<pair<pair<ll,int>,int>> G[MAX];
ll dis[MAX];
int K,cnt=0,ans[MAX];

void dijkstra(){
    dis[0]=0;
    
    priority_queue<pair<pair<ll,int>,pair<int,int>>,vector<pair<pair<ll,int>,pair<int,int>>>,greater<pair<pair<ll,int>,pair<int,int>>>> PQ;
    
    for(int i=0;i<G[0].size();i++){
        auto p=G[0][i];
        PQ.push({{p.first.first,p.first.second},{0,p.second}});
    }
    
    while(!PQ.empty()&&cnt<K){
        auto p=PQ.top();PQ.pop();
        if(dis[p.first.second]!=INF) continue;
        dis[p.first.second]=p.first.first;
        ans[p.second.second]=1;
        cnt++;
        for(int i=0;i<G[p.first.second].size();i++){
            auto q=G[p.first.second][i];
            PQ.push({{dis[p.first.second]+q.first.first,q.first.second},{p.first.second,q.second}});
        }
    }
    
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        dis[i]=INF;
    }
    
    for(int i=0;i<M;i++){
        int a,b;ll c;cin>>a>>b>>c;
        a--;b--;
        G[a].push_back({{c,b},i});
        G[b].push_back({{c,a},i});
    }
    
    dijkstra();
    
    cout<<cnt<<endl;
    bool ok=false;
    for(int i=0;i<M;i++){
        if(ans[i]){
            if(ok) cout<<" ";
            cout<<i+1;
            ok=true;
        }
    }
    cout<<endl;
}