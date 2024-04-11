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

const int MAXN = 300005;

int rt, n, m, d[MAXN], dis[MAXN], q[MAXN], ql, qr, size[MAXN];
vector < int > G[MAXN];

inline void bfs(int x)
{
	fill( dis, 0 );
	for( dis[ q[ ql = 0 ] = x ] = qr = 1 ; ql ^ qr ; x = q[ ++ql ] )
		for( auto y : G[ x ] ) if( !dis[ y ] ) dis[ q[ qr++ ] = y ] = dis[ x ] + 1;
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read(), m = read();
	if( m == 1LL * n * ( n - 1 ) / 2 )
	{
		puts( "YES" );
		for( int i = 1 ; i <= n ; i++ ) printf( "1 " );
		return 0;
	}
	for( int i = 1, x, y ; i <= m ; i++ ) G[ x = read() ].pb( y = read() ), G[ y ].pb( x ), d[ x ]++, d[ y ]++;
	int mx = 0;
	bfs( 1 );
	for( int i = 1 ; i <= n ; i++ ) mx = max( mx, dis[ i ] );
	if( mx == 2 ) for( int i = 1 ; i <= n ; i++ ) if( d[ i ] ^ d[ 1 ] ) rt = i;
	if( !rt ) rt = q[ n - 1 ];
	bfs( rt );
	for( int i = 1 ; i <= n ; i++ ) if( dis[ i ] == 2 && d[ i ] == d[ rt ] ) dis[ i ] = 1;
	for( int i = 1 ; i <= n ; i++ ) size[ dis[ i ] ]++;
	LL c = 0;
	for( int i = 1 ; i <= n ; i++ ) c += 1LL * size[ i ] * ( size[ i ] - 1 ) >> 1, c += 1LL * size[ i ] * size[ i - 1 ];
	if( c ^ m ) return puts( "NO" ), 0;
	for( int x = 1 ; x <= n ; x++ )
		for( auto y : G[ x ] ) if( abs( dis[ y ] - dis[ x ] ) > 1 )
			return puts( "NO" ), 0;
	puts( "YES" );
	for( int i = 1 ; i <= n ; i++ ) printf( "%d ", dis[ i ] );
	return 0;
}