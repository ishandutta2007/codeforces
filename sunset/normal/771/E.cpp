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

const int MAXN = 300005;

struct node { int v, p; bool operator < ( const node &b ) { return v < b.v || ( v == b.v && p > b.p ); } }f[MAXN], g[MAXN];

inline void chk(node &x, node y) { if( x < y ) x = y; }

int n, a[MAXN], b[MAXN], c[MAXN], na[MAXN], nb[MAXN], nc[MAXN];

inline void get(int *a, int *na)
{
	map < LL, int > F;
	na[ F[ 0 ] = n ] = n + 1;
	LL sum = 0;
	for( int i = n - 1 ; i >= 0 ; i-- )
	{
		sum += a[ i ];
		na[ i ] = na[ i + 1 ];
		if( F.find( sum ) != F.end() ) na[ i ] = min( na[ i ], F[ sum ] );
		F[ sum ] = i;
	}	
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf( "%d", &n );
	for( int i = 0 ; i < n ; i++ ) scanf( "%d", &a[ i ] );
	for( int i = 0 ; i < n ; i++ ) scanf( "%d", &b[ i ] ), c[ i ] = a[ i ] + b[ i ];
	get( a, na ); get( b, nb ); get( c, nc );
	for( int i = 0 ; i <= n ; i++ )
	{
		chk( f[ na[ g[ i ].p ] ], { g[ i ].v + 1, i } );
		chk( g[ nb[ f[ i ].p ] ], { f[ i ].v + 1, i } );
		chk( f[ na[ i ] ], { f[ i ].v + 1, f[ i ].p } );
		chk( g[ nb[ i ] ], { g[ i ].v + 1, g[ i ].p } );
		chk( f[ i + 1 ], f[ i ] ); chk( g[ i + 1 ], g[ i ] );
		chk( f[ nc[ i ] ], { max( f[ i ].v, g[ i ].v ) + 1, nc[ i ] } );
	}
	return printf( "%d\n", max( f[ n ].v, g[ n ].v ) ), 0;
}