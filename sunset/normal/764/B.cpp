#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000020;

int n, a[MAXN];

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &a[ i ] );
	for( int i = 1, j = n ; i < j ; i += 2, j -= 2 )
		swap( a[ i ], a[ j ] );
	for( int i = 1 ; i <= n ; i++ ) printf( "%d ", a[ i ] );
	putchar( 10 );
}