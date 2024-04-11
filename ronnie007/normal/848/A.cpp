#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;

int f[ 37 ] ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    int i ;
    int x = 3000 ;
    int id = 0 ;
    while ( n > 0 ) {
        while ( n < ( x * ( x - 1 ) ) / 2 ) {
            x -- ;
        }
        f[ id ] = x ;
        n -= ( x * ( x - 1 ) / 2 ) ;
        id ++ ;
    }
    if ( f[ 0 ] < 1 ) { f[ 0 ] = 1 ; }
    for ( i = 0 ; i < 26 ; i ++ ) {
        char c = char ( 'a' + i ) ;
        while ( f[ i ] != 0 ) {
            f[ i ] -- ;
            cout << c ;
        }
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}