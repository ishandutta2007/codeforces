#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;

int val[MAXN], head[MAXN], pos[MAXN];
int n, v[MAXN], fa[MAXN], rt, tot, last, cnt;
bool flag, can[MAXN];

struct edge
{
	int to, nxt;
}e[MAXN << 1];

inline void addedge(int x, int y) { e[ ++cnt ].to = y; e[ cnt ].nxt = head[ x ]; head[ x ] = cnt; }

inline void dfs(int x)
{
	if( flag ) return ;
	val[ x ] = v[ x ];
	for( int i = head[ x ] ; i ; i = e[ i ].nxt )
	{
		dfs( e[ i ].to );
		val[ x ] += val[ e[ i ].to ];
		pos[ x ] = max( pos[ x ], pos[ e[ i ].to ] );
	}
	if( x == rt ) return ;
	if( flag ) return ;
	if( val[ x ] == tot * 2 && pos[ x ] ) printf( "%d %d\n", x, pos[ x ] ), flag = 1;
	else if( val[ x ] == tot ) pos[ x ] = x;
}

inline void dfs2(int x)
{
	if( flag ) return ;
	for( int i = head[ x ] ; i ; i = e[ i ].nxt )
		dfs2( e[ i ].to );
	if( flag ) return ;
	if( x == rt ) return ;
	if( val[ x ] == tot )
	{
		if( !can[ x ] && last ) printf( "%d %d\n", last, x ), flag = 1;
		can[ fa[ x ] ] = 1;
		last = x;
	}
	if( can[ x ] ) can[ fa[ x ] ] = 1;
}

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i <= n ; i++ )
	{
		scanf( "%d%d", &fa[ i ], &v[ i ] ); tot += v[ i ];
		if( fa[ i ] ) addedge( fa[ i ], i );
		else rt = i;
	}
	if( tot % 3 ) return puts( "-1" ), 0;
	tot /= 3;
	dfs( rt );
	if( flag ) return 0;
	dfs2( rt );
	if( flag ) return 0;
	return puts( "-1" ), 0;
}