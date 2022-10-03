#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=2005,INF=1<<30;

ll dp[MAX][MAX][4];

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    dp[1][1][0]=dp[1][2][1]=dp[1][2][2]=dp[1][1][3]=1;
    
    for(int i=1;i<N;i++){
        for(int j=1;j<=2*i;j++){
            dp[i+1][j][0]+=dp[i][j][0];
            dp[i+1][j+1][1]+=dp[i][j][0];
            dp[i+1][j+1][2]+=dp[i][j][0];
            dp[i+1][j+1][3]+=dp[i][j][0];
            
            dp[i+1][j][0]+=dp[i][j][1];
            dp[i+1][j][1]+=dp[i][j][1];
            dp[i+1][j+2][2]+=dp[i][j][1];
            dp[i+1][j][3]+=dp[i][j][1];
            
            dp[i+1][j][0]+=dp[i][j][2];
            dp[i+1][j+2][1]+=dp[i][j][2];
            dp[i+1][j][2]+=dp[i][j][2];
            dp[i+1][j][3]+=dp[i][j][2];
            
            dp[i+1][j+1][0]+=dp[i][j][3];
            dp[i+1][j+1][1]+=dp[i][j][3];
            dp[i+1][j+1][2]+=dp[i][j][3];
            dp[i+1][j][3]+=dp[i][j][3];
            
            for(int k=j;k<=j+2;k++){
                for(int l=0;l<4;l++){
                    dp[i+1][k][l]%=mod;
                }
            }
        }
    }
    
    ll ans=0;
    
    for(int k=0;k<4;k++){
        ans+=dp[N][K][k];
        ans%=mod;
    }
    
    cout<<ans<<endl;
}