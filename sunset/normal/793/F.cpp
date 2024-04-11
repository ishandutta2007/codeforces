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

const int MAXN = 100010;
const int INF = 0x3f3f3f3f;

inline int read()
{
	int sc = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc;
}

int mx[MAXN << 2], tag[MAXN << 2], n, m, ans[MAXN], Q;
vector < int > seg[MAXN];
vector < pa > q[MAXN];

inline int min(int x, int y) { return !x ? y : ( ( x <= y ) ? x : y ); }

inline void pushup(int x) { mx[ x ] = max( mx[ x << 1 ], mx[ x << 1 | 1 ] ); }

inline void pushdown(int x)
{
	if( tag[ x ] )
	{
		tag[ x << 1 ] = min( tag[ x << 1 ], tag[ x ] );
		tag[ x << 1 | 1 ] = min( tag[ x << 1 | 1 ], tag[ x ] );
		mx[ x << 1 ] = min( mx[ x << 1 ], tag[ x ] );
		mx[ x << 1 | 1 ] = min( mx[ x << 1 | 1 ], tag[ x ] );
		tag[ x ] = 0;
	}
}

inline void modify(int x, int l, int r, int ql, int qr, int v)
{
	if( l == ql && r == qr ) { tag[ x ] = min( tag[ x ], v ); mx[ x ] = min( mx[ x ], v ); return ; }
	pushdown( x ); int mid = l + r >> 1;
	if( qr <= mid ) modify( x << 1, l, mid, ql, qr, v );
	else if( ql > mid ) modify( x << 1 | 1, mid + 1, r, ql, qr, v );
	else modify( x << 1, l, mid, ql, mid, v ), modify( x << 1 | 1, mid + 1, r, mid + 1, qr, v );
	pushup( x );
}

inline int query(int x, int l, int r, int v)
{
	if( l == r ) return l;
	pushdown( x ); int mid = l + r >> 1;
	return mx[ x << 1 ] <= v ? query( x << 1 | 1, mid + 1, r, v ) : query( x << 1, l, mid, v );
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read(), m = read();
	for( int i = 1, l, r ; i <= m ; i++ ) { l = read(), r = read(); if( l ^ r ) seg[ l ].pb( r ); }
	Q = read();
	for( int i = 1, l, r ; i <= Q ; i++ ) l = read(), r = read(), q[ l ].pb( mp( r, i ) );
	for( int i = n ; i ; i-- )
	{
		modify( 1, 1, n, i, i, INF );
		for( auto r : seg[ i ] ) modify( 1, 1, n, i, r - 1, r );
		for( auto x : q[ i ] ) ans[ x.yy ] = query( 1, 1, n, x.xx );
	}
	for( int i = 1 ; i <= Q ; i++ ) printf( "%d\n", ans[ i ] );
	return 0;
}