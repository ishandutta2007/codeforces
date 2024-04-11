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
const int mod = 1e9 + 7;

int a[MAXN], table[MAXN], n, ans;

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read();
	table[ 0 ] = 1;
	for( int i = 1 ; i <= n ; i++ )
	{
		a[ i ] = read();
		table[ i ] = table[ i - 1 ] << 1;
		if( table[ i ] >= mod ) table[ i ] -= mod;
	}
	sort( a + 1, a + n + 1 );
	for( int i = 1 ; i < n ; i++ )
		ans = ( 1LL * ( table[ i ] - 1 ) * ( table[ n - i ] - 1 ) % mod * ( a[ i + 1 ] - a[ i ] ) + ans ) % mod;
	return printf( "%d\n", ans ), 0;
}