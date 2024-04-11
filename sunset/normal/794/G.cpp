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

const int MAXN = 600005;
const int mod = 1e9 + 7;

char a[MAXN], b[MAXN];
int n, da, db, p, q, fac[MAXN], inv[MAXN], f[MAXN], c, table[MAXN], lena, lenb, ans;

inline int qpow(int x, int y) { int ret = 1; for( ; y ; y >>= 1, x = 1LL * x * x % mod ) if( y & 1 ) ret = 1LL * ret * x % mod; return ret; }
inline int C(int x, int y) { return 1LL * fac[ x ] * inv[ y ] % mod * inv[ x - y ] % mod; }

inline void init()
{
	table[ 0 ] = fac[ 0 ] = inv[ 0 ] = 1;
	for( int i = 1 ; i <= max( max( lena, lenb ), n + 1 ) ; i++ ) table[ i ] = ( table[ i - 1 ] << 1 ) % mod;
	for( int i = 1 ; i <= lena + lenb ; i++ ) fac[ i ] = 1LL * fac[ i - 1 ] * i % mod;
	inv[ lena + lenb ] = qpow( fac[ lena + lenb ], mod - 2 );
	for( int i = lena + lenb - 1 ; i ; i-- ) inv[ i ] = 1LL * inv[ i + 1 ] * ( i + 1 ) % mod;
	for( int i = n ; i ; i-- )
	{
		f[ i ] = 1LL * ( n / i ) * ( n / i ) % mod;
		for( int j = i + i ; j <= n ; j += i )
			f[ i ] = ( f[ i ] - f[ j ] + mod ) % mod;
	}
	for( int i = 1 ; i <= n ; i++ ) c = ( 1LL * f[ i ] * table[ i ] + c ) % mod;
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf( "%s%s", a + 1, b + 1 ); n = read();
	lena = strlen( a + 1 ); lenb = strlen( b + 1 );
	init();
	for( int i = 1 ; i <= lena ; i++ ) if( a[ i ] == 'A' ) da++; else if( a[ i ] == 'B' ) db++; else p++;
	for( int i = 1 ; i <= lenb ; i++ ) if( b[ i ] == 'A' ) da--; else if( b[ i ] == 'B' ) db--; else q++;
	for( int d = -q ; d <= p ; d++ )
	{
		int t = C( p + q, q + d ), A = da + d, B = db + p - q - d;
		if( A == 0 && B == 0 ) { ans = ( 1LL * t * c + ans ) % mod; continue; }
		if( 1LL * A * B < 0 )
		{
			A = abs( A ), B = abs( B );
			ans = ( 1LL * t * ( table[ n / ( max( A, B ) / __gcd( A, B ) ) + 1 ] - 2 + mod ) + ans ) % mod;
		}
	}
	if( lena == lenb )
	{
		bool same = true; int cnt = 0;
		for( int i = 1 ; i <= lena ; i++ )
			if( a[ i ] != '?' && b[ i ] != '?' && a[ i ] != b[ i ] ) same = false;
			else if( a[ i ] == '?' && b[ i ] == '?' ) cnt++;
		if( same )
		{
			ans = ( ans - 1LL * table[ cnt ] * c % mod + mod ) % mod;
			ans = ( ans + 1LL * table[ cnt ] * ( table[ n + 1 ] - 2 + mod ) % mod * ( table[ n + 1 ] - 2 + mod ) ) % mod;
		}
	}
	return printf( "%d\n", ans ), 0;
}