#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int a[MAXN], n, m;
long long dp[MAXN][MAXN], ret;

inline void solve()
{
	scanf( "%lld", &ret );
	int l = 0, r = n;
	while( l <= r )
	{
		int mid = l + r >> 1;
		if( dp[ 1 ][ mid ] + ret >= 0 ) r = mid - 1;
		else l = mid + 1;
	}
	printf( "%d\n", l );
}

int main()
{
	scanf( "%d%d", &n, &m );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &a[ i ] );
	for( int i = n ; i ; i-- )
	{
		dp[ i ][ 0 ] = min( dp[ i + 1 ][ 0 ] + a[ i ], 1ll * a[ i ] );
		dp[ i ][ n - i + 1 ] = 0;
		for( int j = 1 ; j < n - i + 1 ; j++ )
			dp[ i ][ j ] = max( dp[ i + 1 ][ j - 1 ], min( dp[ i + 1 ][ j ] + a[ i ], 1ll * a[ i ] ) );
	}
	while( m-- ) solve();
	return 0;
}