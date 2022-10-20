#include<bits/stdc++.h>
using namespace std ;

long long n , r ;

void input ( ) {
    cin >> n >> r ;
    if ( r > n ) { r = n ; }
}

void solve ( ) {
    if ( n > r ) {
        cout << 1LL * r * ( r + 1 ) / 2 << "\n" ;
    }
    else {
        cout << 1LL * r * ( r - 1 ) / 2 + 1 << "\n" ;
    }
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