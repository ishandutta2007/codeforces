#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
pair < int , int > a[ MAXN ] ;

int x[ MAXN ] ;
int y[ MAXN ] ;

int getr ( int sr ) {
    int l , r , mid ;
    l = 1 ;
    r = n ;
    if ( y[ n ] <= sr ) { return n ; }
    if ( y[ 1 ] > sr ) { return 0 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( y[ mid ] <= sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( y[ r ] > sr ) { -- r ; }
    return r ;
}

int getl ( int sr ) {
    int l , r , mid ;
    l = 1 ;
    r = n ;
    if ( x[ 1 ] >= sr ) { return n ; }
    if ( x[ n ] < sr ) { return 0 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( x[ mid ] >= sr ) { r = mid ; }
        else { l = mid ; }
    }
    while ( x[ l ] < sr ) { ++ l ; }
    return n - l + 1 ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
        x[ i ] = a[ i ].first ;
        y[ i ] = a[ i ].second ;
    }
    sort ( x + 1 , x + n + 1 ) ;
    sort ( y + 1 , y + n + 1 ) ;
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sr = n ;
        sr -= getr ( a[ i ].first - 1 ) ;
        sr -= getl ( a[ i ].second + 1 ) ;
        ans = max ( ans , sr ) ;
    }
    cout << n - ans << "\n" ;
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