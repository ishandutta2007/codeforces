#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int INF = 1e9 + 7;

inline int read()
{
	int sc = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc;
}

int a[MAXN], n, m, ans[MAXN << 2];

struct node
{
	vector < int > v;
	int ans;
}e[MAXN << 2];

struct Query
{
	int l, r, id;
	bool operator < ( const Query &b ) const { return r < b.r; }
}q[MAXN << 2];

inline void merge(vector < int > &a, vector < int > b, vector < int > c)
{
	int szb = b.size(), szc = c.size();
	int i = 0, j = 0;
	for( ; i < szb ; i++ )
	{
		while( j < szc && c[ j ] < b[ i ] ) a.push_back( c[ j++ ] );
		a.push_back( b[ i ] );
	}
	while( j < szc ) a.push_back( c[ j++ ] );
	return ;
}

inline void build(int x, int l, int r)
{
	e[ x ].ans = INF;
	if( l == r )
	{
		e[ x ].v.push_back( a[ l ] );
		return ;
	}
	int mid = l + r >> 1;
	build( x << 1, l, mid );
	build( x << 1 | 1, mid + 1, r );
	merge( e[ x ].v, e[ x << 1 ].v, e[ x << 1 | 1 ].v );
	for( int i = 1 ; i <= r - l ; i++ ) e[ x ].ans = min( e[ x ].ans, e[ x ].v[ i ] - e[ x ].v[ i - 1 ] );
	return ;
}

inline int query(int x, int l, int r, int ql, int qr)
{
	if( l == ql && r == qr ) return e[ x ].ans;
	int mid = l + r >> 1;
	if( qr <= mid ) return query( x << 1, l, mid, ql, qr );
	if( ql > mid ) return query( x << 1 | 1, mid + 1, r, ql, qr );
	return min( query( x << 1, l, mid, ql, mid ), query( x << 1 | 1, mid + 1, r, mid + 1, qr) ); 
}

inline void modify(int x, int l, int r, int qr, int v, int &d)
{
//	printf( "%d %d %d %d %d %d\n", x, l, r, qr, v, d );
	if( l == r )
	{
		e[ x ].ans = min( e[ x ].ans, abs( v - e[ x ].v[ 0 ] ) );
		d = min( d, e[ x ].ans );
		return ;
	}
	int mid = l + r >> 1;
	vector < int > :: iterator it = lower_bound( e[ x ].v.begin(), e[ x ].v.end(), v );
	if( ( it == e[ x ].v.end() || *it >= v + d ) && ( it == e[ x ].v.begin() || *( it - 1 ) <= v - d ) )
	{
		d = min( d, query( x, l, r, l, qr ) );
		return ;
	}
	if( qr > mid )
		modify( x << 1 | 1, mid + 1, r, qr, v, d ),
		modify( x << 1, l, mid, mid, v, d );
	else
		modify( x << 1, l, mid, qr, v, d );
	e[ x ].ans = min( e[ x ].ans, min( e[ x << 1 ].ans, e[ x << 1 | 1 ].ans ) );
}

int main()
{
	n = read();
	for( int i = 1 ; i <= n ; i++ ) a[ i ] = read();
	build( 1, 1, n );
	m = read();
	for( int i = 1 ; i <= m ; i++ ) q[ i ].l = read(), q[ i ].r = read(), q[ i ].id = i;
	sort( q + 1, q + m + 1 );
	int r = 1, d;
	for( int i = 1 ; i <= m ; i++ )
	{
		while( r < q[ i ].r ) d = INF, modify( 1, 1, n, r, a[ r + 1 ], d ), r++;
		ans[ q[ i ].id ] = query( 1, 1, n, q[ i ].l, q[ i ].r );
	}
	for( int i = 1 ; i <= m ; i++ ) printf( "%d\n", ans[ i ] );
	return 0;
}