#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<ll> S(N),T(N);
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    for(int i=0;i<N;i++){
        cin>>T[i];
    }
    
    ll dp[N+1][3];//i01S2T
    
    for(int i=0;i<N+1;i++){
        for(int j=0;j<3;j++){
            dp[i][j]=0;
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                dp[i][j]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
            }else if(j==1){
                dp[i][j]=max(dp[i-1][0]+S[i-1],dp[i-1][2]+S[i-1]);
            }else if(j==2){
                dp[i][j]=max(dp[i-1][0]+T[i-1],dp[i-1][1]+T[i-1]);
            }
        }
    }
    
    cout<<max({dp[N][0],dp[N][1],dp[N][2]})<<endl;
}