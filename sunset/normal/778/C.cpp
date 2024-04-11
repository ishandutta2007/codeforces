#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300030;

int nxt[MAXN][26], n, u, v, ans[MAXN], dep[MAXN], size[MAXN], cnt[MAXN];
char ch[2];

inline void dfs(int x)
{
	cnt[ dep[ x ] ]++;
	size[ x ] = 1;
	for( int i = 0 ; i < 26 ; i++ ) if( nxt[ x ][ i ] )
		dep[ nxt[ x ][ i ] ] = dep[ x ] + 1, dfs( nxt[ x ][ i ] ), size[ x ] += size[ nxt[ x ][ i ] ];
}

inline int count(int *s, int cnts)
{
	if( !cnts ) return 0;
	if( cnts == 1 ) return size[ s[ 0 ] ];
	int t[26], cntt, ret = 1;
	for( int i = 0 ; i < 26 ; i++ )
	{
		cntt = 0;
		for( int j = 0 ; j < cnts ; j++ ) if( nxt[ s[ j ] ][ i ] )
			t[ cntt++ ] = nxt[ s[ j ] ][ i ];
		ret += count( t, cntt );
	}
	return ret;
}

inline void dfs2(int x)
{
	int s[26], cnts = 0;
	for( int i = 0 ; i < 26 ; i++ ) if( nxt[ x ][ i ] )
		s[ cnts++ ] = nxt[ x ][ i ], dfs2( nxt[ x ][ i ] );
	if( cnts ) ans[ dep[ x ] ] += count( s, cnts );
	else ans[ dep[ x ] ]++;
}

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i < n ; i++ )
		scanf( "%d%d%s", &u, &v, ch ), nxt[ u ][ ch[ 0 ] - 'a' ] = v;
	dfs( 1 );
	for( int i = 1 ; i <= n ; i++ ) cnt[ i ] += cnt[ i - 1 ];
	for( int i = 1 ; i <= n ; i++ ) ans[ i ] = cnt[ i - 1 ];
	dfs2( 1 );
	int ret = 0;
	for( int i = 1 ; i <= n ; i++ ) if( ans[ i ] < ans[ ret ] ) ret = i;
	printf( "%d\n%d\n", ans[ ret ], ret + 1 );
}