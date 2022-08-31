#include <bits/stdc++.h>

using namespace std;

const int MAXN = 32;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

int d[MAXN], head[MAXN], cnt, X[MAXN], Y[MAXN], n, vis[MAXN][4];

struct edge
{
	int to, nxt;
}e[MAXN << 1];

inline void add(int x, int y) { e[ ++cnt ].to = y; e[ cnt ].nxt = head[ x ]; head[ x ] = cnt; d[ y ]++; }
inline void addedge(int x, int y) { add( x, y ); add( y, x ); }

inline void dfs(int x, int fa, int dep)
{
	for( int i = head[ x ] ; i ; i = e[ i ].nxt ) if( e[ i ].to ^ fa )
	{
		int y = e[ i ].to;
		for( int j = 0 ; j < 4 ; j++ )
			if( !vis[ x ][ j ] )
			{
				vis[ x ][ j ] = 1;
				vis[ y ][ j ^ 1 ] = 1;
				X[ y ] = X[ x ] + dx[ j ] * ( 1 << dep );
				Y[ y ] = Y[ x ] + dy[ j ] * ( 1 << dep );
				dfs( y, x, dep - 1 );
				break;
			}
	}
}

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i < n ; i++ )
	{
		int u, v;
		scanf( "%d%d", &u, &v );
		addedge( u, v );
	}
	for( int i = 1 ; i <= n ; i++ ) if( d[ i ] >= 5 ) return printf( "NO\n" ), 0;
	printf( "YES\n" ); 
	dfs( 1, 0, 30 );
	for( int i = 1 ; i <= n ; i++ ) printf( "%d %d\n", X[ i ], Y[ i ] );
}