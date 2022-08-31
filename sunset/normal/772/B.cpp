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

const int MAXN = 1005;

struct Point
{
	LL x, y;
	Point(LL _x = 0, LL _y = 0) { x = _x; y = _y; }
	Point operator - ( const Point &b ) const { return Point( x - b.x, y - b.y ); }
	LL operator * ( const Point &b ) const { return x * b.y - y * b.x; }
	inline long double len() { return sqrt( x * x + y * y ); }
}p[MAXN];

long double ans = 1e20;
int n;

inline long double dis(Point a, Point b) { return ( a - b ).len(); }
inline long double dis(Point p, Point l, Point r) { return abs( ( l - p ) * ( r - p ) ) / ( dis( l, r ) ) / 2.0; }

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf( "%d", &n );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%I64d%I64d", &p[ i ].x, &p[ i ].y );
	p[ n + 1 ] = p[ 1 ]; p[ n + 2 ] = p[ 2 ];
	for( int i = 2 ; i <= n + 1 ; i++ )
		ans = min( ans, dis( p[ i ], p[ i - 1 ], p[ i + 1 ] ) );
	printf( "%.10Lf\n", ans );
}