#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,MAX_LOG=20,INF=1<<30;
vector<pair<int,ll>> G[MAX];
int N,par[MAX_LOG][MAX],depth[MAX];
ll dis[MAX];

void BFS(int u){
    for(int i=0;i<N;i++){
        depth[i]=-1;
        dis[i]=0;
        for(int j=0;j<20;j++){
            par[j][i]=-1;
        }
    }
    queue<int> Q;
    Q.push(u);
    depth[u]=0;
    dis[u]=0;
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        for(int i=0;i<G[a].size();i++){
            int b=G[a][i].first;
            ll c=G[a][i].second;
            if(depth[b]==-1){
                depth[b]=depth[a]+1;
                dis[b]=dis[a]+c;
                par[0][b]=a;
                Q.push(b);
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


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>N>>Q;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back({b,1});
        G[b].push_back({a,1});
    }
    BFS(0);
    init();
    
    while(Q--){
        int k;cin>>k;
        priority_queue<pair<int,int>> PQ;
        for(int i=0;i<k;i++){
            int a;cin>>a;
            a--;
            if(a==0){
                PQ.push({0,0});
            }else{
                a=par[0][a];
                PQ.push({depth[a],a});
            }
        }
        
        bool ok=true;
        
        while(PQ.size()>=2){
            auto a=PQ.top();PQ.pop();
            auto b=PQ.top();PQ.pop();
            
            //cout<<a.second<<" "<<b.second<<endl;
            
            if(lca(a.second,b.second)==b.second){
                PQ.push(b);
            }else{
                ok=false;
                break;
            }
        }
        
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}