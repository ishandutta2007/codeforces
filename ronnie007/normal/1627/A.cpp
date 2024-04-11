#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 57

int n , m , x , y ;
string a[ MAXN ] ;

void input ( ) {
    cin >> n >> m >> x >> y ;
    -- x , -- y ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    if ( a[ x ][ y ] == 'B' ) {
        cout << "0\n" ;
        return ;
    }
    int cnt = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] == 'B' ) {
                ++ cnt ;
                if ( i == x || j == y ) {
                    cout << "1\n" ;
                    return ;
                }
            }
        }
    }
    if ( cnt > 0 ) { cout << "2\n" ; }
    else { cout << "-1\n" ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}