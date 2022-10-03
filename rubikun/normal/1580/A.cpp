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
const int mod=1000000007,MAX=405,INF=1<<29;

int dp[2][MAX][MAX][5];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        vector<string> S(H);
        for(int i=0;i<H;i++) cin>>S[i];
        
        for(int t=0;t<2;t++) for(int l=0;l<=W;l++) for(int r=0;r<=W;r++) for(int s=0;s<5;s++) dp[t][l][r][s]=INF;
        
        vector<vector<int>> rui(H,vector<int>(W+1));
        for(int i=0;i<H;i++){
            for(int j=1;j<=W;j++){
                rui[i][j]=rui[i][j-1];
                if(S[i][j-1]=='1') rui[i][j]++;
            }
        }
        
        for(int l=0;l<W;l++){
            for(int r=l+3;r<W;r++){
                dp[0][l][r][1]=(r-l+1-2)-(rui[0][r]-rui[0][l+1]);
            }
        }
        
        int ans=INF;
        
        for(int h=1;h<H;h++){
            int t=(h&1),s=t^1;
            for(int l=0;l<W;l++){
                for(int r=l+3;r<W;r++){
                    for(int k=4;k>=1;k--){
                        int tok=min(4,k+1);
                        chmin(dp[t][l][r][tok],dp[s][l][r][k]+(rui[h][r]-rui[h][l+1])+(int)(S[h][l]=='0')+(int)(S[h][r]=='0'));
                        
                        if(k==4){
                            chmin(ans,dp[s][l][r][k]+(r-l+1-2)-(rui[h][r]-rui[h][l+1]));
                        }
                    }
                }
            }
            for(int l=0;l<W;l++){
                for(int r=l+3;r<W;r++){
                    dp[t][l][r][1]=(r-l+1-2)-(rui[h][r]-rui[h][l+1]);
                }
            }
            
            for(int l=0;l<W;l++){
                for(int r=0;r<W;r++){
                    for(int k=0;k<5;k++){
                        dp[s][l][r][k]=INF;
                    }
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}