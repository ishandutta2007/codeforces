#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;

bool f[ MAXN ][ 2 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    f[ 0 ][ 0 ] = true ;
    int i , j , t ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( t = 0 ; t < 2 ; t ++ ) {
            if ( f[ i ][ t ] == false ) { continue ; }
            if ( ( a[ i + 1 ] % 2 ) != 1 ) { continue ; }
            for ( j = i + 1 ; j <= n ; j ++ ) {
                if ( ( ( j - i ) % 2 ) == 1 ) {
                    if ( ( a[ j ] % 2 ) == 1 ) {
                        f[ j ][ (t^1) ] = true ;
                    }
                }
            }
        }
    }
    if ( f[ n ][ 1 ] == true ) { printf ( "YES\n" ) ; }
    else { printf ( "NO\n" ) ; }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}