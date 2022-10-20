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
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( ( i % 2 ) == 0 && a[ i ] >= 0 ) { a[ i ] = - a[ i ] ; }
        if ( ( i % 2 ) == 1 && a[ i ] <= 0 ) { a[ i ] = - a[ i ] ; }
        cout << a[ i ] << " " ;
    }
    cout << "\n" ;
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