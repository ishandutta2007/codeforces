#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
long long k ;
long long a[ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == k ) {
            cout << "YES\n" ;
            return ;
        }
    }
    sort ( a + 1 , a + n + 1 ) ;
    long long aux = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        aux = __gcd ( aux , a[ i ] - a[ i - 1 ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long diff = ( a[ i ] - k ) ;
        if ( diff < 0 ) { diff = -diff ; }
        if ( ( diff % aux ) == 0 ) {
            cout << "YES\n" ;
            return ;
        }
    }
    cout << "NO\n" ;
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