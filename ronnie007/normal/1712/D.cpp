#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 1e5 + 7 ;

int n , k ;
int a[ MAXN ] , b[ MAXN ] ;

bool f ( int sr ) {
    int tot = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        b[ i ] = a[ i ] ;
        if ( 2 * b[ i ] < sr ) { b[ i ] = 1e9 ; ++ tot ; }
    }
    bool fl = false ;
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( min ( b[ i ] , b[ i + 1 ] ) >= sr ) { fl = true ; }
    }
    if ( fl == false ) {
        bool aux = false ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( b[ i ] >= sr ) { aux = true ; break ; }
        }
        if ( aux == true ) { ++ tot ; }
        else { tot += 2 ; }
    }
    return ( tot <= k ) ;
}

void solve ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    int l , r , mid ;
    l = 1 ; r = 1e9 ;
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
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}