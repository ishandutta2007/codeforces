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
const int mod=998244353,MAX=55;
const ll INF=1LL<<60;

ll dp[MAX][2];
ll A[MAX][2];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        for(int t=0;t<2;t++){
            for(int i=0;i<N;i++){
                cin>>A[i][t];
                dp[i][t]=INF;
            }
        }
        dp[0][0]=dp[0][1]=0;
        for(int i=1;i<N;i++){
            chmin(dp[i][0],dp[i-1][0]+abs(A[i][0]-A[i-1][0])+abs(A[i][1]-A[i-1][1]));
            chmin(dp[i][0],dp[i-1][1]+abs(A[i][0]-A[i-1][1])+abs(A[i][1]-A[i-1][0]));
            chmin(dp[i][1],dp[i-1][0]+abs(A[i][1]-A[i-1][0])+abs(A[i][0]-A[i-1][1]));
            chmin(dp[i][1],dp[i-1][1]+abs(A[i][1]-A[i-1][1])+abs(A[i][0]-A[i-1][0]));
        }
        
        cout<<min(dp[N-1][0],dp[N-1][1])<<"\n";
    }
}