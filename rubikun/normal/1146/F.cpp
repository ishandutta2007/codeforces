#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=200005,INF=1<<30;
vector<int> G[MAX];
ll dp[MAX][3];

void DFS(int u,int p){
    if(G[u].size()==0){
        dp[u][0]=1;
        return;
    }
    dp[u][2]=1;
    
    for(int to:G[u]){
        if(to==p) continue;
        
        DFS(to,u);
        
        dp[u][0]=(dp[u][0]*(dp[to][0]+dp[to][2])%mod+(dp[u][0]+dp[u][1])*(dp[to][0]+dp[to][1]))%mod;
        dp[u][1]=(dp[u][2]*(dp[to][0]+dp[to][1])%mod+dp[u][1]*(dp[to][0]+dp[to][2]))%mod;
        dp[u][2]=dp[u][2]*(dp[to][0]+dp[to][2])%mod;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N-1;i++){
        int p;cin>>p;
        p--;
        G[p].push_back(i+1);
    }
    
    DFS(0,-1);
    
    cout<<(dp[0][0]+dp[0][2])%mod<<endl;
}