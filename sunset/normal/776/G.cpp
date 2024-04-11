#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 65536;

LL dp[17][MAXN][17];
int Q, mo[MAXN * 16], n, a[17], cnt;
char ch[17];

inline LL dfs(int mx, int p, int pos)
{
	if( dp[ mx ][ p ][ pos ] != -1 ) return dp[ mx ][ p ][ pos ];
	cnt++;
	if( !pos )
		return dp[ mx ][ p ][ pos ] = ( p >> mx ) & 1;
	LL t = 0;
	for( int i = 0 ; i < 16 ; i++ )
		t += dfs( max( mx, i ), mo[ p * 16 + i ], pos - 1 );
	return dp[ mx ][ p ][ pos ] = t;
}

int main()
{
	memset( dp, -1, sizeof dp );
	for( int i = 1 ; i < MAXN * 16 ; i++ )
	{
		mo[ i ] = mo[ i - 1 ] + 1;
		if( mo[ i ] == MAXN ) mo[ i ] = 0;
	}
	dfs( 0, 0, 16 );
	scanf( "%d", &Q );
	while( Q-- )
	{
		LL x = 0, ret = 0;
		scanf( "%s", ch ); n = strlen( ch );
		for( int i = 0 ; i < n ; i++ )
		{
			x *= 16;
			if( ch[ i ] >= '0' && ch[ i ] <= '9' ) x += ch[ i ] - '0';
			else x += ch[ i ] - 'a' + 10;
		}
		if( x )
		{
			x--;
			int mx = 0, cur = 0; n = 0;
			while( x ) a[ n++ ] = x % 16, x /= 16;
			for( int i = n - 1 ; i >= 0 ; i-- )
			{
				for( int j = 0 ; j < a[ i ] ; j++ )
					ret -= dp[ max( mx, j ) ][ mo[ cur * 16 + j ] ][ i ];
				mx = max( mx, a[ i ] );
				cur = mo[ cur * 16 + a[ i ] ];
			}
			ret -= dp[ mx ][ cur ][ 0 ];
		}
		x = 0;
		scanf( "%s", ch ); n = strlen( ch );
		for( int i = 0 ; i < n ; i++ )
		{
			x *= 16;
			if( ch[ i ] >= '0' && ch[ i ] <= '9' ) x += ch[ i ] - '0';
			else x += ch[ i ] - 'a' + 10;
		}
		if( x )
		{
			int mx = 0, cur = 0; n = 0;
			while( x ) a[ n++ ] = x % 16, x /= 16;
			for( int i = n - 1 ; i >= 0 ; i-- )
			{
				for( int j = 0 ; j < a[ i ] ; j++ )
					ret += dp[ max( mx, j ) ][ mo[ cur * 16 + j ] ][ i ];
				mx = max( mx, a[ i ] );
				cur = mo[ cur * 16 + a[ i ] ];
			}
			ret += dp[ mx ][ cur ][ 0 ];
		}
		printf( "%I64d\n", ret );
	}
}