#include<bits/stdc++.h>
using namespace std ;

int n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    cout << ( n + 1 ) / 2 << "\n" ;
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