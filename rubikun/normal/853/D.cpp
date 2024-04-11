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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

ll dp[MAX][35];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<MAX;i++){
        for(int j=0;j<35;j++){
            dp[i][j]=INF;
        }
    }
    
    dp[0][0]=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=30;j++){
            for(int k=0;k<=A[i]/100;k++){
                if(j<k) break;
                chmin(dp[i+1][j-k],dp[i][j]+A[i]-k*100);
                if(k==0) chmin(dp[i+1][j+A[i]/1000],dp[i][j]+A[i]);
            }
        }
    }
    
    ll ans=INF;
    
    for(int j=0;j<35;j++) chmin(ans,dp[N][j]);
    
    cout<<ans<<endl;
    return 0;
}