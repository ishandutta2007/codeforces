#include<iostream>
#include<stdio.h>
#include<set>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int pos[ MAXN ] ;

int sg[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        pos[ a[ i ] ] = i ;
    }
}

void solve ( ) {
    int i ;
    for ( i = n ; i >= 1 ; i -- ) {
        int x = pos[ i ] ;
        x -= i ;
        set < int > s ;
        while ( x >= 1 ) {
            if ( a[ x ] > i ) {
                s.insert ( sg[ x ] ) ;
            }
            x -= i ;
        }
        x = pos[ i ] ;
        x += i ;
        while ( x <= n ) {
            if ( a[ x ] > i ) {
                s.insert ( sg[ x ] ) ;
            }
            x += i ;
        }
        for ( int j = 0 ; j <= n ; j ++ ) {
            if ( s.find ( j ) == s.end ( ) ) { sg[ pos[ i ] ] = j ; break ; }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( sg[ i ] == 0 ) { printf ( "B" ) ; }
        else { printf ( "A" ) ; }
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}