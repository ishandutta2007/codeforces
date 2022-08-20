#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int ans = -1, ansd, a[MAXN], b[MAXN], n, m;

inline int Pow(int x, int y, int mod)
{
	int s = 1;
	for( ; y ; y >>= 1, x = 1ll * x * x % mod ) if( y & 1 ) s = 1ll * s * x % mod;
	return s;	
}

inline bool find(int *a, int n, int x) { int t = lower_bound( a + 1, a + n + 1, x ) - a; return a[ t ] == x; }

inline void solve(int *a, int n)
{
	if( n == 1 ) { ans = a[ 1 ], ansd = 1; return ; } 
	int tmp = a[ 2 ] - a[ 1 ], cnt = 0;
	for( int i = 1 ; i <= n ; i++ ) if( find( a, n, ( a[ i ] + tmp ) % m ) ) cnt++;
	ansd = 1ll * tmp * Pow( n - cnt , m - 2, m ) % m;
	int d = ( m - ansd ) % m;
	for( int i = 1 ; i <= n ; i++ ) if( !find( a, n, ( a[ i ] + d ) % m ) )
	{
		if( ans == -1 ) ans = a[ i ];
		else { ans = -1; return ; }
	}
}

int main()
{
	scanf( "%d%d", &m, &n );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &a[ i ] );
	sort( a + 1, a + n + 1 );
	if( n == 1 || n == m ) return printf( "%d 1\n", a[ 1 ], 1 ), 0;
	if( 2 * n < m ) solve( a, n );
	else
	{
		int t = 0;
		for( int i = 0 ; i < m ; i++ ) if( !find( a, n, i ) ) b[ ++t ] = i;
		solve( b, t );
		if( ans != -1 ) ( ans += 1ll * ansd * t % m ) %= m;
	}
	if( ans == -1 ) return printf( "-1\n" ), 0;
	return printf( "%d %d\n", ans, ansd ), 0;
}