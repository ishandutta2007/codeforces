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

const int MAXN = 500005;

int n, tag[MAXN << 2], id[MAXN];
pa a[MAXN], mn[MAXN << 2];
set < int > in, de, ze;

inline void pushup(int x) { mn[ x ] = min( mn[ x << 1 ], mn[ x << 1 | 1 ] ); mn[ x ].xx += tag[ x ]; }

inline void build(int x, int l, int r)
{
	if( l == r ) { mn[ x ] = mp( a[ l ].xx, l ); return ; }
	int mid = l + r >> 1;
	build( x << 1, l, mid ); build( x << 1 | 1, mid + 1, r );
	pushup( x );
}

inline void modify(int x, int l, int r, int ql, int qr, int v)
{
	if( l == ql && r == qr )
	{
		mn[ x ].xx += v; tag[ x ] += v;
		return ;
	}
	int mid = l + r >> 1;
	if( qr <= mid ) modify( x << 1, l, mid, ql, qr, v );
	else if( ql > mid ) modify( x << 1 | 1, mid + 1, r, ql, qr, v );
	else modify( x << 1, l, mid, ql, mid, v ), modify( x << 1 | 1, mid + 1, r, mid + 1, qr, v );
	pushup( x );
}

inline pa query(int x, int l, int r, int ql, int qr)
{
	if( l == ql && r == qr ) return mn[ x ];
	int mid = l + r >> 1; pa ret;
	if( qr <= mid ) ret = query( x << 1, l, mid, ql, qr );
	else if( ql > mid ) ret = query( x << 1 | 1, mid + 1, r, ql, qr );
	else ret = min( query( x << 1, l, mid, ql, mid ), query( x << 1 | 1, mid + 1, r, mid + 1, qr ) );
	return mp( ret.xx + tag[ x ], ret.yy );
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read();
	for( int i = 1 ; i <= n ; i++ ) a[ i ].xx = read(), a[ i ].yy = i;
	sort( a + 1, a + n + 1 );
	for( int i = 1 ; i <= n ; i++ ) id[ a[ i ].yy ] = i;
	build( 1, 1, n );
	for( int i = 1 ; i <= n ; i++ )
	{
		int x = id[ i ]; pa v = query( 1, 1, n, x, x );
		if( !v.xx ) ze.insert( x );
		else if( v.xx > 0 )
		{
			in.insert( x );
			modify( 1, 1, n, x, n, -1 );
			pa t = query( 1, 1, n, x, n );
			if( t.xx < 0 )
			{
				in.erase( t.yy ); ze.insert( t.yy );
				modify( 1, 1, n, t.yy, n, 1 );
			}
		}
		else
		{
			de.insert( x );
			modify( 1, 1, n, x, n, 1 );
			int p = *--de.end();
			if( a[ p ].xx == 1 - de.size() )
			{
				de.erase( p ); ze.insert( p );
				modify( 1, 1, n, p, n, -1 );
			}
			else if( ze.size() )
			{
				int q = *ze.begin();
				ze.erase( q ); in.insert( q );
				modify( 1, 1, n, q, n, -1 );
			}
		}
		printf( "%d\n", in.size() - de.size() );
	}
}