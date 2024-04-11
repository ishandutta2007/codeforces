// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

#define N 5010
const int MOD=1e9+7;

int n,a,b,k,dp[2][N],sdp[2][N];
int main() {
    RI(n,a,b,k);
    int u=0;
    dp[0][a]=1;
    REP1(i,1,n) sdp[0][i]=sdp[0][i-1]+dp[0][i];
    REP1(i,1,k) {
        u^=1;
        memset(dp[u]+1,0,n*sizeof(int));
        REP1(j,1,b-1) {
            int r=(j+b-1)/2;
            dp[u][j]=sdp[u^1][r]-dp[u^1][j];
            if ( dp[u][j]<0 ) dp[u][j]+=MOD;
        }
        REP1(j,b+1,n) {
            int l=(b+j)/2+1;
            dp[u][j]=sdp[u^1][n]-sdp[u^1][l-1]-dp[u^1][j];
            if ( dp[u][j]<0 ) dp[u][j]+=MOD;
            if ( dp[u][j]<0 ) dp[u][j]+=MOD;
        }
        REP1(j,1,n) {
            sdp[u][j]=sdp[u][j-1]+dp[u][j];
            if ( sdp[u][j]>=MOD ) sdp[u][j]-=MOD;
        }
    }
    int ans=sdp[u][n];
    printf("%d\n",ans);
    return 0;
}