#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=405;
const ll INF=(1LL<<62);
int dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S,T;cin>>S>>T;
        int N=S.size(),M=T.size();
        bool ans=false;
        
        for(int k=0;k<M;k++){
            memset(dp,0,sizeof(dp));
            dp[0][0]=k;
            
            for(int i=0;i<N;i++){
                for(int j=0;j<=k;j++){
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                    
                    if(j<k&&S[i]==T[j]){
                        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
                    }
                    if(dp[i][j]==M) continue;
                    
                    if(S[i]==T[dp[i][j]]){
                        dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
                    }
                }
            }
            
            if(dp[N][k]==M) ans=true;
        }
        
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}