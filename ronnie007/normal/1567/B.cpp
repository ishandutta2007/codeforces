#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007
int pref[ MAXN ] ;

void init ( ) {
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        pref[ i ] = ( pref[ i - 1 ] ^ i ) ;
    }
}

int a , b ;

void input ( ) {
    cin >> a >> b ;
}

void solve ( ) {
    if ( pref[ a - 1 ] == b ) {
        cout << a << "\n" ;
    }
    else if ( ( pref[ a - 1 ] ^ b ) == a ) {
        cout << a + 2 << "\n" ;
    }
    else { cout << a + 1 << "\n" ; }
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
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