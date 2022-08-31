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

const int MAXN = 200005;

int n, m, cur, pre = 1, nxt;
pa dp[MAXN];
bool ban[MAXN];
vector < int > v[MAXN], ans;

inline int exgcd(int a, int b, int &x, int &y)
{
	if( !b ) { x = 1; y = 0; return a; }
	int d = exgcd( b, a % b, y, x );
	y -= a / b * x;
	return d;
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf( "%d%d", &m, &n );
	for( int i = 1, x ; i <= m ; i++ ) scanf( "%d", &x ), ban[ x ] = 1;
	for( int i = 1 ; i < n ; i++ ) if( !ban[ i ] ) v[ __gcd( n, i ) ].pb( i );
	v[ cur = n ].pb( 0 );
	for( int i = 1 ; i <= n ; i++ )
	{
		dp[ i ] = mp( 0, 0 );
		if( i ^ 1 )
			for( int j = 1 ; j * j <= i ; j++ )	if( i % j == 0 )
			{
				dp[ i ] = max( dp[ i ], mp( dp[ j ].xx, j ) );
			   	if( j ^ 1 ) dp[ i ] = max( dp[ i ], mp( dp[ i / j ].xx, i / j ) );
			}
		dp[ i ].xx += v[ i ].size();
	}
	while( cur )
	{
		for( auto x : v[ cur ] ) ans.pb( x );
		cur = dp[ cur ].yy;
	}
	reverse( ans.begin(), ans.end() );
	if( ban[ 0 ] ) ans.pop_back();
	printf( "%d\n", ans.size() );
	for( auto cur : ans )
	{
		int x, y, d = exgcd( pre, n, x, y );
		x %= n; if( x < 0 ) x += n;
		printf( "%d ", 1LL * ( cur / d ) * x % n ); 
		pre = cur;
	}
	putchar( 10 );
	return 0;
}