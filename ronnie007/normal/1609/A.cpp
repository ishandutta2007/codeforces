#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n ;
long long a[ 22 ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    long long coef = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( ( a[ i ] % 2 ) == 0 ) {
            a[ i ] /= 2 ;
            coef *= 2 ;
        }
    }
    sort ( a + 1 , a + n + 1 ) ;
    a[ n ] *= coef ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += a[ i ] ;
    }
    cout << ans << "\n" ;
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