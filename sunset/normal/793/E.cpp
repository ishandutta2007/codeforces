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

const int MAXN = 5005;

inline int read()
{
	int sc = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc;
}

vector < int > G[MAXN], cur;
int size[MAXN], fa[MAXN], n, a, b, c, d, mx;
bool vis[MAXN];

inline void dfs(int x)
{
	for( int i = x ; i ^ 1 ; i = fa[ i ] )
	{
		vis[ i ] = 1;
		for( auto y : G[ i ] ) if( !vis[ y ] ) cur.pb( size[ y ] );
	}
}

inline bool solve(int a, int b, int c)
{
	fill( vis, 0 ); cur.clear();
	bitset < MAXN > ret; ret.reset(); ret[ 0 ] = 1;
	dfs( a ); dfs( c );
	while( fa[ b ] ^ 1 ) b = fa[ b ]; vis[ b ] = 1;
	for( auto y : G[ 1 ] ) if( !vis[ y ] ) cur.pb( size[ y ] );
	for( auto x : cur ) ret |= ret << x;
	return ret[ size[ 1 ] / 2 - 1 - size[ b ] ];

}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read(); a = read(); b = read(); c = read(); d = read();
	for( int i = 2 ; i <= n ; i++ ) G[ fa[ i ] = read() ].pb( i );
	for( int i = n ; i > 1 ; i-- ) size[ i ] = max( size[ i ], 1 ), size[ fa[ i ] ] += size[ i ], mx = max( mx, size[ i ] );
	if( size[ 1 ] & 1 ) return puts( "NO" ), 0;
	if( mx * 2 >= size[ 1 ] ) return puts( "NO" ), 0;
	if( solve( a, c, b ) && solve( b, d, c ) ) puts( "YES" );
	else puts( "NO" );
}