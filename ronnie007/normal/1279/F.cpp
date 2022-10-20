#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n , len , k ;
string a ;
int h[ MAXN ] ;
pair < long long , int > dp[ MAXN ] ;


void f ( long long cost ) {
    dp[ 0 ] = { 0 , 0 } ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int lst = i - len ;
        if ( lst < 0 ) { lst = 0 ; }
        dp[ i ].first = dp[ lst ].first + cost ;
        dp[ i ].second = dp[ lst ].second + 1 ;

        if ( dp[ i ].first >= dp[ i - 1 ].first + h[ i ] ) {
            dp[ i ].first = dp[ i - 1 ].first + h[ i ] ;
            dp[ i ].second = dp[ i - 1 ].second ;
        }
    }
}

int calc ( ) {
    long long l , r , mid ;
    l = 0 ;
    r = MAXN ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        f ( mid ) ;
        if ( dp[ n ].second > k ) { l = mid ; }
        else { r = mid ; }
    }
    while ( 1 ) {
        f ( l ) ;
        if ( dp[ n ].second <= k ) { break ; }
        ++ l ;
    }
    return dp[ n ].first - l * k ;
}

void input ( ) {
    cin >> n >> k >> len ;
    cin >> a ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i - 1 ] >= 'a' && a[ i - 1 ] <= 'z' ) { h[ i ] = 1 ; }
    }
    int ans = calc ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i - 1 ] >= 'a' && a[ i - 1 ] <= 'z' ) { h[ i ] = 0 ; }
        else { h[ i ] = 1 ; }
    }
    ans = min ( ans , calc ( ) ) ;
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}