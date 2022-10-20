#include<bits/stdc++.h>
using namespace std ;

#define MAXN 26

int n ;

long long ans[ MAXN ][ MAXN ] ;
long long pw[ 60 ] ;


void input ( ) {
    cin >> n ;
    pw[ 0 ] = 1 ;
    for ( int i = 1 ; i <= 60 ; ++ i ) {
        pw[ i ] = pw[ i - 1 ] * 2 ;
    }
}

void solve ( ) {
    ans[ 1 ][ 1 ] = 0 ;
    ans[ n ][ n ] = 0 ;
    int id = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x = 1 ;
        int y = i ;
        int type = 1 ;
        while ( 1 ) {
            if ( type == 1 ) {
                ans[ x ][ y ] = pw[ id ] ;
            }
            else {
                ans[ x ][ y ] = 0 ;
            }
            type ^= 1 ;
            ++ x ;
            -- y ;
            if ( x > n || y < 1 ) { break ; }
        }
        ++ id ;
    }
    for ( int j = 2 ; j < n ; ++ j ) {
        int x = j ;
        int y = n ;
        int type = 1 ;
        while ( 1 ) {
            if ( type == 1 ) {
                ans[ x ][ y ] = pw[ id ] ;
            }
            else {
                ans[ x ][ y ] = 0 ;
            }
            type ^= 1 ;
            ++ x ;
            -- y ;
            if ( x > n || y < 1 ) { break ; }
        }
        ++ id ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            cout << ans[ i ][ j ] << " " ;
            fflush ( stdout ) ;
        }
        cout << "\n" ;
        fflush ( stdout ) ;
    }
    int q ;
    cin >> q ;
    long long hh ;
    int x , y ;
    int steps = 2 * n - 2 ;
    while ( q -- ) {
        cin >> hh ;
        x = y = 1 ;
        cout << x << " " << y << "\n" ;
        fflush ( stdout ) ;
        for ( int i = 0 ; i < steps ; ++ i ) {
            if ( ( hh % 2 ) == 0 ) {
                if ( y < n && ans[ x ][ y + 1 ] == 0 ) {
                    ++ y ;
                }
                else if ( x < n && ans[ x + 1 ][ y ] == 0 ) {
                    ++ x ;
                }
            }
            else {
                if ( y < n && ans[ x ][ y + 1 ] > 0 ) {
                    ++ y ;
                }
                else if ( x < n && ans[ x + 1 ][ y ] > 0 ) {
                    ++ x ;
                }
            }
            hh /= 2 ;
            cout << x << " " << y << "\n" ;
            fflush ( stdout ) ;
        }
    }
}


int main ( ) {
    //ios_base :: sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}