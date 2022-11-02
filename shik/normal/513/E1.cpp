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

inline void chkmax( int &a, int b ) {
    if ( b>a ) a=b;
}

#define N 410
#define M 55
const int INF=1e9;

int n,m,a[N],sa[N];

int sum( int l, int r ) {
    return sa[r]-sa[l-1];
}

int dp[N][M][2];
int main() {
    RI(n,m);
    REP1(i,1,n) RI(a[i]);
    REP1(i,1,n) sa[i]=sa[i-1]+a[i];
    REP1(i,0,n) REP1(j,0,m) dp[i][j][0]=dp[i][j][1]=-INF;
    dp[0][0][0]=dp[0][0][1]=0;
    REP1(i,1,n) {
        int *me=dp[i][1];
        chkmax(me[0],dp[i-1][1][0]);
        chkmax(me[1],dp[i-1][1][1]);
        REP1(j,1,i) {
            int s=sum(j,i);
            chkmax(me[0],-s);
            chkmax(me[1],+s);
        }
    }
    REP1(i,1,n) REP1(j,2,m) {
        int *me=dp[i][j];
        chkmax(me[0],dp[i-1][j][0]);
        chkmax(me[1],dp[i-1][j][1]);
        REP1(k,1,i) {
            int s=sum(k,i);
            chkmax(me[0],dp[k-1][j-1][0]);
            chkmax(me[0],dp[k-1][j-1][1]-2*s);
            chkmax(me[1],dp[k-1][j-1][0]+2*s);
            chkmax(me[1],dp[k-1][j-1][1]);
        }
        //printf("%d,%d: %d %d\n",i,j,me[0],me[1]);
    }
    int ans=-INF;
    REP1(i,1,n) REP1(j,i,n) {
        int s=sum(i,j);
        chkmax(ans,dp[i-1][m-1][0]+s);
        chkmax(ans,dp[i-1][m-1][1]-s);
    }
    printf("%d\n",ans);
    return 0;
}