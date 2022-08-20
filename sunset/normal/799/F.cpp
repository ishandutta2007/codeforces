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

const int MAXN = 200005;

struct node { int v, c; LL s; node(int _v = 0, int _c = 0, LL _s = 0) { v = _v; c = _c; s = _s; } };
int n, m, l[MAXN], r[MAXN], cnt[MAXN];
vector < int > add[MAXN], del[MAXN];
LL ans;

inline node merge(node x, node y) { if( x.v < y.v ) return x; if( x.v > y.v ) return y; return node( x.v, x.c + y.c, x.s + y.s ); }

struct tree
{
	node e[MAXN << 2];
	int tag[MAXN << 2], type;

	inline void pushup(int x) { e[ x ] = merge( e[ x << 1 ], e[ x << 1 | 1 ] ); e[ x ].v += tag[ x ]; }

	inline void build(int x, int l, int r)
	{
		tag[ x ] = 0;
		if( l == r ) { e[ x ].v = 0; e[ x ].c = ( l & 1 ) == type; e[ x ].s = e[ x ].c * l; return ; }
		int mid = l + r >> 1;
		build( x << 1, l, mid ); build( x << 1 | 1, mid + 1, r );
		pushup( x );
	}

	inline void modify(int x, int l, int r, int ql, int qr, int v)
	{
		if( ql > qr ) return ;
		if( l == ql && r == qr ) { e[ x ].v += v; tag[ x ] += v; return ; }
		int mid = l + r >> 1;
		if( qr <= mid ) modify( x << 1, l, mid, ql, qr, v );
		else if( ql > mid ) modify( x << 1 | 1, mid + 1, r, ql, qr, v );
		else modify( x << 1, l, mid, ql, mid, v ), modify( x << 1 | 1, mid + 1, r, mid + 1, qr, v );
		pushup( x );
	
	}

	inline node query(int x, int l, int r, int ql, int qr)
	{
		if( l == ql && r == qr ) return e[ x ];
		int mid = l + r >> 1; node ret;
		if( qr <= mid ) ret = query( x << 1, l, mid, ql, qr );
		else if( ql > mid ) ret = query( x << 1 | 1, mid + 1, r, ql, qr );
		else ret = merge( query( x << 1, l, mid, ql, mid ), query( x << 1 | 1, mid + 1, r, mid + 1, qr ) );
		ret.v += tag[ x ];
		return ret;
	}
}t[2];

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	m = read(), n = read(); t[ 1 ].type = 1;
	for( int i = 1 ; i <= m ; i++ ) cnt[ l[ i ] = read() ]++, cnt[ ( r[ i ] = read() ) + 1 ]--, add[ l[ i ] ].pb( i ), del[ r[ i ] ].pb( i );
	for( int i = 1, cur = 0 ; i <= n ; i++ )
	{
		if( cnt[ i ] += cnt[ i - 1 ] )
		{
			for( int j = 1 ; j <= cur ; j++ )
				ans -= 1LL * j * ( cur - j + 1 );
			cur = 0;
		}
		else cur++;
		if( i == n )
			for( int j = 1 ; j <= cur ; j++ )
				ans -= 1LL * j * ( cur - j + 1 );
	}
	for( int bit = 0 ; bit < 2 ; bit++ )
	{
		t[ 0 ].build( 1, 1, n ); t[ 1 ].build( 1, 1, n );
		for( int i = 1 ; i <= m ; i++ )
			t[ bit ^ 1 ].modify( 1, 1, n, l[ i ], r[ i ], 1 );
		for( int i = 2 - bit ; i <= n ; i += 2 )
		{
			for( auto j : add[ i - 1 ] )
				t[ 0 ].modify( 1, 1, n, 1, l[ j ] - 1, 1 ), t[ 1 ].modify( 1, 1, n, 1, l[ j ] - 1, 1 );
			for( auto j : del[ i - 1 ] )
			{
				if( ( l[ j ] & 1 ) ^ bit ) t[ 0 ].modify( 1, 1, n, 1, l[ j ] - 1, -1 ), t[ 1 ].modify( 1, 1, n, 1, l[ j ] - 1, -1 );
				else t[ 0 ].modify( 1, 1, n, 1, l[ j ] - 1, 1 ), t[ 1 ].modify( 1, 1, n, 1, l[ j ] - 1, 1 );
				t[ bit ].modify( 1, 1, n, l[ j ], r[ j ], 1 );
				t[ bit ^ 1 ].modify( 1, 1, n, l[ j ], r[ j ], -1 );
			}
			node tt = merge( t[ 0 ].query( 1, 1, n, 1, i ), t[ 1 ].query( 1, 1, n, 1, i ) );
			if( !tt.v ) ans += 1LL * ( i + 1 ) * tt.c - tt.s;
		}
	}
	cout << ans << endl;
}