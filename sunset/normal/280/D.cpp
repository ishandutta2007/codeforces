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

const int MAXN = 100010;

int n, Q, a[MAXN], top, sl[MAXN], sr[MAXN];

struct info
{
	int l, r, s;
	info(int _l = 0, int _r = 0, int _s = 0) { l = _l; r = _r; s = _s; }
	info operator + ( const info &b ) const { return info( l, b.r, s + b.s ); }
	bool operator < ( const info &b ) const { return s < b.s; }
	inline void rev() { s = -s; }
	inline void print() { printf( "l = %d, r = %d, s = %d\n", l, r, s ); }
};

struct node
{
	info sum;
	info mxsum, mxl, mxr;
	info mnsum, mnl, mnr;
	bool rev = 0;
	inline void re()
	{
		rev ^= 1;
		sum.rev();
		mxsum.rev(); mxl.rev(); mxr.rev();
		mnsum.rev(); mnl.rev(); mnr.rev();
		swap( mxsum, mnsum );
		swap( mxl, mnl );
		swap( mxr, mnr );
	}
}e[MAXN << 2];

inline node merge(node l, node r)
{
	node t;
	t.sum = l.sum + r.sum;
	t.mxsum = max( l.mxr + r.mxl, max( l.mxsum, r.mxsum ) );
	t.mxl = max( l.mxl, l.sum + r.mxl );
	t.mxr = max( r.mxr, l.mxr + r.sum );
	t.mnsum = min( l.mnr + r.mnl, min( l.mnsum, r.mnsum ) );
	t.mnl = min( l.mnl, l.sum + r.mnl );
	t.mnr = min( r.mnr, l.mnr + r.sum );
	return t;
}

inline node single(int pos, int v)
{
	node t;
	t.sum = t.mxsum = t.mxl = t.mxr = t.mnsum = t.mnl = t.mnr = info( pos, pos, v );
	t.rev = 0;
	return t;
}

inline void pushup(int x) { e[ x ] = merge( e[ x << 1 ], e[ x << 1 | 1 ] ); }

inline void build(int x, int l, int r)
{
	if( l == r ) { e[ x ] = single( l, a[ l ] ); return ; }
	int mid = l + r >> 1;
	build( x << 1, l, mid ); build( x << 1 | 1, mid + 1, r );
	pushup( x );
}

inline void pushdown(int x)
{
	if( e[ x ].rev )
	{
		e[ x ].rev = 0;
		e[ x << 1 ].re();
		e[ x << 1 | 1 ].re();
	}
}

inline void modify(int x, int l, int r, int p, int v)
{
	if( l == r ) { e[ x ] = single( p, v ); return ; }
	pushdown( x );
	int mid = l + r >> 1;
	if( p <= mid ) modify( x << 1, l, mid, p, v );
	else modify( x << 1 | 1, mid + 1, r, p, v );
	pushup( x );
}

inline node query(int x, int l, int r, int ql, int qr)
{
	if( l == ql && r == qr ) return e[ x ];
	pushdown( x );
	int mid = l + r >> 1;
	if( qr <= mid ) return query( x << 1, l, mid, ql, qr );
	if( ql > mid ) return query( x << 1 | 1, mid + 1, r, ql, qr );
	return merge( query( x << 1, l, mid, ql, mid ), query( x << 1 | 1, mid + 1, r, mid + 1, qr ) );
}

inline void getrev(int x, int l, int r, int ql, int qr)
{
	if( l == ql && r == qr ) { e[ x ].re(); return ; }
	pushdown( x );
	int mid = l + r >> 1;
	if( qr <= mid ) getrev( x << 1, l, mid, ql, qr );
	else if( ql > mid ) getrev( x << 1 | 1, mid + 1, r, ql, qr );
	else getrev( x << 1, l, mid, ql, mid ), getrev( x << 1 | 1, mid + 1, r, mid + 1, qr );
	pushup( x );
}

inline void print(int x, int l, int r)
{
	printf( "L = %d R = %d\n", l, r );
	if( l == r ) return ;
	int mid = l + r >> 1;
	print( x << 1, l, mid ); print( x << 1 | 1, mid + 1, r );
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read();
	for( int i = 1 ; i <= n ; i++ ) a[ i ] = read();
	build( 1, 1, n );
	Q = read();
	//print( 1, 1, n );
	while( Q-- )
	{
		if( !read() )
		{
			int p = read(), v = read();
			modify( 1, 1, n, p, v );
		}
		else
		{
			int l = read(), r = read(), k = read(), ret = 0;
			while( k-- )
			{
				node t = query( 1, 1, n, l, r );
				if( t.mxsum.s < 0 ) break;
				ret += t.mxsum.s;
				sl[ ++top ] = t.mxsum.l, sr[ top ] = t.mxsum.r;
				getrev( 1, 1, n, sl[ top ], sr[ top ] );
			}
			printf( "%d\n", ret );
			while( top )
				getrev( 1, 1, n, sl[ top ], sr[ top ] ), top--;
		}
	}
}