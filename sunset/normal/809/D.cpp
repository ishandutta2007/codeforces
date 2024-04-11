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

const int MAXN = 600005;
const int INF = 0x3f3f3f3f;

int fa[MAXN], ch[MAXN][2], tag[MAXN], val[MAXN], st[MAXN], top, rt, tot, n;

inline void pushdown(int x)
{
	if( tag[ x ] )
	{
		tag[ ch[ x ][ 0 ] ] += tag[ x ];
		tag[ ch[ x ][ 1 ] ] += tag[ x ];
		val[ ch[ x ][ 0 ] ] += tag[ x ];
		val[ ch[ x ][ 1 ] ] += tag[ x ];
		tag[ x ] = 0;
	}
}

inline void rotate(int x)
{
	int y = fa[ x ], z = fa[ y ], k = ch[ y ][ 1 ] == x;
	fa[ ch[ y ][ k ] = ch[ x ][ k ^ 1 ] ] = y;
	fa[ fa[ ch[ x ][ k ^ 1 ] = y ] = x ] = z;
	if( z ) ch[ z ][ ch[ z ][ 1 ] == y ] = x;
}

inline void splay(int x, int aim = 0)
{
	st[ top = 1 ] = x;
	for( int i = x ; fa[ i ] ; i = fa[ i ] ) st[ ++top ] = fa[ i ];
	while( top ) pushdown( st[ top-- ] );
	for( int y = fa[ x ] ; y ^ aim ; rotate( x ), y = fa[ x ] ) if( fa[ y ] ^ aim )
		rotate( ( ( ch[ y ][ 1 ] == x ) == ( ch[ fa[ y ] ][ 1 ] == y ) ) ? y : x );
	if( !aim ) rt = x;
}

inline int build(int l, int r)
{
	if( l > r ) return 0;
	int mid = l + r >> 1, x = ++tot;
	ch[ x ][ 0 ] = build( l, mid - 1 );
	ch[ x ][ 1 ] = build( mid + 1, r );
	if( ch[ x ][ 0 ] ) fa[ ch[ x ][ 0 ] ] = x;
	if( ch[ x ][ 1 ] ) fa[ ch[ x ][ 1 ] ] = x;
	val[ x ] = mid ? INF : 0;
	return x;
}

inline int query_pre(int v)
{
	int ret = -1, cur = rt;
	while( cur )
	{
		pushdown( cur );
		if( val[ cur ] < v ) ret = cur, cur = ch[ cur ][ 1 ];
		else cur = ch[ cur ][ 0 ];
	}
	return ret;
}

inline int query_suf(int v)
{
	int ret = -1, cur = rt;
	while( cur )
	{
		pushdown( cur );
		if( val[ cur ] > v ) ret = cur, cur = ch[ cur ][ 0 ];
		else cur = ch[ cur ][ 1 ];
	}
	return ret;
}

inline void ins(int v)
{
	int x = rt;
	while( true )
	{
		pushdown( x );
		int &y = ch[ x ][ v > val[ x ] ];
		if( !y ) { val[ y = ++tot ] = v; fa[ y ] = x; x = y; break; }
		x = y;
	}
	splay( x );
}

inline void del(int x)
{
	splay( x );
	int cur = ch[ x ][ 0 ];
	if( !cur ) { fa[ rt = ch[ x ][ 1 ] ] = 0; return ; }
	while( ch[ cur ][ 1 ] ) cur = ch[ cur ][ 1 ];
	splay( cur, rt );
	fa[ ch[ cur ][ 1 ] = ch[ rt ][ 1 ] ] = ch[ rt ][ 1 ] ? cur : 0;
	fa[ rt = cur ] = 0;
}

inline int dfs(int x)
{
	if( !x ) return 0;
	pushdown( x );
	return ( val[ x ] && val[ x ] < INF ) + dfs( ch[ x ][ 0 ] ) + dfs( ch[ x ][ 1 ] );
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read();
	rt = build( 0, n );
	for( int i = 1 ; i <= n ; i++ )
	{
		int L = read(), R = read(), l = query_pre( L ), r = query_pre( R ), ll = query_suf( val[ l ] ), rr = query_suf( val[ r ] );
		if( l == r ) { val[ ll ] = L; continue; }
		splay( l ); splay( rr, rt );
		tag[ ch[ rr ][ 0 ] ]++; val[ ch[ rr ][ 0 ] ]++;
		ins( L );
		del( rr );
	}
	printf( "%d\n", dfs( rt ) );
}