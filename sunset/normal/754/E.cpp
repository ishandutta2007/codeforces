#include <bits/stdc++.h>
using namespace std;

const int MAXN = 405;

typedef bitset < MAXN > bs;

bs mp[26][MAXN], ans[MAXN];
int n, m, r, c;
char ch[MAXN];

int main()
{
	scanf( "%d%d", &n, &m );
	for( int i = 0 ; i < n ; i++ )
	{
		scanf( "%s", ch );
		for( int j = 0 ; j < m ; j++ ) mp[ ch[ j ] - 'a' ][ i ][ j ] = true;
	}
	for( int i = 0 ; i < n ; i++ ) ans[ i ] = ~ans[ i ];
	scanf( "%d%d", &r, &c );
	for( int i = 0 ; i < r ; i++ )
	{
		scanf( "%s", ch );
		for( int j = 0 ; j < c ; j++ )
		{
			if( ch[ j ] == '?' ) continue;
			int dx = ( ( -i ) % n + n ) % n, dy = j % m;
			for( int x = 0 ; x < n ; x++ )
				ans[ ( x + dx ) % n ] &= ( ( mp[ ch[ j ] - 'a' ][ x ] >> dy ) | ( mp[ ch[ j ] - 'a' ][ x ] << ( m - dy ) ) ); 
		}
	}
	for( int i = 0 ; i < n ; i++ )
	{
		for( int j = 0 ; j < m ; j++ )
			if( ans[ i ][ j ] ) putchar( '1' );
			else putchar( '0' );
		putchar( 10 );
	}
}