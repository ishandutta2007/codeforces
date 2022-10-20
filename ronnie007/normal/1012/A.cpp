#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 200007
int n ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= 2 * n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + 2 * n + 1 ) ;
}

void solve ( ) {
    int i , j ;
    long long mn = -1 ;
    for ( i = 1 ; i + n <= 2 * n + 1 ; i ++ ) {
        long long aux1 = a[ i + n - 1 ] - a[ i ] ;
        long long aux2 ;
        if ( i == 1 ) { aux2 = a[ 2 * n ] - a[ n + 1 ] ; }
        else { aux2 = a[ 2 * n ] - a[ 1 ] ; }
        aux1 *= aux2 ;
        if ( mn < 0 ) { mn = aux1 ; }
        if ( aux1 < mn ) { mn = aux1 ; }
    }
    printf ( "%I64d\n" , mn ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}