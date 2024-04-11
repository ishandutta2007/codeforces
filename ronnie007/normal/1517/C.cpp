#include<bits/stdc++.h>
using namespace std ;

#define MAXN 507

int n ;
int a[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ][ i ] ;
    }
}

void solve ( ) {
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x = i ;
        int y = 1 ;
        for ( int t = 1 ; t <= n ; ++ t ) {
            if ( a[ t ][ t ] >= i ) {
                a[ x ][ y ] = a[ t ][ t ] ;
                ++ x ; ++ y ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= i ; ++ j ) {
            cout << a[ i ][ j ] << " " ;
        }
        cout << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}