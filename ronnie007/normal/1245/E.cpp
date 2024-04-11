#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 17

int n = 10 ;
int a[ MAXN ][ MAXN ] ;
double dp[ MAXN ][ MAXN ] ;

int dir[ MAXN ] ;

void input ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
    dir[ 10 ] = 1 ;
    for ( int i = 9 ; i >= 1 ; -- i ) {
        dir[ i ] = 0 - dir[ i + 1 ] ;
    }
}

void solve ( ) {
    for ( int j = 2 ; j <= n ; ++ j ) {
        double coef = 0 ;
        double sm = 0 ;
        for ( int k = 1 ; k <= 6 ; ++ k ) {
            if ( j - k <= 0 ) { coef += 1.0 ; }
            else {
                sm += ( 1.0 / 6 ) * ( 1 + dp[ 1 ][ j - k ] ) ;
            }
        }
        dp[ 1 ][ j ] = ( coef / 6 + sm ) / ( ( 6 - coef ) / 6 ) ;
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        int st = 1 ;
        if ( dir[ i ] == 1 ) { st = 10 ; }
        for ( int j = st ; j >= 1 && j <= 10 ; j -= dir[ i ] ) {
            for ( int k = 1 ; k <= 6 ; ++ k ) {
                int aux = j + k * dir[ i ] ;
                int rw = i ;

                if ( aux > 10 ) { -- rw ; aux -= 11 ; aux = 10 - aux ; }
                else if ( aux <= 0 ) { -- rw ; aux = 1 - aux ; }

                if ( a[ rw ][ aux ] == 0 ) {
                    dp[ i ][ j ] += ( 1.0 / 6 ) * ( 1 + dp[ rw ][ aux ] ) ;
                }
                else {
                    dp[ i ][ j ] += ( 1.0 / 6 ) * ( 1 + min ( dp[ rw ][ aux ] , dp[ rw - a[ rw ][ aux ] ][ aux ] ) ) ;
                }
            }
        }
    }

    printf ( "%.15lf\n" , dp[ 10 ][ 1 ] ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}