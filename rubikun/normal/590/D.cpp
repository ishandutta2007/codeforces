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
const int mod=998244353,MAX=155;
const ll INF=1LL<<60;

ll dp[2][MAX][MAX*MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K,lim;cin>>N>>K>>lim;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<2;i++) for(int j=0;j<MAX;j++) for(int k=0;k<MAX*MAX;k++) dp[i][j][k]=INF;
    dp[0][0][0]=0;
    for(int i=0;i<N;i++){
        int s=i&1,t=s^1;
        for(int j=0;j<=i;j++){
            for(int k=0;k<=N*i;k++){
                chmin(dp[t][j][k],dp[s][j][k]);
                chmin(dp[t][j+1][k+i-j],dp[s][j][k]+A[i]);
                
                dp[s][j][k]=INF;
            }
        }
    }
    
    ll ans=INF;
    
    for(int k=0;k<=N*N;k++){
        if(k<=lim) chmin(ans,dp[N&1][K][k]);
    }
    
    cout<<ans<<endl;
}