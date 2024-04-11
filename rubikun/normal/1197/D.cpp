#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18;
const ll INF=1LL<<55;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M,K;cin>>N>>M>>K;
    vector<ll> A(N+1);
    for(int i=1;i<=N;i++){
        //cin>>A[i];
        scanf("%lld",&A[i]);
        A[i]+=A[i-1];
    }
    
    ll dp[N+1][M];
    
    for(int i=0;i<N+1;i++){
        for(int j=0;j<M;j++){
            if(j==0) dp[i][j]=0;
            else dp[i][j]=-INF;
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            for(int k=1;k<=M;k++){
                if(i-k<0) continue;
                if(j-k>0) dp[i][j]=max(dp[i][j],dp[i-k][(j-k)]+A[i]-A[i-k]);
                else dp[i][j]=max(dp[i][j],dp[i-k][(j+M-k)%M]+A[i]-A[i-k]-K);
            }
        }
    }
    
    ll ans=0;
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    
    cout<<ans<<endl;
    
    
}