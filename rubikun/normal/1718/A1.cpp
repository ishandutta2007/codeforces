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
const int mod=998244353,MAX=5005,INF=1<<30;

int dp[MAX][1<<13];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        A.push_back(0);
        for(int i=0;i<=N;i++) for(int j=0;j<(1<<13);j++) dp[i][j]=INF;
        dp[0][A[0]]=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<(1<<13);j++){
                if(dp[i][j]==INF) continue;
                if(j==0) chmin(dp[i+1][A[i+1]],dp[i][j]);
                chmin(dp[i+1][A[i+1]],dp[i][j]+1);
                chmin(dp[i+1][A[i+1]^j],dp[i][j]+1);
            }
        }
        
        int ans=INF;
        
        for(int j=0;j<(1<<13);j++) chmin(ans,dp[N][j]);
        
        cout<<ans<<"\n";
    }
}