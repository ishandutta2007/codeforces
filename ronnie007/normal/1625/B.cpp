#include<bits/stdc++.h>
using namespace std ;

#define MAXN 150007

int n ;
int a[ MAXN ] ;

int lst[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < MAXN ; ++ i ) {
        lst[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int ans = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x = a[ i ] ;
        if ( lst[ x ] > 0 ) {
            ans = max ( ans , lst[ x ] + n - i ) ;
        }
        lst[ x ] = i ;
    }
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