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
const int mod=1000000007,MAX=2005;
const ll INF=1LL<<60;

ll dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K,P;cin>>N>>K>>P;
    vector<ll> A(N),B(K);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<K;i++) cin>>B[i];
    sort(all(A));
    sort(all(B));
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    
    for(int i=0;i<K;i++){
        for(int j=0;j<=N;j++){
            chmin(dp[i+1][j],dp[i][j]);
            if(j!=N) chmin(dp[i+1][j+1],max(dp[i][j],abs(B[i]-A[j])+abs(P-B[i])));
        }
    }
    
    cout<<dp[K][N]<<endl;
}