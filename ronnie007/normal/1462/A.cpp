#include<bits/stdc++.h>
using namespace std ;

#define MAXN 307
int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int l , r ;
    l = 1 ; r = n ;
    int fl = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( fl == 0 ) {
            cout << a[ l ++ ] << " " ;
        }
        else {
            cout << a[ r -- ] << " " ; 
        }
        fl ^= 1 ;
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