#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=105,INF=1<<30;

int dp[MAX][MAX][2];//ijB[i]%2k

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    for(int i=0;i<=102;i++){
        for(int j=0;j<=102;j++){
            dp[i][j][0]=INF;
            dp[i][j][1]=INF;
        }
    }
    
    if(A[0]==0){
        dp[1][1][1]=0;
        dp[1][0][0]=0;
    }else if(A[0]%2==0){
        dp[1][0][0]=0;
    }else{
        dp[1][1][1]=0;
    }
    
    for(int i=1;i<N;i++){
        if(A[i]==0){
            for(int j=0;j<=100;j++){
                dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][0]);
                dp[i+1][j+1][1]=min(dp[i+1][j+1][1],dp[i][j][0]+1);
                
                dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][1]+1);
                dp[i+1][j+1][1]=min(dp[i+1][j+1][1],dp[i][j][1]);
            }
        }else if(A[i]%2==0){
            for(int j=0;j<=100;j++){
                dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][0]);
                //dp[i+1][j+1][1]=min(dp[i+1][j+1][1],dp[i][j][0]+1);
                
                dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][1]+1);
                //dp[i+1][j+1][1]=min(dp[i+1][j+1][1],dp[i][j][1]);
            }
        }else{
            for(int j=0;j<=100;j++){
                //dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][0]);
                dp[i+1][j+1][1]=min(dp[i+1][j+1][1],dp[i][j][0]+1);
                
                //dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][1]+1);
                dp[i+1][j+1][1]=min(dp[i+1][j+1][1],dp[i][j][1]);
            }
        }
    }
    
    cout<<min(dp[N][(N+1)/2][0],dp[N][(N+1)/2][1])<<endl;
}