#include<bits/stdc++.h>
using namespace std ;

int n ;

void input ( ) {
    cin >> n ; 
}

void solve ( ) {
    int aux = 0 ;
    for ( int i = 2 ; i * i <= n ; ++ i ) {
        if ( ( n % i ) == 0 ) {
            aux = ( n / i ) ;
            break ;
        }
    }
    if ( aux == 0 ) {
        aux = 1 ;
    }
    cout << aux << " " << n - aux << "\n" ;
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