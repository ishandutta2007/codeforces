#include <bits/stdc++.h>

using namespace std;

int n,l,r;

char s[2020],a[2020];

int main()
{
	scanf( "%d%s", &n, s + 1 );
	if( n & 1 )
	{
		l = r = ( n + 1 >> 1 );
		a[ l ] = s[ 1 ];
		for( int i = 2 ; i <= n ; i++ )
		{
			if( i & 1 ) a[ ++r ] = s[ i ];
			else a[ --l ] = s[ i ];
		}
		for( int i = 1 ; i <= n ; i++ )
			printf( "%c", a[ i ] );
	}
	else
	{
		l = r = ( n + 1 >> 1 );
		a[ l ] = s[ 1 ];
		for( int i = 2 ; i <= n ; i++ )
		{
			if( ( i & 1 ) ^ 1 ) a[ ++r ] = s[ i ];
			else a[ --l ] = s[ i ];
		}
		for( int i = 1 ; i <= n ; i++ )
			printf( "%c", a[ i ] );
	}
}