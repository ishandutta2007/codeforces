// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 4010
#define M 810
#define INF 514514514
int u[N][N],su[N][N],w[N][N],s[M][N],dp[M][N];
char buf[2*N];
void go( int t, int l, int r, int sl, int sr ) {
    if ( l>r ) return;
    int m=(l+r)/2,sm=-1,sml=INF;
    for ( int i=sl; i<=sr && i<=m; i++ ) {
        int now=dp[t-1][i]+w[i+1][m];
        if ( now<sml ) {
            sml=now;
            sm=i;
        }
    }
    dp[t][m]=sml;
    go(t,l,m-1,sl,sm);
    go(t,m+1,r,sm,sr);
}
int main()
{
    int n,m;
    scanf("%d%d ",&n,&m);
    for ( int i=1; i<=n; i++ ) {
        gets(buf);
        for ( int j=1; j<=n; j++ ) u[i][j]=buf[2*(j-1)]-'0';
    }
    for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) su[i][j]=su[i][j-1]+u[i][j];
    for ( int i=1; i<=n; i++ ) for ( int j=i+1; j<=n; j++ ) w[i][j]=w[i][j-1]+su[j][j]-su[j][i-1];
    for ( int i=1; i<=n; i++ ) dp[1][i]=w[1][i];
    for ( int i=2; i<=m; i++ ) go(i,1,n,1,n);
    printf("%d\n",dp[m][n]);
    return 0;
}