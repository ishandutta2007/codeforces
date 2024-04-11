#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101;

int n, l;

int vis[MAXN], a[MAXN];

int main()
{
	scanf( "%d%d", &n, &l );
	for( int i = 1 ; i <= n ; i++ ) { int x; scanf( "%d", &x ); vis[ x ] = 1; }
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &a[ i ] );
	for( int i = 0 ; i < l ; i++ )
	{
		int j;
		for( j = 1 ; j <= n ; j++ ) if( !vis[ ( a[ j ] + i ) % l ] ) break;
		if( j == n + 1 ) return printf( "YES\n" ), 0;
	}
	return printf( "NO\n" ), 0;
}