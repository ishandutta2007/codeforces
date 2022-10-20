#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 200007

int n ;
char a[ MAXN ] ;
char b[ MAXN ] ;
char p[ MAXN ] ;
char cmp1[ MAXN ] ;
char cmp2[ MAXN ] ;

void f ( int l , int r  ) {
	if ( ( r - l + 1 ) % 2 != 0 ) { return ; }
	int mid = ( r + l ) / 2 ;
	f ( l , mid ) ;
	f ( mid + 1 , r ) ;
	int i ;
	int len = ( r - l + 1 ) / 2 ;
	bool g = true ;
	for ( i = 0 ; i < len ; i ++ ) {
		if ( p[ l + i ] == p[ mid + i + 1 ] ) { continue ; }
		if ( p[ l + i ] > p[ mid + i + 1 ] ) { g = false ; }
		break ;
    }
	if ( g == false ) {
		for ( i = 0 ; i < len ; i ++ ) {
			swap ( p[ l + i ] , p[ mid + i + 1 ] ) ;
        }
    }
}

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	//cin >> a >> b ;
	//n = a.size ( ) ;
	scanf ( "%s%s" , &a , &b ) ;
	n = strlen ( a ) ;
}

void solve ( ) {
	strcpy ( p , a ) ;
	f ( 0 , n - 1 ) ;
	strcpy ( cmp1 , p ) ;
	strcpy ( p , b ) ;
	f ( 0 , n - 1 ) ;
	strcpy ( cmp2 , p ) ;
	if ( strcmp ( cmp1 , cmp2 ) == 0 ) { 
		printf ( "YES\n" ) ;
	}
	else { printf ( "NO\n" ) ; }
}