#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

int t ;

void input ( ) {
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        long long x , y ;
        scanf ( "%I64d%I64d" , &x , &y ) ;
        int hh = 0 ;
        while ( hh < 1000 ) {
            if ( x >= y ) { break ; }
            if ( ( x & 1 ) == 0 ) { x = ( ( x * 3 ) >> 1 ) ; }
            else { -- x ; }
            ++ hh ;
        }
        if ( x >= y ) { printf ( "YES\n" ) ; }
        else { printf ( "NO\n" ) ; }
    }
}

void solve ( ) {

}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}