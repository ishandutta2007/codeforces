#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 200007

int n , k ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int pref[ MAXN ] ;

bool f ( int sr ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] >= sr ) { b[ i ] = 1 ; }
        else { b[ i ] = -1 ; }
    }
    int offset = n ;
    int mn = 4 * MAXN ;
    pref[ 0 ] = n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        offset += b[ i ] ;
        pref[ i ] = offset ;
        if ( i >= k ) { mn = min ( mn , pref[ i - k ] ) ; }

        if ( pref[ i ] > mn ) { return true ; }
    }
    return false ;
}

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int l , r , mid ;
    l = 1 ;
    r = n ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { l = mid ; }
        else { r = mid ; }
    }
    while ( f ( r ) == false ) { -- r ; }
    cout << r << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}