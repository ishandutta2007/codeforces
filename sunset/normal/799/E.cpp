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

const int MAXN = 200005;
const LL INF = 1e18;

int n, m, K, c[MAXN], a[4][MAXN], cnt[4];
bool A[MAXN], B[MAXN];
LL ans = INF, sum[4][MAXN];

inline int chk(int x, int p, int m)
{
	int A = upper_bound( a[ 1 ] + 1, a[ 1 ] + cnt[ 1 ] + 1, x ) - a[ 1 ] - 1,
		B = upper_bound( a[ 2 ] + 1, a[ 2 ] + cnt[ 2 ] + 1, x ) - a[ 2 ] - 1,
		C = upper_bound( a[ 3 ] + 1, a[ 3 ] + cnt[ 3 ] + 1, x ) - a[ 3 ] - 1;
	A = max( A, p ); B = max( B, p );
	//cout << x << " " << A << " " << B << " " << C << " " << m << endl;
	return A + B + C <= m;
}

inline LL cal(int x, int p, int m)
{
	int A = upper_bound( a[ 1 ] + 1, a[ 1 ] + cnt[ 1 ] + 1, x ) - a[ 1 ] - 1,
		B = upper_bound( a[ 2 ] + 1, a[ 2 ] + cnt[ 2 ] + 1, x ) - a[ 2 ] - 1,
		C = upper_bound( a[ 3 ] + 1, a[ 3 ] + cnt[ 3 ] + 1, x ) - a[ 3 ] - 1;
	A = max( A, p ); B = max( B, p );
	LL ret = sum[ 1 ][ A ] + sum[ 2 ][ B ] + sum[ 3 ][ C ];
	ret -= 1LL * ( A + B + C - m ) * x;
	return ret;
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read(); m = read(), K = read();
	for( int i = 1 ; i <= n ; i++ ) c[ i ] = read();
	for( int c = read() ; c ; c-- ) A[ read() ] = 1;
	for( int c = read() ; c ; c-- ) B[ read() ] = 1;
	for( int i = 1 ; i <= n ; i++ )
	{
		if( A[ i ] && B[ i ] ) a[ 0 ][ ++cnt[ 0 ] ] = c[ i ];
		else if( A[ i ] ) a[ 1 ][ ++cnt[ 1 ] ] = c[ i ];
		else if( B[ i ] ) a[ 2 ][ ++cnt[ 2 ] ] = c[ i ];
		else a[ 3 ][ ++cnt[ 3 ] ] = c[ i ];
	}
	for( int i = 0 ; i < 4 ; i++ ) sort( a[ i ] + 1, a[ i ] + cnt[ i ] + 1 );
	for( int i = 0 ; i < 4 ; i++ )
		for( int j = 1 ; j <= cnt[ i ] ; j++ )
			sum[ i ][ j ] = sum[ i ][ j - 1 ] + a[ i ][ j ];
	for( int i = 0 ; i <= m && i <= cnt[ 0 ] ; i++ )
	{
		LL ret = sum[ 0 ][ i ];
		if( i + cnt[ 1 ] < K || i + cnt[ 2 ] < K || m - i < ( K - i ) * 2 || cnt[ 1 ] + cnt[ 2 ] + cnt[ 3 ] + i < m ) continue;
		int p = max( 0, K - i ), L = 0, R = 1e9, cur = 1e9;
		while( L <= R )
		{
			int mid = L + R >> 1;
			if( chk( mid, p, m - i ) ) L = mid + 1;
			else cur = mid, R = mid - 1;
		}
		ret += cal( cur, p, m - i );
		//cout << i << " " << cur << " " << ret << endl;
		ans = min( ans, ret );
	}
	if( ans == INF ) ans = -1;
	cout << ans << endl;
}