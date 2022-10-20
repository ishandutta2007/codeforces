#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

long long x , y ;

void input ( ) {
    cin >> x >> y ;
}

void solve ( ) {
    if ( x > y ) { cout << "NO\n" ; return ; }
    int cnt = 0 ;
    for ( int i = 0 ; i < 30 ; ++ i ) {
        cnt -= ( ( y & ( 1 << i ) ) > 0 ) ;
        cnt += ( ( x & ( 1 << i ) ) > 0 ) ;
        if ( cnt < 0 ) {
            cout << "NO\n" ;
            return ;
        }
    }
    cout << "YES\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}