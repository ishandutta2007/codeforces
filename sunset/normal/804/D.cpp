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

const int MAXN = 100005;

int n, m, Q, bl[MAXN], sz[MAXN], st[MAXN], top, dep[MAXN], up[MAXN], dn[MAXN], len[MAXN], mxlen[MAXN];
vector < int > G[MAXN], cnt[MAXN], v[MAXN];
vector < LL > sum[MAXN];
map < pa, double > ans;

inline void dfs(int x, int tp, int fa = 0)
{
	bl[ st[ ++top ] = x ] = tp; dn[ x ] = dep[ x ];
	for( auto y : G[ x ] ) if( y ^ fa ) dep[ y ] = dep[ x ] + 1, dfs( y, tp, x ), dn[ x ] = max( dn[ x ], dn[ y ] );
}

inline void dfs2(int x, int fa = 0)
{
	int mx = up[ x ];
	for( auto y : G[ x ] ) if( y ^ fa ) up[ y ] = max( up[ y ], mx + 1 ), mx = max( mx, dn[ y ] + 1 );
	mx = up[ x ]; reverse( G[ x ].begin(), G[ x ].end() );
	for( auto y : G[ x ] ) if( y ^ fa ) up[ y ] = max( up[ y ], mx + 1 ), mx = max( mx, dn[ y ] + 1 );
	for( auto y : G[ x ] ) if( y ^ fa ) dfs2( y, x );
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read(), m = read(), Q = read();
	for( int i = 1, x, y ; i <= m ; i++ ) x = read(), y = read(), G[ x ].pb( y ), G[ y ].pb( x );
	for( int i = 1 ; i <= n ; i++ ) if( !bl[ i ] )
	{
		top = 0;
		dfs( i, i );
		for( int j = 1 ; j <= top ; j++ ) dn[ st[ j ] ] -= dep[ st[ j ] ];
		dfs2( i );
		for( int j = 1 ; j <= top ; j++ ) len[ st[ j ] ] = max( up[ st[ j ] ], dn[ st[ j ] ] ), mxlen[ i ] = max( up[ st[ j ] ] + dn[ st[ j ] ], mxlen[ i ] ), v[ i ].pb( len[ st[ j ] ] );
		sz[ i ] = top; sum[ i ].resize( sz[ i ] + 1 ); cnt[ i ].resize( sz[ i ] + 1 );
		for( int j = 1 ; j <= top ; j++ ) cnt[ i ][ len[ st[ j ] ] ]++, sum[ i ][ len[ st[ j ] ] ] += len[ st[ j ] ];
		for( int j = sz[ i ] - 1 ; ~j ; j-- ) cnt[ i ][ j ] += cnt[ i ][ j + 1 ], sum[ i ][ j ] += sum[ i ][ j + 1 ];
	}
	while( Q-- )
	{
		int x = bl[ read() ], y = bl[ read() ];
		if( x == y ) { puts( "-1" ); continue; }
		if( sz[ x ] > sz[ y ] || ( sz[ x ] == sz[ y ] && x > y ) ) swap( x, y );
		if( ans.find( mp( x, y ) ) != ans.end() ) { printf( "%.8lf\n", ans[ mp( x, y ) ] ); continue; }
		double &ret = ans[ mp( x, y ) ];
		int least_len = max( mxlen[ x ], mxlen[ y ] );
		for( auto c : v[ x ] )
		{
			int d = max( 0, min( sz[ y ], least_len - c - 1 ) );
			ret += 1LL * least_len * ( sz[ y ] - cnt[ y ][ d ] ) + 1LL * ( c + 1 ) * cnt[ y ][ d ] + sum[ y ][ d ];
		}
		ret /= sz[ x ]; ret /= sz[ y ];
		printf( "%.8lf\n", ret );
	}
}