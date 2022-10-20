#include<bits/stdc++.h>
using namespace std ;

#define MAXN 3007
int n ;
int a[ MAXN ] ;
int sm = 0 ;

void input ( ) {
    cin >> n ;
    sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        sm += a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( ( sm % i ) != 0 ) { continue ; }
        int val = ( sm / i ) ;
        int hh = 0 ;
        int cnt = 0 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            hh += a[ j ] ;
            if ( hh > val ) { break ; }
            if ( hh == val ) {
                ++ cnt ;
                hh = 0 ;
            }
        }
        if ( cnt == i ) {
            cout << n - i << "\n" ;
            return ;
        }
    }
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