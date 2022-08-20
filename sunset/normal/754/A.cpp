#include <bits/stdc++.h>

using namespace std;

int n, a[102], L[102], R[102], cnt2;

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &a[ i ] );
	int cnt = 0, l = 1, r = n;
	for( int i = 1 ; i <= n ; i++ ) if( !a[ i ] ) cnt++;
	if( cnt == n ) return printf( "NO" ), 0;
	puts( "YES" );
	while( !a[ l ] ) l++;
	while( !a[ r ] ) r--;
	if( l == r ) return printf( "1\n1 %d\n", n ), 0;
	L[ 1 ] = 1, R[ 1 ] = l;
	cnt2 = 1;
	for( int i = l + 1; i <= r ; i++ )
		if( a[ i ] )
			L[ ++cnt2 ] = l + 1, l = R[ cnt2 ] = i;
	R[ cnt2 ] = n;
	printf( "%d\n", cnt2 );
	for( int i = 1 ; i <= cnt2 ; i++ ) printf( "%d %d\n", L[ i ], R[ i ] ); 
}