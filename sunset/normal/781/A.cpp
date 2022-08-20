#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200020;

struct edge { int to, nxt; }e[MAXN << 1];

int d[MAXN], head[MAXN], cnt, n, ans, rt, col[MAXN];

inline void add(int x, int y) { e[ ++cnt ] = { y, head[ x ] }; head[ x ] = cnt; }
inline void addedge(int x, int y) { add( x, y ); add( y, x ); d[ x ]++; d[ y ]++; }

inline void dfs(int x, int fa, int cx, int cfa)
{
	int c = 1;
	for( int i = head[ x ] ; i ; i = e[ i ].nxt )
		if( e[ i ].to ^ fa )
		{
			while( c == cx || c == cfa ) c++;
			col[ e[ i ].to ] = c;
			dfs( e[ i ].to, x, c, cx );
			c++;
		}
}

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i < n ; i++ ) { int x, y; scanf( "%d%d", &x, &y ); addedge( x, y ); }
	for( int i = 1 ; i <= n ; i++ )
		if( d[ i ] + 1 > ans ) ans = d[ i ] + 1, rt = i;
	printf( "%d\n", ans );
	int c;
	col[ rt ] = c = 1;
	for( int i = head[ rt ] ; i ; i = e[ i ].nxt )
		col[ e[ i ].to ] = ++c, dfs( e[ i ].to, rt, c, 1 );
	for( int i = 1 ; i <= n ; i++ ) printf( "%d ", col[ i ] );
}