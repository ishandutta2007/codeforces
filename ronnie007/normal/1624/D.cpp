#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 200007

int n , k ;
string a ;
int cnt[ 26 ] ;
int w[ MAXN ] ;


bool f ( int sr ) {
    if ( 1LL * k * sr > n ) { return false ; }
    int mids = 0 ;
    int hh = 0 ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        mids += ( cnt[ i ] % 2 ) ;
        hh += ( cnt[ i ] / 2 ) ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        w[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        if ( mids > 0 ) {
            -- mids ;
            ++ w[ i ] ;
            int lft = ( sr / 2 ) ;
            if ( hh < lft ) { return false ; }
            hh -= lft ;
            w[ i ] += lft * 2 ;
        }
        else { break ; }
    }
    for ( int i = k ; i >= 1 ; -- i ) {
        if ( w[ i ] != 0 ) { break ; }
        int lft = ( sr / 2 ) ;
        if ( hh < lft ) { return false ; }
        hh -= lft ;
        w[ i ] += lft * 2 ;
    }
    mids += 2 * hh ;
    hh = 0 ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        if ( w[ i ] < sr ) {
            ++ w[ i ] ;
            if ( mids <= 0 ) { return false ; }
            -- mids ;
        }
    }
    return true ;
}

void input ( ) {
    cin >> n >> k ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    cin >> a ;
    for ( int i = 0 ; i < n ; ++ i ) {
        ++ cnt[ ( a[ i ] - 'a' ) ] ;
    }
}

void solve ( ) {
    int l , r , mid ;
    l = 1 ; r = n ;
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
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}