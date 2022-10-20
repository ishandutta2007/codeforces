#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
string a ;

int f[ 17 ] ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == 'L' ) {
            for ( int j = 0 ; j < 10 ; ++ j ) {
                if ( f[ j ] == 0 ) { f[ j ] = 1 ; break ; }
            }
        }
        else if ( a[ i ] == 'R' ) {
            for ( int j = 9 ; j >= 0 ; -- j ) {
                if ( f[ j ] == 0 ) { f[ j ] = 1 ; break ; }
            }
        }
        else {
            int id = ( a[ i ] - '0' ) ;
            f[ id ] = 0 ;
        }
    }
    for ( int i = 0 ; i < 10 ; ++ i ) {
        cout << f[ i ] ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}