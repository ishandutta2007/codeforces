#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
pair < int , int > a[ MAXN ] ;

bool f ( int sr ) {
    int hh = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ].first >= hh && a[ i ].second >= sr - hh - 1 ) {
            ++ hh ;
        }
        if ( hh >= sr ) { return true ; }
    }
    return false ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
        swap ( a[ i ].first , a[ i ].second ) ;
    }
}

void solve ( ) {
    int l , r , mid ;
    l = 1 , r = n ;
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
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}