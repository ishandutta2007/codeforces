#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n ;
int a[ 100007 ] ;

void input ( ) ;
void solve ( ) ;

int main ( )
	{
	input ( ) ;
	solve ( ) ;
	return 0 ;
	}


void input ( )
	{
	scanf ( "%d", &n ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ )
		{
		scanf ( "%d" , &a[ i ] ) ;
		}
	}

void solve ( )
	{
	int br[ 17 ] ;
	int i ;
	for ( i = 1 ; i <=10 ; i ++ ) br[ i ] = 0 ;


	for ( i = 0 ; i < n ; i ++ )br[ a[ i ] ] ++ ;

	int x ,y , z ;
	x =  br[ 1 ] ;
	y =  br[ 2 ] + br[ 3 ] ;
	z = br[ 4 ] +  br[ 6 ] ;

	///printf ( "%d %d %d\n" , x , y , z ) ;

	if ( x != y || y != z || x != z  || br[ 1 ] + br[ 2 ] + br[ 3 ] + br[ 4 ] + br[ 6 ] != n || br[ 6 ] - br[ 3 ] != br[ 2 ] - br[ 4 ] || br[ 4 ] > br[ 2 ] || br[ 3 ] > br[ 6 ] )
		{
		printf ( "-1\n" ) ;
		return  ;
		}
	int t = 0 ;
	for ( i = 0 ; i < br[ 4 ] ; i ++ )
		{
		printf ( "1 2 4\n" ) ;
		}
	for ( i = 0 ; i < br[ 3 ] ; i ++ )
		{
		printf ( "1 3 6\n" ) ;
		}
	for ( i = 0 ; i < br[ 2 ] - br[ 4 ]  ; i ++ )
		{
		printf ( "1 2 6\n" ) ;
		}
	}