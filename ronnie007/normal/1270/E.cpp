#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 1007

int n ;
pair < int , int > a[ MAXN ] ;

int f[ 2 ][ 2 ] ;

int get ( int x ) {
    if ( x < 0 ) { x = -x ; }
    return ( x & 1 ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
}

void solve ( ) {
    if ( n == 2 ) {
        printf ( "1\n1\n" ) ;
        return ;
    }
    while ( 1 ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            ++ f[ get ( a[ i ].first ) ][ get ( a[ i ].second ) ] ;
        }
        if ( f[ 0 ][ 0 ] + f[ 1 ][ 1 ] < n && f[ 0 ][ 0 ] + f[ 1 ][ 1 ] > 0 ) {
            printf ( "%d\n" , f[ 0 ][ 0 ] + f[ 1 ][ 1 ] ) ;
            for ( int i = 1 ; i <= n ; ++ i ) {
                if ( get ( a[ i ].first + a[ i ].second ) == 0 ) {
                    printf ( "%d " , i ) ;
                }
            }
            printf ( "\n" ) ;
            return ;
        }
        if ( f[ 0 ][ 0 ] > 0 && f[ 1 ][ 1 ] > 0 ) {
            printf ( "%d\n" , f[ 0 ][ 0 ] ) ;
            for ( int i = 1 ; i <= n ; ++ i ) {
                if ( get ( a[ i ].first ) == 0 && get ( a[ i ].second ) == 0 ) {
                    printf ( "%d " , i ) ;
                }
            }
            printf ( "\n" ) ;
            return ;
        }
        if ( f[ 0 ][ 1 ] > 0 && f[ 1 ][ 0 ] > 0 ) {
            printf ( "%d\n" , f[ 0 ][ 1 ] ) ;
            for ( int i = 1 ; i <= n ; ++ i ) {
                if ( get ( a[ i ].first ) == 0 && get ( a[ i ].second ) == 1 ) {
                    printf ( "%d " , i ) ;
                }
            }
            printf ( "\n" ) ;
            return ;
        }
        for ( int i = 1 ; i <= n ; ++ i ) {
            a[ i ].first = ( a[ i ].first - get ( a[ i ].first ) ) / 2 ;
            a[ i ].second = ( a[ i ].second - get ( a[ i ].second ) ) / 2 ;
        }
        for ( int i = 0 ; i < 2 ; ++ i ) {
            for ( int j = 0 ; j < 2 ; ++ j ) {
                f[ i ][ j ] = 0 ;
            }
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}