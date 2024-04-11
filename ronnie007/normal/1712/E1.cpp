#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 4e5 + 7 ;

int l , r ;
vector < int > divs[ MAXN ] ;

void init ( ) {
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        for ( int j = 2 * i ; j < MAXN ; j += i ) {
            divs[ j ].push_back ( i ) ;
        }
    }
}

ll lcm ( ll x , ll y ) {
    ll ret = x * y ;
    ll aux = __gcd ( x , y ) ;
    ret /= aux ;
    return ret ;
}

void solve ( ) {
    cin >> l >> r ;
    ll len = ( r - l + 1 ) ;
    ll ans = len * ( len - 1 ) * ( len - 2 ) / 6 ;
    for ( int i = l ; i <= r ; ++ i ) {
        ll hh = 0 ;
        for ( auto x : divs[ i ] ) {
            if ( x >= l ) { ++ hh ; }
        }
        ans -= hh * ( hh - 1 ) / 2 ;
        int sz = divs[ 2 * i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            if ( divs[ 2 * i ][ j ] < l ) { continue ; }
            if ( divs[ 2 * i ][ j ] == i ) { continue ; }
            for ( int t = sz - 1 ; t > j ; -- t ) {
                if ( divs[ 2 * i ][ t ] < l ) { break ; }
                if ( divs[ 2 * i ][ t ] == i ) { continue ; }
                ll hh = lcm ( divs[ 2 * i ][ j ] , divs[ 2 * i ][ t ] ) ;
                hh = lcm ( hh , i ) ;
                if ( hh != 2 * i ) { continue ; }
                if ( divs[ 2 * i ][ j ] + divs[ 2 * i ][ t ] + i <= 2 * i ) { break ; }
                -- ans ;
            }
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}