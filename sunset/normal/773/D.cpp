#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill( x, y ) memset( x, y, sizeof x )
#define copy( x, y ) memcpy( x, y, sizeof x )
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;

inline LL read()
{
	LL sc = 0, f = 1; char ch = getchar();
	while( ch < '0' || ch > '9' ) { if( ch == '-' ) f = -1; ch = getchar(); }
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

const int MAXN = 2005;
const int INF = INT_MAX;

int n, a[MAXN][MAXN], m = INF, d[MAXN];
bool v[MAXN];

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read();
	for( int i = 1 ; i <= n ; i++ )
		for( int j = i + 1 ; j <= n ; j++ )
			a[ i ][ j ] = a[ j ][ i ] = read(), m = min( a[ i ][ j ], m );
	for( int i = 1 ; i <= n ; i++ )
		for( int j = i + 1 ; j <= n ; j++ )
			a[ i ][ j ] = a[ j ][ i ] -= m;
	for( int i = 1 ; i <= n ; i++ )
	{
		d[ i ] = INF;
		for( int j = 1 ; j <= n ; j++ ) if( i ^ j ) d[ i ] = min( d[ i ], a[ i ][ j ] << 1 );
	}
	d[ 0 ] = INF;
	for( int i = 1 ; i <= n ; i++ )
	{
		int p = 0;
		for( int j = 1 ; j <= n ; j++ ) if( !v[ j ] && d[ j ] < d[ p ] ) p = j;
		for( int j = 1 ; j <= n ; j++ ) d[ j ] = min( d[ j ], d[ p ] + a[ p ][ j ] );
		v[ p ] = 1;
	}
	for( int i = 1 ; i <= n ; i++ ) printf( "%lld\n", 1LL * ( n - 1 ) * m + d[ i ] );
}