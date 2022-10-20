#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

int x , y ;

int w ( int x , int y ) {
    if ( x < y ) { swap ( x , y ) ; }
    if ( y == 0 ) { return x ; }
    return w ( y , ( x % y ) ) ;
}

void input ( ) {
    scanf ( "%d%d" , &x , &y ) ;
}

void solve ( ) {
    cout << ( ( w ( x , y ) == 1 ) ? "Finite" : "Infinite" ) << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}