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

const int MAXN = 300005;

int n, mx, a[MAXN], b[MAXN], ans[MAXN];

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read();
	for( int i = 1 ; i <= n ; i++ ) a[ i ] = read(), mx = max( mx, a[ i ] );
	for( int i = 2 ; i < n ; i++ ) b[ i ] = min( a[ i ], max( a[ i - 1 ], a[ i + 1 ] ) );
	ans[ n - 1 ] = mx;
	mx = ( n & 1 ) ? a[ n + 1 >> 1 ] : 0;
	for( int i = n - ( n & 1 ) ; i ; i -= 2 )
	{
		int l = i >> 1, r = n - ( i >> 1 ) + 1;
		mx = max( mx, max( a[ l ], a[ r ] ) );
		ans[ n - i ] = mx;
	}
	mx = 0;
	for( int i = n - ( ( n & 1 ) ^ 1 ) ; i ^ 1 ; i -= 2 )
	{
		int l = i + 1 >> 1, r = n - ( i >> 1 );
		mx = max( mx, max( b[ l ], b[ r ] ) );
		ans[ n - i ] = mx;
	}
	for( int i = 0 ; i < n ; i++ ) printf( "%d%c", ans[ i ], i == n - 1 ? '\n' : ' ' );
	return 0;
}