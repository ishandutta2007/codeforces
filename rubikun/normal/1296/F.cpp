#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=10005,INF=1<<30;
vector<pair<int,int>> G[MAX];
int cost[MAX];
stack<int> ST;
int goal;

bool DFS(int u,int p,int cha){
    if(u==goal) return true;
    for(int i=0;i<G[u].size();i++){
        int a=G[u][i].first,b=G[u][i].second;
        
        if(a==p) continue;
        
        bool ok=DFS(a,u,cha);
        
        if(ok){
            cost[b]=max(cost[b],cha);
            return true;
        }
    }
    return false;
}
int mi=INF;

bool solve(int u,int p){
    if(u==goal) return true;
    for(int i=0;i<G[u].size();i++){
        int a=G[u][i].first,b=G[u][i].second;
        
        if(a==p) continue;
        
        bool ok=solve(a,u);
        
        if(ok){
            mi=min(mi,cost[b]);
            return true;
        }
    }
    return false;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back({b,i});
        G[b].push_back({a,i});
    }
    
    int M;cin>>M;
    vector<int> s(M),g(M),f(M);
    
    for(int i=0;i<M;i++){
        cin>>s[i]>>g[i]>>f[i];
        s[i]--;g[i]--;
        goal=g[i];
        
        DFS(s[i],-1,f[i]);
    }
    
    bool ans=true;
    
    for(int i=0;i<M;i++){
        mi=INF;
        goal=g[i];
        solve(s[i],-1);
        
        if(mi!=f[i]) ans=false;
    }
    
    if(ans){
        for(int i=0;i<N-1;i++){
            if(cost[i]==0) cost[i]=1000000;
            cout<<cost[i]<<" ";
        }
        cout<<endl;
    }else cout<<-1<<endl;
}