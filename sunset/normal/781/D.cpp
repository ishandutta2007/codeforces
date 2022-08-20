#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

bitset < MAXN > dp[2][63][MAXN], f, g;
int n, m, cur;
long long ans;

int main()
{
	scanf( "%d%d", &n, &m );
	for( int i = 1 ; i <= m ; i++ )
	{
		int x, y, w;
		scanf( "%d%d%d", &x, &y, &w );
		dp[ w ][ 0 ][ x ][ y ] = 1;
	}
	for( int k = 1 ; k <= 62 ; k++ )
		for( int d = 0 ; d < 2 ; d++ )
			for( int i = 1 ; i <= n ; i++ )
				for( int j = 1 ; j <= n ; j++ )
					if( dp[ d ][ k - 1 ][ i ][ j ] )
						dp[ d ][ k ][ i ] |= dp[ d ^ 1 ][ k - 1 ][ j ];
	if( dp[ 0 ][ 62 ][ 1 ].any() ) return printf( "-1\n" ), 0;
	f[ 1 ] = 1;
	for( int k = 61 ; k >= 0 ; k-- )
	{
		g.reset();
		for( int i = 1 ; i <= n ; i++ ) if( f[ i ] )
			g |= dp[ cur ][ k ][ i ];
		if( g.any() ) ans += 1LL << k, cur ^= 1, f = g;
	}
	if( ans > 1e18 ) ans = -1;
	cout << ans << endl;
}