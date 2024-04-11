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

const int MAXN = 5005;
const int MAXM = 2000005;
const int mod = 1e9 + 7;

int n, a, b, len[MAXN], can[MAXM], id_cnt, L[MAXN], R[MAXN], C[MAXN][MAXN];
int dfn[MAXN], scc[MAXN], low[MAXN], tim, num, st[MAXN], top, w[MAXN], ans;
vector < int > G[MAXN], id[MAXN], scc_bit[MAXN], v[MAXN];
char ch[MAXM];

inline void inc(int &x, int y) { x += y; if( x >= mod ) x -= mod; }

inline void dfs(int x)
{
	dfn[ x ] = low[ x ] = ++tim; st[ ++top ] = x;
	for( auto y : G[ x ] )
		if( !dfn[ y ] ) dfs( y ), low[ x ] = min( low[ x ], low[ y ] );
		else if( !scc[ y ] ) low[ x ] = min( low[ x ], dfn[ y ] );
	if( dfn[ x ] == low[ x ] )
	{
		num++; int t = 0;
		while( t ^ x )
		{
			scc[ t = st[ top-- ] ] = num;
			w[ num ] = __gcd( w[ num ], len[ t ] );
			v[ num ].pb( t );
		}
		scc_bit[ num ].resize( w[ num ] );
		for( auto y : v[ num ] )
			for( int d = 0 ; d < len[ y ] ; d++ ) if( can[ id[ y ][ d ] ] ) scc_bit[ num ][ d % w[ num ] ] = 1;
	}
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read(), a = read(), b = read();
	for( int i = 0 ; i <= n ; i++ )
	{
		C[ i ][ 0 ] = 1;
		for( int j = 1 ; j <= i ; j++ ) inc( C[ i ][ j ] = C[ i - 1 ][ j ], C[ i - 1 ][ j - 1 ] );
	}
	for( int i = 1 ; i <= n ; i++ )
	{
		scanf( "%s", ch + 1 );
		for( int j = 1 ; j <= n ; j++ ) if( ch[ j ] == '1' ) G[ i ].pb( j );
	}
	for( int i = 1 ; i <= n ; i++ )
	{
		len[ i ] = read(); scanf( "%s", ch );
		for( int j = 0 ; j < len[ i ] ; j++ ) id[ i ].pb( ++id_cnt ), can[ id_cnt ] = ch[ j ] == '1', L[ i ] += can[ id_cnt ];
	}
	for( int i = 1 ; i <= n ; i++ ) if( !dfn[ i ] ) dfs( i );
	for( int i = num ; i > 1 ; i-- )
	{
		int g = __gcd( w[ i ], w[ i - 1 ] );
		w[ i - 1 ] = g;
		for( int j = 0 ; j < w[ i ] ; j++ )	scc_bit[ i - 1 ][ j % g ] |= scc_bit[ i ][ j ];
	}
	for( int i = 1 ; i <= n ; i++ )
	{
		int x = scc[ i ];
		for( int j = 0 ; j < len[ i ] ; j++ )
			R[ i ] += scc_bit[ x ][ j % w[ x ] ];
	}
	for( int i = 1 ; i <= n ; i++ )
	{
		int t1 = 0, t2 = 0;
		for( int j = 1 ; j <= n ; j++ ) if( L[ j ] > R[ i ] ) t1++;
		if( t1 >= a ) continue;
		for( int j = 1 ; j <= n ; j++ ) if( L[ j ] <= R[ i ] && mp( R[ j ], j ) > mp( R[ i ], i ) ) t2++;
		for( int j = 0 ; j < b && j <= t2 && j + t1 < a ; j++ )
		   inc( ans, 1LL * C[ t2 ][ j ] * C[ t1 ][ b - j - 1 ] % mod );	
	}
	return printf( "%d\n", ans ), 0;
}