#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
pair < int , int > a[ MAXN ] ;
pair < int , int > b[ MAXN ] ;
int ord[ MAXN ] , ans[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first ;
        a[ i ].second = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ].first ;
        b[ i ].second = i ;
    }
}

void solve ( ) {
    sort ( a + 1 , a + n + 1 ) ;
    sort ( b + 1 , b + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ord[ b[ i ].second ] = i ;
        ans[ i ] = 0 ;
    }
    ans[ a[ n ].second ] = 1 ;
    int mn = MAXN ;
    for ( int i = n ; i >= 1 ; -- i ) {
        ans[ a[ i ].second ] = 1 ;
        mn = min ( mn , ord[ a[ i ].second ] ) ;
        if ( mn == i ) { break ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ans[ i ] ;
    }
    cout << "\n" ;
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