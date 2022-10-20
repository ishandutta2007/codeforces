#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 107 

int n , m ;
int a[ MAXN ][ MAXN ] ;

int br[ MAXN ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &m , &n ) ;
	int i , j ;
	int id ;
	int cur ;
	for ( i = 0 ; i < n ; i ++ ) {
		id = 0 ;
		cur = -1 ;
		for ( j = 1 ; j <= m ; j ++ ) {
			scanf ( "%d" , &a[ i ][ j ] ) ;
			if ( cur < a[ i ][ j ] ) { cur = a[ i ][ j ] ; id = j ; } 
        }
		br[ id ] ++ ;
    }
}

void solve ( ) {
	int id = 0 ;
	int cur = -1 ;
	int i ;
	for ( i = 1 ; i <= m ; i ++ ) {	
		if ( cur < br[ i ] ) { cur = br[ i ] ; id = i ; }
    }
	printf ( "%d\n" , id ) ;
}