#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std ;

#define MAXN 1000007

int n ;
int a[ MAXN ] ;
long long br[ 3 * MAXN ] ;

long long u[ 3 * MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
        br[ a[ i ] ] ++ ;
    }
}

void solve ( ) {
	long long i , j ;
    for ( i = 1 ; i <= 3000000 ; i ++ ) {
    	if ( br[ i ] == 0 ) { continue ; }
    	for ( j = i ; j <= 3000000 ; j += i ) {
        	if ( ( j / i ) == i ) { u[ j ] += ( br[ i ] * ( br[ i ] - 1 ) ) ; }
        	else { u[ j ] += ( br[ i ] * br[ j / i ] ) ; }
        }
    }
	for ( i = 1 ; i <= 3000000 ; i ++ ) { u[ i ] += u[ i - 1 ] ; }
    int k ;
    int x ;
    scanf ( "%d" , &k ) ;
    while ( k != 0 ) {
    	k -- ;
    	scanf ( "%d" , &x ) ;
        printf ( "%I64d\n" , 1LL * n * ( n - 1 ) - u[ x - 1 ] ) ;
    }
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}