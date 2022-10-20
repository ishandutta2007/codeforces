#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;
int cnt[ 11 ] ;

bool prime ( int x ) {
    for ( int i = 2 ; i * i <= x ; ++ i ) {
        if ( ( x % i ) == 0 ) { return false ; }
    }
    return true ;
}


void input ( ) {
    for ( int i = 0 ; i < 10 ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        ++ cnt[ ( a[ i ] - '0' ) ] ;
        if ( a[ i ] == '1' ||  a[ i ] == '4' || a[ i ] == '6' || a[ i ] == '8' || a[ i ] == '9' ) {
            cout << "1\n" ;
            cout << a[ i ] << "\n" ;
            return ;
        }
    }
    for ( int i = 1 ; i < 10 ; ++ i ) {
        if ( cnt[ i ] >= 2 ) {
            cout << "2\n" ;
            cout << i << i << "\n" ;
            return ;
        }
    }
    int mn = 17 ;
    int ans = -1 ;
    for ( int mask = 1 ; mask < ( 1 << n ) ; ++ mask ) {
        int val = 0 ;
        int digs = 0 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( ( mask & ( 1 << i ) ) > 0 ) {
                val = ( val * 10 ) + ( a[ i ] - '0' ) ;
                ++ digs ;
            }
        }
        if ( digs < mn && prime ( val ) == false ) {
            mn = digs , ans = val ;
        }
    }
    cout << mn << "\n" ;
    cout << ans << "\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
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