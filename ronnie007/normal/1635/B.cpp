#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

bool f ( int x ) {
    if ( x <= 1 || x >= n ) { return false ; }
    if ( a[ x ] > a[ x - 1 ] && a[ x ] > a[ x + 1 ] ) {
        return true ;
    }
    return false ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 2 ; i < n ; ++ i ) {
        if ( f ( i - 1 ) == true && f ( i + 1 ) == true ) {
            a[ i ] = max ( a[ i - 1 ] , a[ i + 1 ] ) ;
            ++ ans ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( f ( i - 1 ) == true || f ( i + 1 ) == true ) {
            a[ i ] = max ( a[ i - 1 ] , a[ i + 1 ] ) ;
            ++ ans ;
        }
    }
    cout << ans << "\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << a[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    ///scanf ( "%d" , &t ) ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}