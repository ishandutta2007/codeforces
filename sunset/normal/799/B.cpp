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

int n, m, p[MAXN], a[MAXN], b[MAXN];
set < pa > S[4];

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read();
	for( int i = 1 ; i <= n ; i++ ) p[ i ] = read();
	for( int i = 1 ; i <= n ; i++ ) a[ i ] = read(), S[ a[ i ] ].insert( mp( p[ i ], i ) );
	for( int i = 1 ; i <= n ; i++ ) b[ i ] = read(), S[ b[ i ] ].insert( mp( p[ i ], i ) );
	m = read();
	while( m-- )
	{
		int x = read();
		if( S[ x ].empty() ) puts( "-1" );
		else
		{
			int c = ( *S[ x ].begin() ).yy;
			printf( "%d ", p[ c ] );
			S[ a[ c ] ].erase( mp( p[ c ], c ) );
			S[ b[ c ] ].erase( mp( p[ c ], c ) );
		}
	}	
}