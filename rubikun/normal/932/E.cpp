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

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

ll dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,K;cin>>N>>K;
    
    dp[0][0]=1;
    
    for(int i=0;i<=K;i++){
        for(int j=0;j<=i;j++){
            dp[i+1][j]+=dp[i][j]*j;
            if(N-j>=0) dp[i+1][j+1]+=dp[i][j]*(N-j);
            
            dp[i+1][j]%=mod;
            dp[i+1][j+1]%=mod;
        }
    }
    
    ll ans=0;
    
    for(int j=1;j<=min(N,K);j++){
        ans+=dp[K][j]*rui(2,N-j);
        ans%=mod;
    }
    
    cout<<ans<<endl;
    
}