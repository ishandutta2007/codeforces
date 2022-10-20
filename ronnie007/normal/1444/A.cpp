#include<bits/stdc++.h>
using namespace std ;

long long p , q ;

void input ( ) {
    cin >> p >> q ;
}

long long proc ( long long i ) {
    long long sr = p ;
    int cnt = 0 ;
    while ( ( q % i ) == 0 ) {
        q /= i ;
        ++ cnt ;
    }
    while ( ( sr % i ) == 0 ) { sr /= i ; }
    for ( int j = 0 ; j < cnt - 1 ; ++ j ) { sr *= i ; }
    return sr ;
}

void solve ( ) {
    if ( ( p % q ) != 0 ) {
        cout << p << "\n" ;
        return ;
    }
    long long i = 2 ;
    long long ans = 1 ;
    while ( ( i * i ) <= q ) {
        if ( ( q % i ) == 0 ) {
            ans = max ( ans , proc ( i ) ) ;
        }
        ++ i ;
    }
    if ( q > 1 ) { ans = max ( ans , proc ( q ) ) ; }
    cout << ans << "\n" ;
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