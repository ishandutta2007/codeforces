// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
#define N 310
const LL INF=1e15;
LL w[N][N],dp[N][N];
inline void chkmin( LL &a, LL b ) { if ( b<a ) a=b; }
int main()
{
    int n,m,t;
    scanf("%d%d%d",&n,&m,&t);
    for ( int i=0; i<N; i++ ) for ( int j=0; j<N; j++ ) w[i][j]=INF;
    while ( m-- ) {
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        chkmin(w[l][r],c);
    }
    for ( int l=n-1; l>=1; l-- ) for ( int i=1; i+l<=n; i++ ) {
        chkmin(w[i+1][i+l],w[i][i+l]);
        chkmin(w[i][i+l-1],w[i][i+l]);
    }
    for ( int i=0; i<N; i++ ) for ( int j=0; j<N; j++ ) dp[i][j]=INF;
    for ( int i=0; i<=n; i++ ) dp[i][0]=0;
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=t && j<=i; j++ ) {
        dp[i][j]=dp[i-1][j];
        for ( int k=1; k<=j; k++ ) chkmin(dp[i][j],dp[i-k][j-k]+w[i-k+1][i]);
    }
    if ( dp[n][t]==INF ) puts("-1");
    else cout<<dp[n][t]<<endl;
    return 0;
}