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

const int MAXN = 100005;

int n, c, d, val[2][MAXN], cost[2][MAXN], ans, bit[MAXN], cnt[2];
char opt[2];

inline int lowbit(int x) { return x & -x; }
inline void modify(int x, int v) { for( ; x <= 1e5 ; x += lowbit( x ) ) bit[ x ] = max( bit[ x ], v ); }
inline int query(int x) { int ret = 0; for( ; x ; x -= lowbit( x ) ) ret = max( ret, bit[ x ] ); return ret; }

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read(), c = read(), d = read();
	for( int i = 1 ; i <= n ; i++ )
	{
		int b = read(), p = read(); scanf( "%s", opt );
		if( opt[ 0 ] == 'C' )
		{
			if( p > c ) continue; 
			val[ 0 ][ ++cnt[ 0 ] ] = b, cost[ 0 ][ cnt[ 0 ] ] = p;
		}
		else
		{
			if( p > d ) continue;
			val[ 1 ][ ++cnt[ 1 ] ] = b, cost[ 1 ][ cnt[ 1 ] ] = p;
		}
	}
	if( cnt[ 0 ] && cnt[ 1 ] )
	{
		int mx0 = 0, mx1 = 0;
		for( int i = 1 ; i <= cnt[ 0 ] ; i++ ) mx0 = max( mx0, val[ 0 ][ i ] );
		for( int i = 1 ; i <= cnt[ 1 ] ; i++ ) mx1 = max( mx1, val[ 1 ][ i ] );
		ans = mx0 + mx1;
	}
	for( int i = 1 ; i <= cnt[ 0 ] ; i++ )
	{
		int t = query( c - cost[ 0 ][ i ] );
		if( t ) ans = max( ans, t + val[ 0 ][ i ] );
		modify( cost[ 0 ][ i ], val[ 0 ][ i ] );
	}
	fill( bit, 0 );
	for( int i = 1 ; i <= cnt[ 1 ] ; i++ )
	{
		int t = query( d - cost[ 1 ][ i ] );
		if( t ) ans = max( ans, t + val[ 1 ][ i ] );
		modify( cost[ 1 ][ i ], val[ 1 ][ i ] );
	}
	cout << ans << endl;
}