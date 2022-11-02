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

inline int two( int x ) { return 1<<x; }
inline int bit( int x, int i ) { return (x>>i)&1; }
inline bool chkmin( int &a, int b ) { return b<a?a=b,1:0; }

#define N 110
#define M (1<<16)
const int INF=514514514;
const int pri[16]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int n,a[N],msk[59],dp[N][M],frm[N][M];
int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    REP1(i,2,58) REP(j,16) if ( i%pri[j]==0 ) msk[i]|=two(j);
    REP(i,n+1) REP(j,M) dp[i][j]=INF;
    dp[0][0]=0;
    REP(i,n) REP(j,M) if ( dp[i][j]<INF ) {
        int me=dp[i][j];
        REP1(k,1,58) if ( (j&msk[k])==0 ) {
            if ( chkmin(dp[i+1][j|msk[k]],me+abs(a[i]-k)) ) frm[i+1][j|msk[k]]=k;
        }
    }
    int ans=INF,pos=-1;
    REP(i,M) if ( chkmin(ans,dp[n][i]) ) pos=i;
    vector<int> b;
    for ( int i=n; i>=1; i-- ) {
        b.PB(frm[i][pos]);
        pos^=msk[frm[i][pos]];
    }
    reverse(ALL(b));
    REP(i,n) printf("%d%c",b[i],i+1==n?'\n':' ');
    return 0;
}