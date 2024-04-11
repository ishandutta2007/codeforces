#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int f[MAXN], g[MAXN], h[MAXN], m, n;

bool vis[MAXN];

inline int dfs(int x) { return g[ x ] ? g[ x ] : g[ x ] = dfs( f[ x ] ); }

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &f[ i ] );
	for( int i = 1 ; i <= n ; i++ ) if( i == f[ i ] ) g[ h[ ++m ] = i ] = m;
	if( !m ) return printf( "-1\n" ), 0;
	for( int i = 1 ; i <= n ; i++ )
	{
		int cur = i;
		while( f[ cur ] ^ cur )
		{
			if( vis[ cur ] ) return printf( "-1\n" ), 0;
			vis[ cur ] = 1;
			cur = f[ cur ];
		}
	}
	for( int i = 1 ; i <= n ; i++ ) g[ i ] = dfs( i );
	printf( "%d\n", m );
	for( int i = 1 ; i <= n ; i++ ) printf( "%d%c", g[ i ], i == n ? '\n' : ' ' );
	for( int i = 1 ; i <= m ; i++ ) printf( "%d%c", h[ i ], i == m ? '\n' : ' ' );
}