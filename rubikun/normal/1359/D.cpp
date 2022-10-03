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
const int mod=1000000007,MAX=100005,INF=1<<30;

int dp[MAX][65];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int i=0;i<=N;i++){
        for(int j=0;j<65;j++) dp[i][j]=-INF;
    }
    
    dp[0][0]=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=60;j++){
            if(dp[i][j]==-INF) continue;
            
            if(j<A[i]+30){
                chmax(dp[i+1][A[i]+30],dp[i][j]+A[i]);
                chmax(dp[i+1][A[i]+30],A[i]);
            }else{
                chmax(dp[i+1][j],dp[i][j]+A[i]);
                chmax(dp[i+1][A[i]+30],A[i]);
            }
        }
    }
    
    int ans=-INF;
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<=60;j++){
            chmax(ans,dp[i][j]-(j-30));
        }
    }
    
    cout<<ans<<endl;
}