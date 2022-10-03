#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2005,INF=1<<20;
int dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,h,l,r;cin>>N>>h>>l>>r;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int i=0;i<=N;i++){
        for(int j=0;j<h;j++) dp[i][j]=-INF;
    }
    dp[0][0]=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<h;j++){
            if(l<=(j+A[i])%h&&(j+A[i])%h<=r) dp[i+1][(j+A[i])%h]=max(dp[i+1][(j+A[i])%h],dp[i][j]+1);
            else dp[i+1][(j+A[i])%h]=max(dp[i+1][(j+A[i])%h],dp[i][j]);
            
            if(l<=(j+A[i]-1)%h&&(j+A[i]-1)%h<=r) dp[i+1][(j+A[i]-1)%h]=max(dp[i+1][(j+A[i]-1)%h],dp[i][j]+1);
            else dp[i+1][(j+A[i]-1)%h]=max(dp[i+1][(j+A[i]-1)%h],dp[i][j]);
        }
    }
    
    int ans=0;
    
    for(int j=0;j<h;j++) ans=max(ans,dp[N][j]);
    
    cout<<ans<<endl;
}