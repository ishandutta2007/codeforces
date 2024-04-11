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

int n, m, ans = 1, rt = 1, col[MAXN], vis[MAXN];
vector < int > v[MAXN], G[MAXN];

inline void dfs(int x, int fa = 0)
{
	int cur = 1;
	for( auto c : v[ x ] ) if( col[ c ] ) vis[ col[ c ] ] = x;
	for( auto c : v[ x ] ) if( !col[ c ] ) { while( vis[ cur ] == x ) cur++; col[ c ] = cur++; }
	for( auto y : G[ x ] ) if( y ^ fa ) dfs( y, x );
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read(), m = read();
	for( int i = 1 ; i <= n ; i++ )
		for( int x = read() ; x ; x-- )
			ans < x ? ( ans = x, rt = i ) : 0, v[ i ].pb( read() );
	for( int i = 1, x, y ; i < n ; i++ ) x = read(), y = read(), G[ x ].pb( y ), G[ y ].pb( x );
	printf( "%d\n", ans );
	dfs( rt );
	for( int i = 1 ; i <= m ; i++ ) printf( "%d%c", max( col[ i ], 1 ), i == m ? '\n' : ' ' );
}