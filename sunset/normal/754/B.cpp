#include <bits/stdc++.h>

using namespace std;

int a[4][4];

char s[4];

int main()
{
	for( int i = 0 ; i < 4 ; i++ )
	{
		scanf( "%s", s );
		for( int j = 0 ; j < 4; j++ )
		{
			if( s[ j ] == '.' ) a[ i ][ j ] = 1;
			else if( s[ j ] == 'x' ) a[ i ][ j ] = 2;
			else a[ i ][ j ] = 0;
		}
	}
	for( int i = 0 ; i < 4 ; i++ )
		for( int j = 0 ; j < 2 ; j++ )
			if( a[ i ][ j ] + a[ i ][ j + 1 ] + a[ i ][ j + 2 ] == 5 ) return printf( "YES\n" ), 0;
	for( int i = 0 ; i < 2 ; i++ )
		for( int j = 0 ; j < 4 ; j++ )
			if( a[ i ][ j ] + a[ i + 1 ][ j ] + a[ i + 2 ][ j ] == 5 ) return printf( "YES\n" ), 0;
	if( a[ 1 ][ 1 ] + a[ 2 ][ 2 ] + a[ 3 ][ 3 ] == 5 ) return printf( "YES\n" ), 0;
	if( a[ 1 ][ 1 ] + a[ 2 ][ 2 ] + a[ 0 ][ 0 ] == 5 ) return printf( "YES\n" ), 0;
	if( a[ 0 ][ 1 ] + a[ 1 ][ 2 ] + a[ 2 ][ 3 ] == 5 ) return printf( "YES\n" ), 0;
	if( a[ 1 ][ 0 ] + a[ 2 ][ 1 ] + a[ 3 ][ 2 ] == 5 ) return printf( "YES\n" ), 0;
	if( a[ 0 ][ 2 ] + a[ 1 ][ 1 ] + a[ 2 ][ 0 ] == 5 ) return printf( "YES\n" ), 0;
	if( a[ 0 ][ 3 ] + a[ 1 ][ 2 ] + a[ 2 ][ 1 ] == 5 ) return printf( "YES\n" ), 0;
	if( a[ 1 ][ 2 ] + a[ 2 ][ 1 ] + a[ 3 ][ 0 ] == 5 ) return printf( "YES\n" ), 0;
	if( a[ 1 ][ 3 ] + a[ 2 ][ 2 ] + a[ 3 ][ 1 ] == 5 ) return printf( "YES\n" ), 0;
	printf( "NO\n" );
}