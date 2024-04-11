#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int aux = 0 ;
        for ( int j = i ; j <= n ; ++ j ) {
            ++ aux ;
            if ( a[ j ] == 0 ) { ++ aux ; }
            ans += aux ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    ///scanf ( "%d" , &t ) ;
    /// t = 1 ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}