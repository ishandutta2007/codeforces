#include<bits/stdc++.h>
using namespace std ;

int n , k ;

void input ( ) {
    cin >> n >> k ;
}


void solve ( ) {
    int lst = k - ( n - k ) ;
    for ( int i = 1 ; i < lst ; ++ i ) {
        cout << i << " " ;
    }
    for ( int i = k ; i >= lst ; -- i ) {
        cout << i << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}