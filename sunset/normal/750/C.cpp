#include <bits/stdc++.h>

using namespace std;

const int maxn = 200020;

int a[maxn], b[maxn], n, mx = 1e9, mn = -1e9;

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i <= n ; i++ )
		scanf( "%d%d", &a[ i ], &b[ i - 1 ] ),a[ i ] += a[ i - 1 ];
	for( int i = 0 ; i < n ; i++ ) if( b[ i ] == 1 ) mn = max( mn, 1900 - a[ i ] ); //x + a[ i ] >= 1900 x >= 1900 - a[ i ]
								   else mx = min( mx, 1899 - a[ i ] ); //x + a[ i ] <= 1899 x <= 1899 - a[ i ] 
	if( mx < mn ) return printf( "Impossible\n" ), 0;
	if( mx == 1e9 ) return printf( "Infinity\n" ), 0;
	return printf( "%d\n", mx + a[ n ] ), 0;
}