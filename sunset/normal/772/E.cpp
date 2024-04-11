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

const int MAXN = 2005;

int n, fa[MAXN], sz[MAXN], mx[MAXN], n_leaf, now, rt = 1, st[MAXN], top;
vector < int > G[MAXN];
bool vis[MAXN];

inline int query(int x, int y, int z)
{
	printf( "%d %d %d\n", x, y, z );
	fflush( stdout );
	char opt[5];
	scanf( "%s", opt );
	return ( opt[ 0 ] == 'X' ) ? 0 : ( opt[ 0 ] == 'Y' ) ? 1 : 2;
}

inline void dfs(int x, int fa = -1)
{
	st[ ++top ] = x;
	sz[ x ] = 1; mx[ x ] = 0;
	for( auto y : G[ x ] )
		if( !vis[ y ] && y != fa ) dfs( y, x ), sz[ x ] += sz[ y ], mx[ x ] = max( mx[ x ], sz[ y ] );
}

inline int dfs2(int x, int fa = -1)
{
	int ret = x;
	for( auto y : G[ x ] )
		if( y != fa ) ret = min( ret, dfs2( y, x ) );
	return ret;
}

inline void solve(int rt)
{
	top = 0;
	dfs( rt );
	int cg = 0;
	for( int i = 1 ; i <= top ; i++ )
	{
		mx[ st[ i ] ] = max( mx[ st[ i ] ], sz[ rt ] - sz[ st[ i ] ] );
		if( !cg || mx[ cg ] > mx[ st[ i ] ] ) cg = st[ i ];
	}
	vector < int > ch, leaf;
	for( auto y : G[ cg ] ) if( y ^ fa[ cg ] ) ch.pb( y ), leaf.pb( dfs2( y, cg ) );
	if( !ch.size() ) { fa[ ++n ] = fa[ cg ]; fa[ cg ] = fa[ now ] = n; return ; }
	int t = query( leaf[ 0 ], now, leaf[ 1 ] );
	vis[ cg ] = 1;
	if( t == 2 )
	{
		if( cg ^ rt ) solve( rt );
		else fa[ ++n ] = fa[ cg ], fa[ cg ] = fa[ now ] = n;
	}
	else if( vis[ ch[ t ] ] ) fa[ ++n ] = cg, fa[ ch[ t ] ] = fa[ now ] = n;
	else solve( ch[ t ] );
}

int main()
{
#ifdef wxh010910
	//freopen( "data.in", "r", stdin );
#endif
	scanf( "%d", &n_leaf ); n = n_leaf;
	for( now = 2 ; now <= n_leaf ; now++ )
	{
		fill( vis, 0 );
		for( int j = 1 ; j <= n ; j++ ) G[ j ].clear();
		for( int j = 1 ; j <= n ; j++ ) if( fa[ j ] ) G[ j ].pb( fa[ j ] ), G[ fa[ j ] ].pb( j );
		while( fa[ rt ] ) rt = fa[ rt ];
		solve( rt );
	}
	puts( "-1" );
	for( int i = 1 ; i <= n ; i++ ) printf( "%d%c", !fa[ i ] ? -1 : fa[ i ], i == n ? '\n' : ' ' );
	return 0;
}