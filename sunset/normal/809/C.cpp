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

const int mod = 1e9 + 7;

int f[32][2][2][2], g[32][2][2][2];

inline void inc(int &x, int y) { x += y; if( x >= mod ) x -= mod; }
inline void dec(int &x, int y) { x -= y; if( x < 0 ) x += mod; }

inline int solve(int n, int m, int k)
{
	if( !n || !m ) return 0;
	n--; m--; k--;
	int ret = 0;
	fill( f, 0 ); fill( g, 0 );
	g[ 31 ][ 1 ][ 1 ][ 1 ] = 1;
	for( int i = 31 ; i ; i-- )
		for( int fn = 0 ; fn < 2 ; fn++ )
			for( int fm = 0 ; fm < 2 ; fm++ )
				for( int fk = 0 ; fk < 2 ; fk++ )
					if( f[ i ][ fn ][ fm ][ fk ] || g[ i ][ fn ][ fm ][ fk ] )
					{
						int gn = n >> i - 1 & 1, gm = m >> i - 1 & 1, gk = k >> i - 1 & 1;
						for( int x = 0 ; x <= ( fn ? gn : 1 ) ; x++ )
							for( int y = 0 ; y <= ( fm ? gm : 1 ) ; y++ )
							{
								int d = x ^ y;
								if( fk && d && !gk ) continue;
								int a = fn & ( x == gn ), b = fm & ( y == gm ), c = fk & ( d == gk );
								inc( g[ i - 1 ][ a ][ b ][ c ], g[ i ][ fn ][ fm ][ fk ] );
								inc( f[ i - 1 ][ a ][ b ][ c ], f[ i ][ fn ][ fm ][ fk ] );
								if( d ) inc( f[ i - 1 ][ a ][ b ][ c ], ( 1LL << i - 1 ) * g[ i ][ fn ][ fm ][ fk ] % mod );
							}
					}
	for( int fn = 0 ; fn < 2 ; fn++ )
		for( int fm = 0 ; fm < 2 ; fm++ )
			for( int fk = 0 ; fk < 2 ; fk++ )
				inc( ret, f[ 0 ][ fn ][ fm ][ fk ] ), inc( ret, g[ 0 ][ fn ][ fm ][ fk ] );
	return ret;
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	for( int T = read() ; T ; T-- )
	{
		int x1 = read(), y1 = read(), x2 = read(), y2 = read(), k = read(), ret = 0;
		inc( ret, solve( x2, y2, k ) );
		dec( ret, solve( x1 - 1, y2, k ) );
		dec( ret, solve( x2, y1 - 1, k ) );
		inc( ret, solve( x1 - 1, y1 - 1, k ) );
		printf( "%d\n", ret );
	}
}