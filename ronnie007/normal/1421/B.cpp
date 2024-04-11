#include<bits/stdc++.h>
using namespace std ;

#define MAXN 207

int n ;
string a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int x = 0 ; x < 2 ; ++ x ) {
        int cost = ( ( a[ 0 ][ 1 ] - '0' ) != x ) + ( ( a[ 1 ][ 0 ] - '0' ) != x ) ;
        cost += ( ( a[ n - 1 ][ n - 2 ] - '0' ) == x ) + ( ( a[ n - 2 ][ n - 1 ] - '0' ) == x ) ;
        if ( cost <= 2 ) {
            cout << cost << "\n" ;
            if ( ( a[ 0 ][ 1 ] - '0' ) != x ) { cout << "1 2\n" ; }
            if ( ( a[ 1 ][ 0 ] - '0' ) != x ) { cout << "2 1\n" ; }
            if ( ( a[ n - 1 ][ n - 2 ] - '0' ) == x ) { cout << n << " " << n - 1 << "\n" ; }
            if ( ( a[ n - 2 ][ n - 1 ] - '0' ) == x ) { cout << n - 1 << " " << n << "\n" ; }
            return ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}