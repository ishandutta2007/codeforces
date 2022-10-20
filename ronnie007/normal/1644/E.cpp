#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , len ;
string a ;
pair < int , int > pref[ MAXN ] ;
pair < int , int > rect[ MAXN ] ;


void input ( ) {
    cin >> len ;
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int enx = 1 , eny = 1 ;
    pref[ 0 ] = { enx , eny } ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == 'D' ) { ++ enx ; }
        else { ++ eny ; }
        pref[ i + 1 ] = { enx , eny } ;
    }
    int mxdown = len - enx ;
    int mxright = len - eny ;

    int auxdown , auxright ;
    auxdown = auxright = 0 ;
    long long ans = 0 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        if ( i > 0 ) {
            if ( a[ i - 1 ] == 'D' ) {
                auxdown = max ( auxdown , mxdown ) ;
            }
            if ( a[ i - 1 ] == 'R' ) {
                auxright = max ( auxright , mxright ) ;
            }
        }
        rect[ i ] = { auxdown + 1 , auxright + 1 } ;
        ans += 1LL * min ( rect[ i ].first , len - pref[ i ].first + 1 ) * min ( rect[ i ].second , len - pref[ i ].second + 1 ) ;
        if ( i > 0 ) {
            int unx = min ( rect[ i - 1 ].first - ( a[ i - 1 ] == 'D' ) , rect[ i ].first ) ;
            int uny = min ( rect[ i - 1 ].second - ( a[ i - 1 ] == 'R' ) , rect[ i ].second ) ;
            ans -= 1LL * min ( unx , len - pref[ i ].first + 1 ) * min ( uny , len - pref[ i ].second + 1 ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}