#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<20;
int color[MAX];
vector<int> G[MAX];

int dp[MAX],ans[MAX];

void DFS(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        DFS(to,u);
        
        if(dp[to]>=0) dp[u]+=dp[to];
    }
    if(color[u]==0) dp[u]--;
    else dp[u]++;
}

void solve(int u,int p){
    ans[u]=dp[u];
    for(int to:G[u]){
        if(to==p) continue;
        int a=dp[u],b=dp[to];
        
        if(dp[to]>=0) dp[u]-=dp[to];
        if(dp[u]>=0) dp[to]+=dp[u];
        
        solve(to,u);
        
        dp[u]=a;
        dp[to]=b;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++) cin>>color[i];
    
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    DFS(0,-1);
    
    solve(0,-1);
    
    for(int i=0;i<N;i++) cout<<ans[i]<<" ";
    cout<<endl;
}