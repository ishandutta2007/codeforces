#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n ;
string a ;
string b ;

void input ( ) {
    cin >> n >> a ;
    b = a ;
}

void solve ( ) {
    sort ( b.begin ( ) , b.end ( ) ) ;
    int ans = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( b[ i ] != a[ i ] ) { ++ ans ; }
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