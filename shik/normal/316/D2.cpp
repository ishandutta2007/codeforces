// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 1010
#define MOD 1000000007
int a[N],dp[N][N];
int main()
{
    dp[0][0]=dp[0][1]=1;
    for ( int i=2; i<N; i++ ) dp[0][i]=(dp[0][i-1]+(i-1LL)*dp[0][i-2])%MOD;
    for ( int i=0; i+2<N; i++ ) dp[1][i]=(dp[0][i+2]-dp[0][i+1])%MOD;
    for ( int i=2; i<N; i++ ) for ( int j=0; j+2<N; j++ ) dp[i][j]=(dp[i-1][j+2]-(i-1LL)*dp[i-2][j+2]-dp[i-1][j+1])%MOD;
    int n;
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    int c1=count(a,a+n,1);
    int c2=count(a,a+n,2);
    int ans=dp[c2][c1];
    if ( ans<0 ) ans+=MOD;
    printf("%d\n",ans);
    return 0;
}