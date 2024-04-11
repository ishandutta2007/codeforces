#include<bits/stdc++.h>
using namespace std ;

#define MAXN 2000007
int n ;
int a[ MAXN ] ;

int fst[ MAXN ][ 2 ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int wh = 0 ; wh < 20 ; ++ wh ) {
        int pref = 0 ;
        for ( int i = 0 ; i < ( 1 << 20 ) ; ++ i ) {
            fst[ i ][ 0 ] = fst[ i ][ 1 ] = -2 ;
        }
        int hh = 0 ;
        fst[ 0 ][ 0 ] = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            pref = pref ^ ( a[ i ] & ( ( 1 << 20 ) - ( 1 << ( wh + 1 ) ) ) ) ;
            if ( ( a[ i ] & ( 1 << wh ) ) == 0 ) {
                hh = i ;
                ///continue ;
            }
            if ( fst[ pref ][ ( i & 1 ) ] >= hh ) {

                ans = max ( ans , i - fst[ pref ][ ( i & 1 ) ] ) ;
            }
            if ( fst[ pref ][ ( i & 1 ) ] < hh ) {
                fst[ pref ][ ( i & 1 ) ] = i ;
            }
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}