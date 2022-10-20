#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;


int hh[ 100007 ] ;

void input ( ) {

}

void solve ( ) {
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        hh[ 0 ] = x , hh[ 1 ] = y ;
        int period = 2 ;
        for ( int i = 2 ; i <= 100000 ; ++ i ) {
            hh[ i ] = ( hh[ i - 1 ] ^ hh[ i - 2 ] ) ;
            if ( hh[ i - 1 ] == x && hh[ i ] == y ) { period = i - 1 ; break ; }
        }
        z %= period , printf ( "%d\n" , hh[ z ] ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}