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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

ll dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N),diff(N+2);
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(i) diff[i]=abs(A[i]-A[i-1]);
    }
    
    for(int i=0;i<=N;i++) dp[i]=-INF;
    
    dp[0]=0;
    
    for(int i=1;i<N;i++){
        chmax(dp[i],diff[i]);
        if(i>=2) chmax(dp[i],dp[i-2]-diff[i-1]+diff[i]);
    }
    
    ll ans=-INF;
    
    for(int i=1;i<=N;i++) chmax(ans,dp[i]);
    
    cout<<ans<<endl;
    
}