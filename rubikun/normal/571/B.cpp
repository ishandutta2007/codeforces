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
const int mod=1000000007,MAX=20;
//const int INF=1<<30;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(all(A));
    
    for(int i=0;i<N;i++) A.push_back(A[N-1]);
    
    vector<vector<ll>> dp(K+1,vector<ll>(N%K+5,-INF));
    
    int D=N/K;
    
    dp[0][0]=0;
    
    for(int i=0;i<K;i++){
        for(int j=0;j<=N%K;j++){
            chmax(dp[i+1][j],dp[i][j]+A[(i+1)*D+j]-A[(i+1)*D+j-1]);
            if(j!=N%K) chmax(dp[i+1][j+1],dp[i][j]+A[(i+1)*D+j+1]-A[(i+1)*D+j]);
        }
    }
    
    cout<<A[N-1]-A[0]-dp[K][N%K]<<endl;
}