#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=3005;
const ll INF=1LL<<61;
ll dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S,T;cin>>S>>T;
    int N=S.size(),M=T.size();
    
    ll ans=0;
    
    for(int j=0;j<M;j++){
        if(S[0]==T[j]) dp[1][j+1]=2;
    }
    dp[1][M+1]=2;
    
    if(M==1) ans+=dp[1][1];
    
    for(int i=1;i<N;i++){
        for(int j=1;j<=M+1;j++){
            if(j>=2&&S[i]==T[j-2]){
                dp[i+1][j-1]+=dp[i][j];
                dp[i+1][j-1]%=mod;
            }
            if(i+j>M){
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=mod;
            }else{
                if(S[i]==T[i+j-1]){
                    dp[i+1][j]+=dp[i][j];
                    dp[i+1][j]%=mod;
                }
            }
            
            if(j==M+1){
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=mod;
            }
        }
        
        if(i+1>=M){
            ans+=dp[i+1][1];
            ans%=mod;
        }
        
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
}