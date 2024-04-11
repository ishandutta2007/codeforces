#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 107

int n , l ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n >> l ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 0 ; i < l ; ++ i ) {
        int x , y ;
        x = y = 0 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( ( a[ j ] & ( 1 << i ) ) == 0 ) { ++ x ; }
            else { ++ y ; }
        }
        if ( y > x ) { ans += ( 1 << i ) ; }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}