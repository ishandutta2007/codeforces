#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=4005,MAX_LOG=20;
const ll INF=1LL<<60;
ll dp[MAX][MAX];

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;
    int K;cin>>N>>K;
    dp[0][2000]=1;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int i=0;i<N;i++){
        for(int j=1;j<4000;j++){
            if(dp[i][j]==0) continue;
            if(A[i]==A[(i+1)%N]){
                dp[i+1][j]+=dp[i][j]*K;
                dp[i+1][j]%=mod;
            }else{
                dp[i+1][j+1]+=dp[i][j];
                dp[i+1][j]+=dp[i][j]*(K-2);
                dp[i+1][j-1]+=dp[i][j];
                
                dp[i+1][j+1]%=mod;
                dp[i+1][j]%=mod;
                dp[i+1][j-1]%=mod;
            }
        }
    }
    
    ll ans=0;
    for(int j=2001;j<=4000;j++){
        ans+=dp[N][j];
        ans%=mod;
    }
    
    cout<<ans<<endl;
}