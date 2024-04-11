#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int t ;

void input ( ) {
    scanf ( "%d" , &t ) ;
}

void solve ( ) {
    int n , x , y , d ;
    while ( t != 0 ) {
        t -- ;
        scanf ( "%d%d%d%d" , &n , &x , &y , &d ) ;
        if ( ( abs ( x - y ) % d ) == 0 ) { printf ( "%d\n" , ( abs ( x - y ) / d ) ) ; continue ; }
        int aux1 , aux2 ;
        aux1 = aux2 = n + 1 ;
        if ( ( y % d ) == 1 ) { aux1 = ( x - 1 + d - 1 ) / d + ( y - 1 ) / d ; }
        if ( ( y % d ) == ( n % d ) ) { aux2 = ( n - x + d - 1 ) / d + ( n - y ) / d ; }
        if ( min ( aux1 , aux2 ) > n ) { printf ( "-1\n" ) ; continue ; }
        printf ( "%d\n" , min ( aux1 , aux2 ) ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}