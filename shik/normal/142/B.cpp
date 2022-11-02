// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define C __builtin_popcount
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline void chkmax( int &a, int b ) { if ( b>a ) a=b; }
int dp[1010][4][4]={};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if ( n==1 || m==1 ) printf("%d\n",n+m-1);
	else if ( n>2 && m>2 ) printf("%d\n",(n*m+1)/2);
	else {
		if ( n==2 ) swap(n,m);
		for ( int i=0; i<4; i++ ) for ( int j=0; j<4; j++ ) dp[2][i][j]=4-C(i)-C(j);
		for ( int i=3; i<=n; i++ ) for ( int j=0; j<4; j++ ) for ( int k=0; k<4; k++ ) {
			chkmax(dp[i][j][k],dp[i-1][0][j]);
			if ( !(k&1) ) chkmax(dp[i][j][k],dp[i-1][2][j]+1);
			if ( !(k&2) ) chkmax(dp[i][j][k],dp[i-1][1][j]+1);
			if ( !(k&3) ) chkmax(dp[i][j][k],dp[i-1][3][j]+2);
		}
		printf("%d\n",dp[n][0][0]);
	}
	return 0;
}