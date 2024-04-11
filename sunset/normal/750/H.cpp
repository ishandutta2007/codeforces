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

const int MAXN = 1005;
const int MAXM = 1000005;
const int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
const int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

int fa[MAXM], id_cnt, id[MAXN][MAXN], S, T, n, m, Q, st[MAXN], top, cnt, blkx[MAXN], blky[MAXN];
char ch[MAXN][MAXN];
bool haveans = 1;
set < pa > s;

inline int find(int x) { return fa[ x ] == x ? x : fa[ x ] = find( fa[ x ] ); }
inline int find2(int x) { return fa[ x ] == x ? x : find2( fa[ x ] ); }
inline void merge(int x, int y) { fa[ find2( x ) ] = fa[ find2( y ) ]; }
inline pa make(int x, int y) { return mp( min( x, y ), max( x, y ) ); }

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf( "%d%d%d", &n, &m, &Q );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%s", ch[ i ] + 1 );
	for( int i = 1 ; i <= n ; i++ ) for( int j = 1 ; j <= m ; j++ ) id[ i ][ j ] = ++id_cnt;
	S = ++id_cnt; T = ++id_cnt;
	for( int i = 1 ; i <= id_cnt ; i++ ) fa[ i ] = i;
	for( int i = 1 ; i <= n ; i++ ) id[ i ][ 0 ] = S, id[ i ][ m + 1 ] = T, ch[ i ][ 0 ] = ch[ i ][ m + 1 ] = '#';
	for( int i = 1 ; i <= m ; i++ ) id[ 0 ][ i ] = T, id[ n + 1 ][ i ] = S, ch[ 0 ][ i ] = ch[ n + 1 ][ i ] = '#';
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ ) if( ch[ i ][ j ] == '#' )
			for( int k = 0 ; k < 8 ; k++ )
			{
				int x = i + dx[ k ], y = j + dy[ k ];
				if( ch[ x ][ y ] == '#' ) fa[ find( id[ i ][ j ] ) ] = find( id[ x ][ y ] );
			}
	for( int i = 1 ; i <= id_cnt ; i++ ) find( i );
	for( int i = 1 ; i <= n ; i++ )
		for( int j = 1 ; j <= m ; j++ )
		{
			if( i == 1 && j == 1 ) continue;
			if( i == n && j == m ) continue;
			for( int k = 0 ; k < 8 ; k++ )
				for( int l = k + 1 ; l < 8 ; l++ )
				{
					s.insert( make( find( id[ i + dx[ k ] ][ j + dy[ k ] ] ), find( id[ i + dx[ l ] ][ j + dy[ l ] ] ) ) );
					if( make( find( id[ i + dx[ k ] ][ j + dy[ k ] ] ), find( id[ i + dx[ l ] ][ j + dy[ l ] ] ) ) == mp( find( S ), find( T ) ) ) haveans = false, i = n + 1, j = m + 1 ;
				}
		}
	if( !haveans ) { while( Q-- ) puts( "NO" ); return 0; }
	while( Q-- )
	{
		scanf( "%d", &cnt );
		for( int i = 1 ; i <= cnt ; i++ )
		{
			scanf( "%d%d", &blkx[ i ], &blky[ i ] ), ch[ blkx[ i ] ][ blky[ i ] ] = '#'; st[ ++top ] = find( id[ blkx[ i ] ][ blky[ i ] ] );
			for( int k = 0 ; k < 8 ; k++ )
				if( ch[ blkx[ i ] + dx[ k ] ][ blky[ i ] + dy[ k ] ] == '#' ) st[ ++top ] = find( id[ blkx[ i ] + dx[ k ] ][ blky[ i ] + dy[ k ] ] );
		}
		st[ ++top ] = find( S ), st[ ++top ] = find( T ); sort( st + 1, st + top + 1 ); top = unique( st + 1, st + top + 1 ) - st - 1;
		for( int i = 1 ; i <= cnt ; i++ )
			for( int k = 0 ; k < 8 ; k++ )
				if( ch[ blkx[ i ] + dx[ k ] ][ blky[ i ] + dy[ k ] ] == '#' ) merge( id[ blkx[ i ] + dx[ k ] ][ blky[ i ] + dy[ k ] ], id[ blkx[ i ] ][ blky[ i ] ] );
		bool ans = true;
		for( int i = 1 ; i <= top && ans ; i++ ) if( find2( st[ i ] ) == find2( S ) )
			for( int j = 1 ; j <= top && ans ; j++ ) if( find2( st[ j ] ) == find2( T ) && s.find( make( st[ i ], st[ j ] ) ) != s.end() )
				ans = false;
		puts( ans ? "YES" : "NO" ); fflush( stdout );
		for( int i = 1 ; i <= cnt ; i++ ) ch[ blkx[ i ] ][ blky[ i ] ] = '.';
		while( top ) fa[ st[ top ] ] = st[ top ], top--;
	}
}