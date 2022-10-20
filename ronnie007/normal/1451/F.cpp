#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n , m ;
int a[ MAXN ][ MAXN ] ;

int aux[ 2 * MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i <= n + m ; ++ i ) {
        aux[ i ] = 0 ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            cin >> a[ i ][ j ] ;
            aux[ i + j ] ^= a[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    for ( int i = 0 ; i < n + m ; ++ i ) {
        if ( aux[ i ] != 0 ) {
            cout << "Ashish\n" ;
            return ;
        }
    }
    cout << "Jeel\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}