#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const int INF = 2e9;

int a[MAXN], l[MAXN], r[MAXN], L, R, c[MAXN], b[MAXN], n;

struct node
{
	int num, id;
	bool operator < ( const node &tmp ) const { return num < tmp.num; }
}p[MAXN];

int main()
{
	scanf( "%d%d%d", &n, &L, &R );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &a[ i ] ), l[ i ] = L - a[ i ], r[ i ] = R - a[ i ];
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &p[ i ].num ), p[ i ].id = i;
	sort( p + 1, p + n + 1 );
	for( int i = 1 ; i <= n ; i++ )
		if( p[ i ].num ^ p[ i + 1 ].num ) if( p[ i ].num ^ i ) return printf( "-1\n" ), 0;
	int mn = -INF, mx = INF, last = 1, now = -INF - 1;
	for( int i = 1 ; i <= n ; i++ )
	{
		int id = p[ i ].id;
		if( mn > r[ id ] || mx < l[ id ] ) return printf( "-1\n" ), 0;
		mx = min( mx, r[ id ] );
		mn = max( mn, l[ id ] );
		if( p[ i ].num ^ p[ i + 1 ].num )
		{
			now = max( now + 1, mn );
			if( now > mx ) return printf( "-1\n" ), 0;
			while( last <= i ) c[ p[ last++ ].id ] = now;
			mx = INF, mn = -INF;
		}
	}
	for( int i = 1 ; i <= n ; i++ ) b[ i ] = a[ i ] + c[ i ];
	for( int i = 1 ; i <= n ; i++ )
	{
		printf( "%d", b[ i ] );
		if( i == n ) putchar( 10 );
		else putchar( ' ' );
	}
}