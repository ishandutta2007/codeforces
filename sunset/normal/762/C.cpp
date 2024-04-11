#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

char a[MAXN], b[MAXN];

int n, m, f[MAXN], g[MAXN], ans, ml, mr;

int main()
{
	memset( f, -1, sizeof f );
	memset( g, -1, sizeof g );
	scanf( "%s%s", a + 1, b + 1 );
	n = strlen( a + 1 ), m = strlen( b + 1 );
	int now = 1;
	for( int i = 1 ; i <= m ; i++ )
	{
		while( now <= n && b[ i ] != a[ now ] ) now++;
		if( now > n ) break;
		f[ i ] = now++;
		if( ans < i ) ans = i, ml = i, mr = m + 1;
	}
	now = n;
	for( int i = m ; i ; i-- )
	{
		while( now && b[ i ] != a[ now ] ) now--;
		if( !now ) break;
		g[ i ] = now--;
		if( ans < m - i + 1 ) ans = m - i + 1, ml = 0, mr = i;
	}
	int r = 2;
	for( int l = 1 ; l <= m ; l++ )
	{
		if( f[ l ] == -1 ) break;
		if( l >= r ) r++;
		while( r <= m && f[ l ] >= g[ r ] ) r++;
		if( r > m ) break;
		if( ans < l + m - r + 1 ) ans = l + m - r + 1, ml = l, mr = r;
	}
	if( !ans ) return puts( "-" ), 0;
	for( int i = 1 ; i <= ml ; i++ )
		printf( "%c", b[ i ] );
	for( int i = mr ; i <= m ; i++ ) printf( "%c", b[ i ] );
	return 0;
}