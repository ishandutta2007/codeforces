#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=300005,INF=1<<30;
ll dp[MAX][2][2];
vector<int> G[MAX];

void DFS(int u,int p){
    dp[u][0][0]=1;
    dp[u][1][0]=1;
    
    for(int to:G[u]){
        if(to==p) continue;
        
        DFS(to,u);
        
        dp[u][0][1]*=((2*dp[to][0][0]+2*dp[to][0][1]+dp[to][1][0]+2*dp[to][1][1]))%mod;
        dp[u][0][1]%=mod;
        
        dp[u][0][1]+=dp[u][0][0]*((dp[to][0][0]+dp[to][0][1]+dp[to][1][0]+dp[to][1][1])%mod)%mod;
        dp[u][0][1]%=mod;
        
        dp[u][1][1]*=((2*dp[to][0][0]+2*dp[to][0][1]+dp[to][1][1]))%mod;
        dp[u][1][1]%=mod;
        
        dp[u][1][1]+=dp[u][1][0]*((dp[to][0][0]+dp[to][0][1])%mod)%mod;
        dp[u][1][1]%=mod;
        
        dp[u][0][0]*=(dp[to][0][0]+dp[to][0][1]+dp[to][1][1])%mod;
        dp[u][0][0]%=mod;
        
        dp[u][1][0]*=(dp[to][0][0]+dp[to][0][1]+dp[to][1][1])%mod;
        dp[u][1][0]%=mod;
    }
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
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    DFS(0,-1);
    
    cout<<(dp[0][0][1]+dp[0][1][1]+dp[0][0][0]-1)%mod<<endl;
    
    /*for(int i=0;i<N;i++){
        cout<<dp[i][0][0]<<" "<<dp[i][0][1]<<" "<<dp[i][1][0]<<" "<<dp[i][1][1]<<endl;
    }
    
    cout<<dp[0][0][0]<<" "<<dp[0][0][1]<<" "<<dp[0][1][0]<<" "<<dp[0][1][1]<<endl;*/
    
    //cout<<(dp[0][0][0]+dp[0][0][1]+dp[0][1][0]+dp[0][1][1])%mod<<endl;
}