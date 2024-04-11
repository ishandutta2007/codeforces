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

struct node { LL sum[10]; int nxt[10]; } e[MAXN << 2];
int n, Q, nxt1[10], nxt2[10];
LL sum[10];

inline void pushup(int x)
{	
	for( int i = 0 ; i < 10 ; i++ ) e[ x ].sum[ i ] = 0;
	for( int i = 0 ; i < 10 ; i++ ) e[ x ].sum[ e[ x << 1 ].nxt[ i ] ] += e[ x << 1 ].sum[ i ];
	for( int i = 0 ; i < 10 ; i++ ) e[ x ].sum[ e[ x << 1 | 1 ].nxt[ i ] ] += e[ x << 1 | 1 ].sum[ i ];
}

inline void pushdown(int x, int l, int r)
{
	fill( sum, 0 );
	if( l ^ r )
	{
		for( int i = 0 ; i < 10 ; i++ ) nxt1[ i ] = e[ x ].nxt[ e[ x << 1 ].nxt[ i ] ],	nxt2[ i ] = e[ x ].nxt[ e[ x << 1 | 1 ].nxt[ i ] ];
		for( int i = 0 ; i < 10 ; i++ ) e[ x << 1 ].nxt[ i ] = nxt1[ i ], e[ x << 1 | 1 ].nxt[ i ] = nxt2[ i ];
	}
	for( int i = 0 ; i < 10 ; i++ ) sum[ e[ x ].nxt[ i ] ] += e[ x ].sum[ i ];
	for( int i = 0 ; i < 10 ; i++ ) e[ x ].sum[ i ] = sum[ i ], e[ x ].nxt[ i ] = i;
}

inline void build(int x, int l, int r)
{
	for( int i = 0 ; i < 10 ; i++ ) e[ x ].nxt[ i ] = i;
	if( l == r )
	{
		int c = read(), cur = 1;
		while( c ) e[ x ].sum[ c % 10 ] += cur, c /= 10, cur *= 10;
		return ;
	}
	int mid = l + r >> 1;
	build( x << 1, l, mid ); build( x << 1 | 1, mid + 1, r );
	pushup( x );
}

inline void modify(int x, int l, int r, int ql, int qr, int u, int v)
{
	pushdown( x, l, r );
	if( l == ql && r == qr )
	{
		e[ x ].nxt[ u ] = v;
		pushdown( x, l, r );
		return ;
	}
	int mid = l + r >> 1;
	if( qr <= mid ) modify( x << 1, l, mid, ql, qr, u, v );
	else if( ql > mid ) modify( x << 1 | 1, mid + 1, r, ql, qr, u, v );
	else modify( x << 1, l, mid, ql, mid, u, v ), modify( x << 1 | 1, mid + 1, r, mid + 1, qr, u, v );
	pushup( x );
}

inline LL query(int x, int l, int r, int ql, int qr)
{
	pushdown( x, l, r );
	if( l == ql && r == qr )
	{
		LL ret = 0;
		for( int i = 0 ; i < 10 ; i++ ) ret += e[ x ].sum[ i ] * i;
		return ret;
	}
	int mid = l + r >> 1;
	if( qr <= mid ) return query( x << 1, l, mid, ql, qr );
	if( ql > mid ) return query( x << 1 | 1, mid + 1, r, ql, qr );
	return query( x << 1, l, mid, ql, mid ) + query( x << 1 | 1, mid + 1, r, mid + 1, qr );
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read(), Q = read();
	build( 1, 1, n );
	while( Q-- )
	{
		int opt = read(), l = read(), r = read();
		if( opt == 1 )
		{
			int x = read(), y = read();
			modify( 1, 1, n, l, r, x, y );
		}
		else printf( "%lld\n", query( 1, 1, n, l, r ) );
	}
	return 0;
}