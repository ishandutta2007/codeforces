#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

int val[ 2 ] ;
int mx[ 2 ] ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int ans = 10 ;
    for ( int mask = 0 ; mask < ( 1 << n ) ; ++ mask ) {
        bool fl = true ;
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( a[ i ] == '?' ) { continue ; }
            if ( a[ i ] == '0' && ( mask & ( 1 << i ) ) > 0 ) {
                fl = false ; break ;
            }
            if ( a[ i ] == '1' && ( mask & ( 1 << i ) ) == 0 ) {
                fl = false ; break ;
            }
        }
        if ( fl == false ) { continue ; }
        int id = 0 ;
        val[ 0 ] = val[ 1 ] = 0 ;
        mx[ 0 ] = mx[ 1 ] = 5 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( ( mask & ( 1 << i ) ) == 0 ) {
                -- mx[ id ] ;
            }
            else {
                ++ val[ id ] ;
            }
            if ( val[ 0 ] > mx[ 1 ] || val[ 1 ] > mx[ 0 ] ) {
                ans = min ( ans , i + 1 ) ;
                break ; 
            }
            id ^= 1 ;
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}