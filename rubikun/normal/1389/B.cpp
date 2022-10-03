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
const int mod=1000000007,MAX=200005,INF=1<<30;
int dp[MAX][7][2];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K,z;cin>>N>>K>>z;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<=N;i++){
            for(int j=0;j<7;j++){
                dp[i][j][0]=-INF;
                dp[i][j][1]=-INF;
            }
        }
        dp[0][0][0]=A[0];
        
        for(int t=0;t<=K;t++){
            for(int j=0;j<=z;j++){
                for(int k=0;k<2;k++){
                    int i=t-2*j;
                    if(i<0||i>=N) continue;
                    if(dp[i][j][k]==-INF) continue;
                    
                    if(k==0){
                        if(i+1<N) chmax(dp[i+1][j][0],dp[i][j][k]+A[i+1]);
                        if(i-1>=0) chmax(dp[i-1][j+1][1],dp[i][j][k]+A[i-1]);
                    }else{
                        if(i+1<N) chmax(dp[i+1][j][0],dp[i][j][k]+A[i+1]);
                    }
                }
            }
        }
        
        int ans=-INF;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<=z;j++){
                for(int k=0;k<2;k++){
                    int t=i+2*j;
                    if(t==K) chmax(ans,dp[i][j][k]);
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}