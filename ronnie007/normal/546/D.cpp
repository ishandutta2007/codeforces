#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std ;

#define MAXN 5000007

long long br[ MAXN ] ;
bool k[ MAXN ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	//input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {

}
 
void solve ( )  {
	br[ 2 ] = 1 ;
	int i , j ;
	int u ;
	for ( i = 2 ; i < MAXN ; i ++ ) {
		if ( k[ i ] == true ) { continue ; }
		br[ i ] = 1 ;
		for ( j = 2 * i ; j < MAXN ; j += i ) {
			k[ j ] = true ;
			u = j ;
			while ( u % i == 0 ) { 
				br[ j ] ++ ;
				u /= i ;
			}
        }
    }
	for ( i = 2 ; i < MAXN ; i ++ ) {
		br[ i ] += br[ i - 1 ] ;
    }
	int q ;
	int a , b ;
	scanf ( "%d" , &q ) ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d%d" , &b , &a ) ;
		printf ( "%I64d\n" , br[ b ] - br[ a ] ) ;
    }
}