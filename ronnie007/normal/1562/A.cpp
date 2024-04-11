#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int l , r ;

void input ( ) {
    cin >> l >> r ;
}

void solve ( ) {
    int ans = 0 ;
    if ( ( r + 1 ) / 2 >= l ) {
        ans = ( r + 1 ) / 2 - 1 ;
    }
    ans = max ( ans , ( r % l ) ) ;
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