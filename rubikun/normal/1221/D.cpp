#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=105;
const ll INF=1LL<<55;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    for(int q=0;q<Q;q++){
        int N;cin>>N;
        
        vector<int> A(N);
        vector<ll> B(N);
        
        for(int i=0;i<N;i++){
            scanf("%d",&A[i]);
            scanf("%lld",&B[i]);
            //cin>>A[i]>>B[i];
        }
        
        vector<vector<ll>> dp(N,vector<ll>(3,INF));
        dp[0][0]=0;
        dp[0][1]=B[0];
        dp[0][2]=B[0]*2;
        
        for(int i=1;i<N;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(A[i-1]+j!=A[i]+k){
                        dp[i][k]=min(dp[i][k],dp[i-1][j]+B[i]*k);
                    }
                }
            }
        }
        
        cout<<min({dp[N-1][0],dp[N-1][1],dp[N-1][2]})<<"\n";
    }
}