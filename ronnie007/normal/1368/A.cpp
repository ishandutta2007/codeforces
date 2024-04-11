#include<bits/stdc++.h>
using namespace std ;

long long x , y , n ;

void input ( ) {
    cin >> x >> y >> n ;
}

void solve ( ) {
    int ans = 0 ;
    while ( 1 ) {
        if ( x > y ) { swap ( x , y ) ; }
        // x <= y
        if ( y > n ) { break ; }
        long long aux = x + y ;
        x = y ; y = aux ;
        ++ ans ;
    }
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