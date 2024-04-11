#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=5005,INF=1<<30;

int dp[2][MAX][5];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        string S,T;cin>>S>>T;
        int cn=0,ma=0;
        for(int i=0;i<N;i++){
            if(cn==M) break;
            if(S[i]==T[cn]){
                cn++;
                if(cn==i+1) ma=cn;
            }
        }
        if(cn<M){
            cout<<-1<<"\n";
            continue;
        }
        
        int ans=N-ma;
        
        for(int i=0;i<2;i++) for(int j=0;j<=M;j++) for(int k=0;k<5;k++) dp[i][j][k]=INF;
        dp[0][0][0]=1;
        
        for(int i=0;i<N;i++){
            int s=i&1,t=s^1;
            for(int j=0;j<=M;j++){
                for(int k=0;k<4;k++){
                    chmin(dp[s][j][k+1],dp[s][j][k]);
                    if(j<M&&S[i]==T[j]&&k==0){
                        chmin(dp[t][j+1][k],dp[s][j][k]+1);
                    }
                    if(j<M&&S[i]==T[j]&&k==1){
                        chmin(dp[t][j+1][k],dp[s][j][k]+1);
                    }
                    if(k==1){
                        chmin(dp[t][j][k],dp[s][j][k]+2);
                    }
                    if(j<M&&S[i]==T[j]&&k==2){
                        chmin(dp[t][j+1][k],dp[s][j][k]);
                    }
                    if(j<M&&S[i]==T[j]&&k==3){
                        chmin(dp[t][j+1][k],dp[s][j][k]+1);
                    }
                    if(k==3){
                        chmin(dp[t][j][k],dp[s][j][k]+1);
                    }
                }
            }
            
            for(int j=0;j<=M;j++){
                for(int k=0;k<5;k++){
                    dp[s][j][k]=INF;
                }
            }
        }
        
        for(int k=0;k<5;k++) chmin(ans,dp[N&1][M][k]);
        
        cout<<ans<<"\n";
    }
}