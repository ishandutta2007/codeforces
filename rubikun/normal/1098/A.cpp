#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;
vector<int> G[MAX];
ll sum[MAX],cost[MAX],par[MAX];

void DFS(int u,int d){
    if(d%2==0){
        cost[u]=sum[u]-par[u];
        for(int to:G[u]){
            par[to]=sum[u];
            DFS(to,d+1);
        }
    }else{
        ll mi=INF;
        for(int to:G[u]){
            mi=min(mi,sum[to]);
        }
        cost[u]=mi-par[u];
        sum[u]=mi;
        
        if(G[u].size()==0){
            cost[u]=0;
        }
        
        for(int to:G[u]){
            par[to]=sum[u];
            DFS(to,d+1);
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N-1;i++){
        int a;cin>>a;
        a--;
        G[a].push_back(i+1);
    }
    for(int i=0;i<N;i++){
        cin>>sum[i];
    }
    
    DFS(0,0);
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ans+=cost[i];
        if(cost[i]<0){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}