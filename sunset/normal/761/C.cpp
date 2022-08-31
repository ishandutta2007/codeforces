#include <bits/stdc++.h>

using namespace std;

const int MAXN = 51;

int dp[MAXN][8], n, m;

char ch[MAXN][MAXN];

inline int cal(char s)
{
	if( s >= '0' && s <= '9' ) return 1;
	if( s >= 'a' && s <= 'z' ) return 2;
	return 4;
}

int main()
{
	scanf( "%d%d", &n, &m );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%s", ch[ i ] );
	memset( dp, 0x7f, sizeof dp );
	dp[ 0 ][ 0 ] = 0;
	for( int i = 1 ; i <= n ; i++ )
	{
		for( int j = 0 ; j < 8 ; j++ )
			for( int k = 0 ; k < m ; k++ )
				dp[ i ][ j | cal( ch[ i ][ k ] ) ] = min( dp[ i ][ j | cal( ch[ i ][ k ] ) ], dp[ i - 1 ][ j ] + min( k, m - k ) );
	}
	return printf( "%d\n", dp[ n ][ 7 ] ), 0;
}