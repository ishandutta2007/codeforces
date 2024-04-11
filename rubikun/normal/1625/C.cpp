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
const int mod=998244353,MAX=505;
const ll INF=1LL<<60;
ll dp[MAX][MAX];

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,L,K;cin>>N>>L>>K;
    vector<ll> d(N),A(N);
    for(int i=0;i<N;i++) cin>>d[i];
    for(int i=0;i<N;i++) cin>>A[i];
    d.push_back(L);
    A.push_back(0);
    for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) dp[i][j]=INF;
    dp[0][0]=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            for(int k=i+1;k<=N;k++){
                chmin(dp[k][j+k-i-1],dp[i][j]+(d[k]-d[i])*A[i]);
            }
        }
    }
    ll ans=INF;
    for(int j=0;j<=K;j++) chmin(ans,dp[N][j]);
    
    cout<<ans<<"\n";
}