#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,MAX_LOG=20,INF=1<<30;
int N;
vector<pair<int,ll>> G[MAX];
int size[MAX];
ll dis[MAX],mini=0;
bool used[MAX];
vector<int> center;

void findcenter(int u,int p){
    size[u]=1;
    bool ok=true;
    
    for(pair<int,ll> to:G[u]){
        if(to.first==p) continue;
        findcenter(to.first,u);
        if(size[to.first]>N/2) ok=false;
        size[u]+=size[to.first];
    }
    
    if(N-size[u]>N/2) ok=false;
    
    if(ok) center.push_back(u);
}

void BFS(int u){
    queue<int> Q;
    Q.push(u);
    
    while(!Q.empty()){
        int a=Q.front();Q.pop();
        for(pair<int,ll> to:G[a]){
            if(to.first==u) continue;
            if(dis[to.first]==0){
                dis[to.first]=dis[a]+to.second;
                Q.push(to.first);
            }
        }
    }
}
ll cnt=0;

void DFS(int u,int p){
    for(pair<int,ll> to:G[u]){
        if(to.first==p) continue;
        DFS(to.first,u);
        if(size[to.first]%2==1) mini+=to.second;
    }
    //cout<<u<<" "<<mini<<endl;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        cin>>N;
        N*=2;
        for(int i=0;i<N;i++){
            size[i]=0;
            dis[i]=0;
            used[i]=0;
        }
        for(int i=0;i<N;i++) G[i].clear();
        center.clear();
        mini=0;
        
        for(int i=0;i<N-1;i++){
            int a,b;ll c;cin>>a>>b>>c;
            a--;b--;
            G[a].push_back({b,c});
            G[b].push_back({a,c});
        }
                        
        findcenter(0,-1);
        BFS(center[0]);
        
        ll maxi=0;
        
        for(int i=0;i<N;i++){
            maxi+=dis[i];
        }
        
        DFS(0,-1);
        
        cout<<mini<<" "<<maxi<<endl;
    }
}