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

const int MAXN = 1000000;
const int mod = 1e9 + 7;

inline void inc(int &x, int y) { x += y; if( x >= mod ) x -= mod; }
inline void dec(int &x, int y) { x -= y; if( x < 0 ) x += mod; }

int n, f0[MAXN], f1[MAXN], f2[MAXN], p2[MAXN], p0[6], ans[MAXN];
LL ret;

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf( "%d", &n );
	p0[ 0 ] = p2[ 0 ] = 1;
	for( int i = 1 ; i < 6 ; i++ ) p0[ i ] = p0[ i - 1 ] * 10;
	for( int i = 1 ; i < MAXN ; i++ ) p2[ i ] = p2[ i - 1 ], inc( p2[ i ], p2[ i - 1 ] );
	for( int i = 1, x ; i <= n ; i++ ) scanf( "%d", &x ), inc( f0[ x ], 1 ), inc( f1[ x ], x ), inc( f2[ x ], 1LL * x * x % mod );
	for( int j = 0 ; j < 6 ; j++ )
		for( int i = MAXN - 1 ; i ; i-- ) if( i / p0[ j ] % 10 )
			inc( f0[ i - p0[ j ] ], f0[ i ] ), inc( f1[ i - p0[ j ] ], f1[ i ] ), inc( f2[ i - p0[ j ] ], f2[ i ] );
	for( int i = 0 ; i < MAXN ; i++ )
		if( !f0[ i ] ) continue;
		else if( f0[ i ] == 1 ) ans[ i ] = f2[ i ];
		else ans[ i ] = 1LL * p2[ f0[ i ] - 1 ] * f2[ i ] % mod, inc( ans[ i ], 1LL * p2[ f0[ i ] - 2 ] * ( 1LL * f1[ i ] * f1[ i ] % mod - f2[ i ] + mod ) % mod );
	for( int j = 0 ; j < 6 ; j++ )
		for( int i = 0 ; i < MAXN ; i++ ) if( i / p0[ j ] % 10 != 9 )
			dec( ans[ i ], ans[ i + p0[ j ] ] );
	for( int i = 0 ; i < MAXN ; i++ ) ret ^= 1LL * ans[ i ] * i;
	cout << ret << endl;
	return 0;
}