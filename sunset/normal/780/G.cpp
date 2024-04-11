#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int mod = 1e9 + 7;

inline int read()
{
	int sc = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc;
}

inline void inc(int &x, int y) { x += y; if( x >= mod ) x -= mod; }

struct node
{
	int l, r, h, id, w;
	bool operator < ( const node &b ) const { return h < b.h || ( h == b.h && id < b.id ); }
}a[MAXN << 1];

int n, h, w, tot, ans;
map < int, int > dp;
set < int > e[MAXN << 2];

inline void ins(int x, int l, int r, int ql, int qr, int v)
{
	if( l == ql && r == qr ) { e[ x ].insert( v ); return ; }
	int mid = l + r >> 1;
	if( qr <= mid ) ins( x << 1, l, mid, ql, qr, v );
	else if( ql > mid ) ins( x << 1 | 1, mid + 1, r, ql, qr, v );
	else ins( x << 1, l, mid, ql, mid, v ), ins( x << 1 | 1, mid + 1, r, mid + 1, qr, v );
}

inline void del(int x, int l, int r, int ql, int qr, int v)
{
	if( l == ql && r == qr ) { e[ x ].erase( v ); return ; }
	int mid = l + r >> 1;
	if( qr <= mid ) del( x << 1, l, mid, ql, qr, v );
	else if( ql > mid ) del( x << 1 | 1, mid + 1, r, ql, qr, v );
	else del( x << 1, l, mid, ql, mid, v ), del( x << 1 | 1, mid + 1, r, mid + 1, qr, v );
}

inline int query(int x, int l, int r, int v)
{
	int ret = 0;
	if( !e[ x ].empty() ) ret = *( --e[ x ].end() );
	if( l ^ r )
	{
		int mid = l + r >> 1;
		if( v <= mid ) ret = max( ret, query( x << 1, l, mid, v ) );
		else ret = max( ret, query( x << 1 | 1, mid + 1, r, v ) );
	}
	return ret;
}

int main()
{
	h = read(), w = read(), n = read();
	for( int i = 1 ; i <= n ; i++ )
	{
		int u = read(), l = read(), r = read(), s = read();
		a[ ++tot ] = { l, r, u, i, u };
		if( u + s + 1 <= h + 1 ) a[ ++tot ] = { l, r, u + s + 1, -i, u };
	}
	sort( a + 1, a + tot + 1 );
	dp[ 0 ] = 1; e[ 1 ].insert( 0 );
	for( int i = 1 ; i <= tot ; i++ )
	{
		if( a[ i ].id > 0 )
		{
			int x = a[ i ].w;
			if( a[ i ].l == 1 ) inc( dp[ x ], dp[ query( 1, 1, w, a[ i ].r + 1 ) ] );
			else inc( dp[ x ], dp[ query( 1, 1, w, a[ i ].l - 1 ) ] );
			if( a[ i ].r == w ) inc( dp[ x ], dp[ query( 1, 1, w, a[ i ].l - 1 ) ] );
			else inc( dp[ x ], dp[ query( 1, 1, w, a[ i ].r + 1 ) ] );
			ins( 1, 1, w, a[ i ].l, a[ i ].r, a[ i ].w );
		}
		else
			del( 1, 1, w, a[ i ].l, a[ i ].r, a[ i ].w );
	}
	for( int i = 1 ; i <= w ; i++ ) inc( ans, dp[ query( 1, 1, w, i ) ] );
	return printf( "%d\n", ans ), 0;
}