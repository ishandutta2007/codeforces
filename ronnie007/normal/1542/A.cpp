#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n ;
int cnt ;

void input ( ) {
    cnt = 0 ;
    cin >> n ;
    for ( int i = 0 ; i < 2 * n ; ++ i ) {
        int x ; cin >> x ;
        if ( ( x % 2 ) == 0 ) { ++ cnt ; }
        else { -- cnt ; }
    }
}

void solve ( ) {
    if ( cnt == 0 ) { cout << "Yes\n" ; }
    else { cout << "No\n" ; }
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