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

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while( ch < '0' || ch > '9' ) { if( ch == '-' ) f = -1; ch = getchar(); }
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

const int MAXN = 100005;

int n, h, w, a, b, c[MAXN], f[MAXN], g[MAXN];

inline bool cmp(int x, int y) { return x > y; }

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	a = read(), b = read(), h = read(), w = read(), n = read();
	for( int i = 1 ; i <= n ; i++ ) c[ i ] = read();
	sort( c + 1, c + n + 1, cmp );
	f[ h ] = w; f[ w ] = h;
	if( max( h, w ) >= max( a, b ) && min( h, w ) >= min( a, b ) ) return printf( "0\n" ), 0;
	for( int i = 1 ; i <= n ; i++ )
	{
		for( int j = 1 ; j <= 1e5 ; j++ ) if( f[ j ] )
			g[ min( 1LL * j * c[ i ], 100000LL ) ] = max( g[ min( 1LL * j * c[ i ], 100000LL ) ], f[ j ] ),
			g[ j ] = max( ( LL ) g[ j ], min( 100000LL, 1LL * f[ j ] * c[ i ] ) );
		copy( f, g ); fill( g, 0 );
		for( int j = a ; j <= 1e5 ; j++ ) if( f[ j ] >= b ) return printf( "%d\n", i ), 0;
	}
	puts( "-1" );
	return 0;
}