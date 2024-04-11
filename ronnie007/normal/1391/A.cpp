#include<bits/stdc++.h>
using namespace std ;

int n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << i << " " ;
    }
    cout << "\n" ;
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