#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

int n ;
string a ;

int ans[ 7 ] ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i < 4 ; i ++ ) {
        int br = 0 ;
        char u = 'a' ;
        for ( j = i ; j < n ; j += 4 ) {
            if ( a[ j ] == '!' ) { br ++ ; }
            else { u = a[ j ] ; }
        }
        if ( u == 'R' ) { ans[ 0 ] = br ; }
        if ( u == 'B' ) { ans[ 1 ] = br ; }
        if ( u == 'Y' ) { ans[ 2 ] = br ; }
        if ( u == 'G' ) { ans[ 3 ] = br ; }
    }
    for ( i = 0 ; i < 4 ; i ++ ) {
        cout << ans[ i ] << " " ;
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