#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 102 ;

int n ;
pair < int , int > a[ MAXN ] ;
int x[ 3 * MAXN ] ;

int lft[ MAXN ][ MAXN ][ 3 * MAXN ] ;
int dp[ MAXN ][ 3 * MAXN ] ;

set < int > s ;
void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
        s.insert ( a[ i ].first ) ;
        s.insert ( a[ i ].first - a[ i ].second ) ;
        s.insert ( a[ i ].first + a[ i ].second ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    int k = 0 ;
    for ( auto val : s ) {
        x[ ++ k ] = val ;
    }
    for ( int r = 1 ; r <= n ; ++ r ) {
        for ( int l = 1 ; l <= r ; ++ l ) {
            for ( int j = 1 ; j <= k ; ++ j ) {
                lft[ l ][ r ][ j ] = j ;
                int en = j ;
                for ( int wh = r ; wh >= l ; -- wh ) {
                    while ( en > 1 && x[ en - 1 ] >= a[ wh ].first ) { -- en ; }
                    if ( a[ wh ].first + a[ wh ].second >= x[ j ] ) {
                        if ( wh == l ) { lft[ l ][ r ][ j ] = min ( lft[ l ][ r ][ j ] , en ) ; }
                        else { lft[ l ][ r ][ j ] = min ( lft[ l ][ r ][ j ] , lft[ l ][ wh - 1 ][ en ] ) ; }
                    }
                    while ( en > 1 && x[ en - 1 ] >= a[ wh ].first - a[ wh ].second ) { -- en ; }
                    if ( a[ wh ].first >= x[ j ] ) {
                        if ( wh == l ) { lft[ l ][ r ][ j ] = min ( lft[ l ][ r ][ j ] , en ) ; }
                        else { lft[ l ][ r ][ j ] = min ( lft[ l ][ r ][ j ] , lft[ l ][ wh - 1 ][ en ] ) ; }                        
                    }
                }
            }
        }
    }

    for ( int r = 1 ; r <= n ; ++ r ) {
        for ( int en = 1 ; en <= k ; ++ en ) {
            for ( int l = 1 ; l <= r ; ++ l ) {
                int mx = lft[ l ][ r ][ en ] ;
                dp[ r ][ en ] = max ( dp[ r ][ en ] , x[ en ] - x[ mx ] ) ;
                for ( int prv = 1 ; prv < mx ; ++ prv ) {
                    dp[ r ][ en ] = max ( dp[ r ][ en ] , dp[ l - 1 ][ prv ] + x[ en ] - x[ mx ] ) ;
                }
            }
        }
    }

    int ans = 0 ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        ans = max ( ans , dp[ n ][ i ] ) ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}