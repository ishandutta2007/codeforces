#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2003,INF=1<<30;
ll dp1[MAX][MAX],dp2[MAX][MAX];
int rightsum[MAX][MAX],downsum[MAX][MAX];

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<string> S(N);
    for(int i=0;i<N;i++) cin>>S[i];
    
    for(int i=0;i<N;i++){
        for(int j=M-1;j>=0;j--){
            rightsum[i][j]=rightsum[i][j+1];
            if(S[i][j]=='R') rightsum[i][j]++;
        }
    }
    
    for(int j=0;j<M;j++){
        for(int i=N-1;i>=0;i--){
            downsum[i][j]=downsum[i+1][j];
            if(S[i][j]=='R') downsum[i][j]++;
        }
    }
    
    for(int j=0;j<M-rightsum[0][0];j++){
        dp1[0][j]=1;
        dp2[1][j]++;
        dp2[N-downsum[1][j]][j]+=mod-1;
        
        dp2[1][j]%=mod;
        dp2[N-downsum[1][j]][j]%=mod;
    }
    
    for(int i=1;i<N;i++){
        for(int j=M-1;j>=0;j--){
            dp1[i][j+1]+=dp2[i][j];
            dp1[i][M-rightsum[i][j+1]]+=mod-dp2[i][j];
            
            dp1[i][j+1]%=mod;
            dp1[i][M-rightsum[i][j+1]]%=mod;
        }
        
        for(int j=1;j<M;j++){
            dp1[i][j]+=dp1[i][j-1];
            dp1[i][j]%=mod;
        }
        
        for(int j=0;j<M;j++){
            dp2[i+1][j]+=dp1[i][j];
            dp2[N-downsum[i+1][j]][j]+=mod-dp1[i][j];
            
            dp2[i+1][j]%=mod;
            dp2[N-downsum[i+1][j]][j]%=mod;
        }
        
        for(int j=0;j<M;j++){
            dp2[i+1][j]+=dp2[i][j];
            dp2[i+1][j]%=mod;
        }
        
    }
    
    cout<<(dp1[N-1][M-1]+dp2[N-1][M-1])%mod<<endl;
    
    
    
}