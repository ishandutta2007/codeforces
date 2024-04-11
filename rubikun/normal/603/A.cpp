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
const int mod=998244353,MAX=100005,INF=1<<30;
int dp[MAX][3][2];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    string S;cin>>S;
    for(int i=0;i<MAX;i++) for(int j=0;j<3;j++) for(int k=0;k<2;k++) dp[i][j][k]=-INF;
    dp[0][0][0]=dp[0][0][1]=0;
    
    for(int i=0;i<N;i++){
        for(int j=1;j<3;j++){
            for(int k=0;k<2;k++){
                chmax(dp[i][j][k],dp[i][j-1][k]);
            }
        }
        int x=S[i]-'0';
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                chmax(dp[i+1][j][k],dp[i][j][k]);
                if(j&1){
                    if(x==k) chmax(dp[i+1][j][k^1],dp[i][j][k]+1);
                }else{
                    if(x!=k) chmax(dp[i+1][j][k^1],dp[i][j][k]+1);
                }
            }
        }
    }
    int ans=-1;
    for(int j=0;j<3;j++) for(int k=0;k<2;k++) chmax(ans,dp[N][j][k]);
    
    cout<<ans<<endl;
}