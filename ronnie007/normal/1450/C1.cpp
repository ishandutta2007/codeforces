#include<bits/stdc++.h>
using namespace std ;

#define MAXN 307

int n ;
string a[ MAXN ] ;

int cnt[ 3 ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < 3 ; ++ i ) { cnt[ i ] = 0 ; }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            if ( a[ i ][ j ] == 'X' ) {
                ++ cnt[ ( i + j ) % 3 ] ;
            }
        }
    }
    int sr = 0 ;
    if ( cnt[ 1 ] <= cnt[ 2 ] && cnt[ 1 ] <= cnt[ 0 ] ) { sr = 1 ; }
    if ( cnt[ 2 ] <= cnt[ 1 ] && cnt[ 2 ] <= cnt[ 0 ] ) { sr = 2 ; }

    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            if ( ( i + j ) % 3 == sr && a[ i ][ j ] == 'X' ) {
                cout << 'O' ; 
            }
            else { cout << a[ i ][ j ] ; }
        }
        cout << "\n" ;
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