#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 200007

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int aux = 0 ;
    for ( int pos = 0 ; pos < 30 ; ++ pos ) {
        int cnt = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( ( a[ i ] & ( 1 << pos ) ) > 0 ) { ++ cnt ; }
        }
        if ( aux == 0 ) { aux = cnt ; }
        else { aux = __gcd ( aux , cnt ) ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( ( aux % i ) == 0 ) {
            cout << i << " " ;
        }
    }
    cout << "\n" ;
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