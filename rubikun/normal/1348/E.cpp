#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=505;
const ll INF=1LL<<60;
ll dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,K;cin>>N>>K;
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++) cin>>A[i]>>B[i];
    
    for(int i=0;i<=N;i++){
        for(int j=0;j<K;j++){
            dp[i][j]=-INF;
        }
    }
    dp[0][0]=0;
    
    ll sum=0;
    
    for(ll i=0;i<N;i++){
        ll z=(A[i]+B[i])%K;
        for(ll j=0;j<K;j++){
            
            if(dp[i][j]<0) continue;
            ll k=(sum+K-j);
            if(k>=K) k-=K;
            
            for(ll a=0;a<K;a++){
                if(a>A[i]) continue;
                
                ll b=(K+z-a);
                if(b>=K) b-=K;
                
                if(a+b>A[i]+B[i]) continue;
                
                ll plus=(A[i]+B[i]-a-b)/K;
                
                if(b>B[i]) continue;
                
                if(j+a>=K) plus++;
                if(k+b>=K) plus++;
                
                ll to=j+a;
                if(to>=K) to-=K;
                
                chmax(dp[i+1][to],dp[i][j]+plus);
            }
        }
        sum+=z;
        if(sum>=K) sum-=K;
    }
    
    ll ans=0;
    
    for(int j=0;j<K;j++) chmax(ans,dp[N][j]);
    
    cout<<ans<<"\n";
}