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

const int MAXN = 200010;

int n, a[MAXN], top;
LL ans, ret, sum[MAXN];

struct Point
{
	LL x, y;
	Point() {}
	Point(LL _x, LL _y) { x = _x; y = _y; }
	Point operator - (const Point &b) const { return Point( x - b.x, y - b.y ); }
	LL operator * (const Point &b) const { return x * b.y - y * b.x; }
}st[MAXN], p;

inline LL get(Point p, int k) { return p.x * k + p.y; }

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf( "%d", &n );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &a[ i ] ), ret += 1LL * a[ i ] * i, sum[ i ] = sum[ i - 1 ] + a[ i ];
	for( int i = 1 ; i <= n ; i++ )
	{
		p = { i, -sum[ i - 1 ] };
		while( top > 1 && ( st[ top - 1 ] - st[ top ] ) * ( p - st[ top ] ) <= 0 ) top--;
		st[ ++top ] = p;
		int l = 1, r = top;
		while( l < r )
		{
			int mid = l + r >> 1;
			if( get( st[ mid ], a[ i ] ) >= get( st[ mid + 1 ], a[ i ] ) ) r = mid;
			else l = mid + 1;
		}
		if( get( st[ l ], a[ i ] ) < get( st[ r ], a[ i ] ) ) l = r;
		ans = max( ans, get( st[ l ], a[ i ] ) + sum[ i - 1 ] - 1LL * a[ i ] * i );
	}
	top = 0;
	for( int i = n ; i ; i-- )
	{
		p = { i, -sum[ i ] };
		while( top > 1 && ( st[ top - 1 ] - st[ top ] ) * ( p - st[ top ] ) >= 0 ) top--;
		st[ ++top ] = p;
		int l = 1, r = top;
		while( l < r )
		{
			int mid = l + r >> 1;
			if( get( st[ mid ], a[ i ] ) >= get( st[ mid + 1 ], a[ i ] ) ) r = mid;
			else l = mid + 1;
		}
		if( get( st[ l ], a[ i ] ) < get( st[ r ], a[ i ] ) ) l = r;
		ans = max( ans, get( st[ l ], a[ i ] ) + sum[ i ] - 1LL * a[ i ] * i );
	}
	cout << ans + ret << endl;
}