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

int n, p, a[MAXN], b[MAXN];
LL tot;

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf( "%d%d", &n, &p );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d%d", &a[ i ], &b[ i ] ), tot += a[ i ];
	if( tot <= p ) return puts( "-1" ), 0;
	long double l = 0, r = 1e18;
	for( int t = 0 ; t < 200 ; t++ )
	{
		long double mid = ( l + r ) / 2, ret = p * mid;
		for( int i = 1 ; i <= n ; i++ )
			if( a[ i ] * mid >= b[ i ] )
				ret -= a[ i ] * mid - b[ i ];
		if( ret < 0 ) r = mid;
		else l = mid;
	}
	printf( "%Lf\n", l );
}