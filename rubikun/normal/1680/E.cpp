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
const int mod=998244353,MAX=300005,INF=1<<30;

int dp[MAX][3];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<string> S(2);
        for(int i=0;i<2;i++) cin>>S[i];
        int l=N+1,r=-1;
        for(int i=0;i<2;i++){
            for(int j=0;j<N;j++){
                if(S[i][j]=='*'){
                    chmin(l,j);
                    chmax(r,j);
                }
            }
        }
        int ans=r-l;
        
        for(int i=l;i<=r;i++){
            for(int j=0;j<3;j++){
                dp[i][j]=INF;
            }
        }
        
        if(S[0][l]=='*'){
            if(S[1][l]=='*'){
                dp[l][0]=dp[l][1]=dp[l][2]=ans+1;
            }else{
                dp[l][0]=ans;
                dp[l][1]=dp[l][2]=ans+1;
            }
        }else{
            if(S[1][l]=='*'){
                dp[l][0]=dp[l][2]=ans+1;
                dp[l][1]=ans;
            }else{
                dp[l][0]=dp[l][1]=ans;
                dp[l][2]=ans+1;
            }
        }
        
        for(int i=l+1;i<=r;i++){
            for(int f=0;f<2;f++){
                for(int g=0;g<2;g++){
                    int cost=dp[i-1][f];
                    if(f!=g) cost++;
                    if(S[g^1][i]=='*') cost++;
                    chmin(dp[i][g],cost);
                }
                chmin(dp[i][2],dp[i-1][f]+1);
            }
            for(int g=0;g<2;g++){
                int cost=dp[i-1][2];
                if(S[g^1][i]=='*') cost++;
                chmin(dp[i][g],cost);
            }
            chmin(dp[i][2],dp[i-1][2]+1);
        }
        
        cout<<min({dp[r][0],dp[r][1],dp[r][2]})<<"\n";
    }
}