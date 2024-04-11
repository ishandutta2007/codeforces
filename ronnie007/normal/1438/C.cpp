#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107
int n , m ;
int a[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cin >> a[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            if ( ( a[ i ][ j ] % 2 ) != ( ( i + j ) % 2 ) ) {
                ++ a[ i ][ j ] ;
            }
            cout << a[ i ][ j ] << " " ;
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