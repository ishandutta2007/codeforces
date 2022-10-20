#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int n ; 

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    int ans = 0 ;
    while ( n > 0 ) {
        int x = ( n % 10 ) ;
        n /= 10 ;
        ans = max ( ans , x ) ;
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