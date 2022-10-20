#include<bits/stdc++.h>
using namespace std ;

int n , k ;

void input ( ) {
    cin >> n >> k ;
}

void solve ( ) {
    int len = ( n - k ) / 2 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( ( i % ( len + 1 ) ) == 0 ) {
            cout << "1" ;
        }
        else { cout << "0" ; }
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}