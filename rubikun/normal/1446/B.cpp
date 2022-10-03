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
int dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    string S,T;cin>>S>>T;
    
    for(int j=0;j<=M;j++) dp[0][j]=0;
    
    for(int i=1;i<=N;i++){
        dp[i][0]=0;
        for(int j=1;j<=M;j++){
            chmax(dp[i][j],dp[i-1][j]-1);
            chmax(dp[i][j],dp[i][j-1]-1);
            if(S[i-1]==T[j-1]) chmax(dp[i][j],dp[i-1][j-1]+2);
            else chmax(dp[i][j],dp[i-1][j-1]-2);
        }
    }
    
    int ans=0;
    
    for(int i=0;i<=N;i++) for(int j=0;j<=M;j++) chmax(ans,dp[i][j]);
    
    cout<<ans<<endl;
}