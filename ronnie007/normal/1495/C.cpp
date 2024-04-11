#include<bits/stdc++.h>
using namespace std ;

#define MAXN 502

int n , m ;
string a[ MAXN ] ;


void connect ( int col ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ][ col ] == 'X' || a[ i ][ col + 1 ] == 'X' ) {
            a[ i ][ col ] = 'X' ;
            a[ i ][ col + 1 ] = 'X' ;
            return ;
        }
    }
    a[ 0 ][ col ] = a[ 0 ][ col + 1 ] = 'X' ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    if ( m <= 2 ) {
        for ( int i = 0 ; i < n ; ++ i ) {
            a[ i ][ 0 ] = 'X' ;
        }
    }
    else { 
        for ( int i = 0 ; i < n ; ++ i ) {
            for ( int j = 0 ; j < m ; ++ j ) {
                if ( ( j % 3 ) == 1 ) {
                    a[ i ][ j ] = 'X' ;
                }
            }
        }

        for ( int j = 2 ; j + 2 < m ; j += 3 ) {
            connect ( j ) ;
        }

        if ( ( m % 3 ) == 1 ) {
            for ( int i = 0 ; i < n ; ++ i ) {
                if ( a[ i ][ m - 1 ] == 'X' ) {
                    a[ i ][ m - 2 ] = 'X' ;
                }
            }
        }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        cout << a[ i ] << "\n" ;
    }
}


int main ( ) {
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