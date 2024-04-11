#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

long long x , y ;

void input ( ) {
    cin >> x >> y ;
}

void solve ( ) {
    if ( x == y ) { cout << "0 0\n" ; return ; }
    if ( x < y ) { swap ( x , y ) ; }
    long long diff = x - y ;
    cout << diff << " " << min ( x % diff , diff - x % diff ) << "\n" ;
    
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