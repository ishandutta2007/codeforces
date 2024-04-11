#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std ;

int n ;
int a[ 100007 ] ;
int d[ 100007 ] ;


int main ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    stack < int > s ;
    s.push ( 0 ) ;
    d[ 0 ] = -1 ;

    for ( i = 1 ; i < n ; i ++ ) {
        d[ i ] = 0 ;
        while ( s.empty ( ) == false ) {
            if ( a[ s.top ( ) ]  > a[ i ] ) break ;
            else d[ i ] = max ( d[ i ] , d[ s.top ( ) ] + 1 ) ;
            s.pop ( ) ;
        }
        if ( s.empty ( ) == true ) d[ i ] = -1 ;
        ///else d[ i ] ++ ;
        s.push ( i ) ;
    }
    int ans = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( d[ i ] + 1 > ans ) ans = d[ i ] + 1 ;
    }
    printf ( "%d\n" , ans ) ;
    return 0 ;
}