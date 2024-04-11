// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,m,msk,dp[50][1<<7][1<<7];
void chkmin( int &a, int b ) { if ( b<a ) a=b; }
int main()
{
	scanf("%d%d",&n,&m);
	if ( n<m ) swap(n,m);
	memset(dp,0x7f,sizeof(dp));
	dp[0][msk=(1<<m)-1][0]=0;
	for ( int i=0; i<n; i++ ) for ( int j=0; j<=msk; j++ ) for ( int k=0; k<=msk; k++ )
		for ( int x=0; x<=msk; x++ ) if ( (j|x)==msk ) chkmin(dp[i+1][(k|x|(x<<1)|(x>>1))&msk][x],dp[i][j][k]+__builtin_popcount(x));
	printf("%d\n",n*m-*min_element(dp[n][msk],dp[n][msk]+(1<<m)));
	return 0;
}