#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=2005,INF=1<<30;
ll dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    dp[1][0]=M;
    for(int i=1;i<N;i++){
        for(int j=0;j<=K;j++){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j+1]+=dp[i][j]*(M-1);
            
            dp[i+1][j]%=mod;
            dp[i+1][j+1]%=mod;
        }
    }
    
    cout<<dp[N][K]<<endl;
}