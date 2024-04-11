#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const int MAXM = 300010;

long long ans = 1e16, s[26][MAXN][MAXN], p[MAXN][MAXN];

int cnt[26], sum[26][MAXN][MAXN], a[MAXM], b[MAXM], c[MAXM], d[MAXM], n, m, K;

char mp[MAXN][MAXN], e[MAXM];

inline long long cal(long long f[MAXN][MAXN], int i) { return f[ c[ i ] ][ d[ i ] ] - f[ a[ i ] - 1 ][ d[ i ] ] - f[ c[ i ] ][ b[ i ] - 1 ] + f[ a[ i ] - 1 ][ b[ i ] - 1 ]; }

int main()
{
	scanf( "%d%d%d", &n, &m, &K );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%s", mp[ i ] + 1 );
	for( int i = 1 ; i <= K ; i++ )
	{
		scanf( "%d%d%d%d", &a[ i ], &b[ i ], &c[ i ], &d[ i ] );
		while( e[ i ] < 'a' || e[ i ] > 'z' ) e[ i ] = getchar();
		e[ i ] -= 'a';
		sum[ e[ i ] ][ a[ i ] ][ b[ i ] ]++;
		sum[ e[ i ] ][ a[ i ] ][ d[ i ] + 1 ]--;
		sum[ e[ i ] ][ c[ i ] + 1 ][ b[ i ] ]--;
		sum[ e[ i ] ][ c[ i ] + 1 ][ d[ i ] + 1 ]++;
	}
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ )
		{
			int tot = 0, ret = 0;
			for( int x = 0 ; x < 26 ; x++ )
			{
				cnt[ x ] = sum[ x ][ i ][ j ] += sum[ x ][ i - 1 ][ j ] + sum[ x ][ i ][ j - 1 ] - sum[ x ][ i - 1 ][ j - 1 ];
				ret += cnt[ x ];
				tot += cnt[ x ] * x;
			}
			cnt[ mp[ i ][ j ] - 'a' ] += K - ret;
			tot += ( K - ret ) * ( mp[ i ][ j ] - 'a' );
			for( int x = 0 ; x < 26 ; x++ )
			{
				if( x == mp[ i ][ j ] - 'a' ) p[ i ][ j ] = p[ i ][ j - 1 ] + p[ i - 1 ][ j ] - p[ i - 1 ][ j - 1 ] + tot;
				s[ x ][ i ][ j ] = s[ x ][ i - 1 ][ j ] + s[ x ][ i ][ j - 1 ] - s[ x ][ i - 1 ][ j - 1 ] + tot;
				if( x ) cnt[ x ] += cnt[ x - 1 ];
				tot += cnt[ x ] - ( K - cnt[ x ] );
			}
		}
	for( int i = 1 ; i <= K ; i++ )
		ans = min( ans, p[ n ][ m ] - cal( p, i ) + cal( s[ e[ i ] ], i ) );
	cout << ans << endl;
	return 0;
}