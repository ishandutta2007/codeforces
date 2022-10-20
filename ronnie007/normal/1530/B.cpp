#include<bits/stdc++.h>
using namespace std ;

int n , m ;
bool a[ 22 ][ 22 ] ;


void input ( ) {
    cin >> n >> m ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            a[ i ][ j ] = false ;
        }
    }
    a[ 1 ][ 1 ] = a[ 1 ][ m ] = a[ n ][ 1 ] = a[ n ][ m ] = true ;
    for ( int j = 3 ; j + 1 < m ; j += 2 ) {
        a[ 1 ][ j ] = a[ n ][ j ] = true ;
    }
    for ( int i = 3 ; i + 1 < n ; i += 2 ) {
        a[ i ][ 1 ] = a[ i ][ m ] = true ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            if ( a[ i ][ j ] == true ) { cout << "1" ; }
            else { cout << "0" ; }
        }
        cout << "\n" ;
    }
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}