#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1005,INF=1<<30;
ll dp[MAX][MAX][13],sum[MAX][MAX][13];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            dp[i][j][0]=1;
        }
    }
    
    for(int i=0;i<=N;i++){
        for(int j=1;j<=N;j++){
            sum[i][j][0]=sum[i][j-1][0]+dp[i][j][0];
            if(sum[i][j][0]>=mod) sum[i][j][0]-=mod;
        }
    }
    
    for(int j=0;j<=N;j++){
        for(int i=1;i<=N;i++){
            sum[i][j][0]+=sum[i-1][j][0];
            if(sum[i][j][0]>=mod) sum[i][j][0]-=mod;
        }
    }
    
    for(int k=1;k<M;k++){
        for(int i=1;i<=N;i++){
            for(int j=i;j<=N;j++){
                dp[i][j][k]=(sum[0][j-1][k-1]+sum[i][N][k-1]-sum[0][N][k-1]-sum[i][j-1][k-1]+2*mod)%mod;
            }
        }
        
        for(int i=0;i<=N;i++){
            for(int j=1;j<=N;j++){
                sum[i][j][k]=sum[i][j-1][k]+dp[i][j][k];
                if(sum[i][j][k]>=mod) sum[i][j][k]-=mod;
            }
        }
        
        for(int j=0;j<=N;j++){
            for(int i=1;i<=N;i++){
                sum[i][j][k]+=sum[i-1][j][k];
                if(sum[i][j][k]>=mod) sum[i][j][k]-=mod;
            }
        }
    }
    
    ll ans=0;
    
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            ans+=dp[i][j][M-1];
            if(ans>=mod) ans-=mod;
        }
    }
    
    cout<<ans<<endl;
}