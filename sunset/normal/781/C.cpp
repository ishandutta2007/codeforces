#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400020;

struct edge{ int to, nxt; }e[MAXN << 1];

int n, m, f[MAXN], K, st[MAXN], head[MAXN], cnt, cur, top, size[MAXN];
bool vis[MAXN];

inline void add(int x, int y) { e[ ++cnt ] = { y, head[ x ] }; head[ x ] = cnt; }
inline void addedge(int x, int y) { add( x, y ); add( y, x ); }
inline int findfa(int x) { while( x ^ f[ x ] ) x = f[ x ] = f[ f[ x ] ]; return x; }

inline void dfs(int x, int fa)
{
	st[ ++top ] = x;
	for( int i = head[ x ] ; i ; i = e[ i ].nxt )
		if( e[ i ].to ^ fa )
			dfs( e[ i ].to, x ), st[ ++top ] = x;
}

int main()
{
	scanf( "%d%d%d", &n, &m, &K );
	for( int i = 1 ; i <= n ; i++ ) f[ i ] = i;
	for( int i = 1 ; i <= m ; i++ )
	{
		int x, y;
		scanf( "%d%d", &x, &y );
		if( findfa( x ) ^ findfa( y ) ) f[ findfa( x ) ] = findfa( y ), addedge( x, y );
	}
	dfs( 1, 0 );
	int mxlen = ( 2 * n + K - 1 ) / K;
	for( int i = 0 ; i < K ; i++ )
	{
		int len = min( mxlen, top - i * mxlen );
		if( len <= 0 ) puts( "1 1" );
		else
		{
			printf( "%d", len );
			for( int j = 1 ; j <= len ; j++ ) printf( " %d", st[ i * mxlen + j ] );
			putchar( 10 );
		}
	}
}