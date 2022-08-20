#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill( x, y ) memset( x, y, sizeof x )
#define copy( x, y ) memcpy( x, y, sizeof x )
using namespace std;

typedef unsigned long long LL;
typedef pair < int, int > pa;

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while( ch < '0' || ch > '9' ) { if( ch == '-' ) f = -1; ch = getchar(); }
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

const int MAXN = 65537;
const long double pi = acos( -1 );

int n, m, mod, ret, f[MAXN], g[MAXN], cf[MAXN], cg[MAXN], h[MAXN];

namespace FFT
{
	struct E
	{
		long double x, y;
		E(long double _x = 0, long double _y = 0) { x = _x; y = _y; }
		E operator + ( const E &b ) const { return E( x + b.x, y + b.y ); }
		E operator - ( const E &b ) const { return E( x - b.x, y - b.y ); }
		E operator * ( const E &b ) const { return E( x * b.x - y * b.y, x * b.y + y * b.x ); }
		E operator / ( const int &b ) const { return E( x / b, y / b ); }
	}a[MAXN], b[MAXN];

	int R[MAXN], n, L;

	inline void getR() { for( int i = 0 ; i < n ; i++ ) R[ i ] = ( R[ i >> 1 ] >> 1 ) | ( ( i & 1 ) << L - 1 ); }

	inline void FFT(E *x, int f)
	{
		for( int i = 0 ; i < n ; i++ ) if( i < R[ i ] ) swap( x[ i ], x[ R[ i ] ] );
		for( int i = 1 ; i < n ; i <<= 1 )
		{
			E wn( cos( pi / i ), f * sin( pi / i ) );
			for( int j = 0 ; j < n ; j += ( i << 1 ) )
			{
				E w( 1, 0 );
				for( int k = 0 ; k < i ; k++, w = w * wn )
				{
					E X = x[ j + k ], Y = w * x[ j + k + i ];
					x[ j + k ] = X + Y; x[ j + k + i ] = X - Y;
				}
			}
		}
		if( f < 0 ) for( int i = 0 ; i < n ; i++ ) x[ i ] = x[ i ] / n;
	}

	inline void mul(int *A, int *B, int *ret)
	{
		for( int i = 0 ; i < n ; i++ ) a[ i ].x = A[ i ], a[ i ].y = 0;
		for( int i = 0 ; i < n ; i++ ) b[ i ].x = B[ i ], b[ i ].y = 0;
		FFT( a, 1 ); FFT( b, 1 );
		for( int i = 0 ; i < n ; i++ ) a[ i ] = a[ i ] * b[ i ];
		FFT( a, -1 );
		for( int i = 0 ; i < n ; i++ ) ret[ i ] = ( LL ) ( a[ i ].x + 0.1 ) % mod;
	}
}

inline void inc(int &x, int y) { x += y; if( x >= mod ) x -= mod; }
inline void dec(int &x, int y) { x -= y; if( x < 0 ) x += mod; }

inline void solve(int m)
{
	if( m == 1 )
	{
		f[ 0 ] = g[ 1 ] = ret = 1;
		return ;
	}
	solve( m >> 1 );
	for( int i = 0 ; i <= n ; i++ ) cf[ i ] = h[ i ] = f[ i ], cg[ i ] = g[ i ], inc( h[ i ], g[ i ] );
	if( m >> 1 & 1 )
	{
		FFT::mul( h, cg, f );
		FFT::mul( h, cf, g );
		for( int i = 0 ; i <= n ; i++ ) dec( g[ i ], h[ i ] );
	}
	else
	{
		FFT::mul( h, cf, f );
		FFT::mul( h, cg, g );
		for( int i = 0 ; i <= n ; i++ ) dec( f[ i ], h[ i ] );
	}
	for( int i = 0 ; i <= n ; i++ ) inc( f[ i ], cf[ i ] );
	for( int i = 0 ; i <= n ; i++ ) inc( g[ i ], cg[ i ] );
	if( m & 1 )
		for( int i = n ; i ; i-- ) inc( g[ i ], f[ i - 1 ] ), inc( g[ i ], g[ i - 1 ] );
	for( int i = 1 ; i <= n ; i += 2 ) inc( ret, g[ i ] );
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read(), m = read(), mod = read();
	if( m == 1 ) return puts( "0" ), 0;
	for( FFT::n = 1 ; FFT::n <= ( n + 1 << 1 ) ; FFT::n <<= 1 ) FFT::L++;
	FFT::getR();
	solve( m >> 1 );
	return printf( "%d\n", ret ), 0;
}