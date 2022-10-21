#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;


#define MAXN 1007

int n , m , c ;
int a[ MAXN ] ;

bool ok ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] == 0 ) { return false ; }
        if ( i != 1 && a[ i ] < a[ i - 1 ] ) { return false ; }
    }
    return true ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &c ) ;
}

void solve ( ) {
    int x ;
    int i ;
    while ( 1 ) {
        scanf ( "%d" , &x ) ;
        if ( x <= ( c / 2 ) ) {
            for ( i = 1 ; i <= n ; i ++ ) {
                if ( a[ i ] == 0 || x < a[ i ] ) {
                    printf ( "%d\n" , i ) ;
                    fflush ( stdout ) ;
                    a[ i ] = x ;
                    break ;
                }
            }
        }
        else {
            for ( i = n ; i >= 1 ; i -- ) {
                if ( a[ i ] < x ) {
                    printf ( "%d\n" , i ) ;
                    fflush ( stdout ) ;
                    a[ i ] = x ;
                    break ;
                }
            }
        }
        if ( ok ( ) == true ) { break ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}