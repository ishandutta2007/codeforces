#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int u[MAXN], v[MAXN], tot, d[MAXN], n, c[MAXN];

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i < n ; i++ ) scanf( "%d%d", &u[ i ], &v[ i ] );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &c[ i ] );
	for( int i = 1 ; i < n ; i++ ) if( c[ u[ i ] ] ^ c[ v[ i ] ] ) tot++, d[ u[ i ] ]++, d[ v[ i ] ]++;
	for( int i = 1 ; i <= n ; i++ ) if( d[ i ] == tot ) return printf( "YES\n%d\n", i ), 0;
	return puts( "NO" ), 0;
}