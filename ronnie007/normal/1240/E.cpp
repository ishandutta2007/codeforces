#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 500007 ;

int n , a[ MAXN ] ;
int cnt[ MAXN ] , pref[ MAXN ] ;
int prv[ MAXN ] ;

ll ans = 0 ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        ++ cnt[ a[ i ] ] ;
    }
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        pref[ i ] = ( pref[ i - 1 ] + cnt[ i ] ) ;
        if ( cnt[ i ] == 0 ) { prv[ i ] = prv[ i - 1 ] ; }
        else { prv[ i ] = i ; }
    }
}

void solve ( ) {
    for ( int y = 2 ; y < MAXN ; ++ y ) {
        ll tot = 0 ;
        for ( int i = y ; i < MAXN ; i += y ) {
            int r = min ( MAXN , i + y ) ;
            tot += 1LL * ( i / y ) * ( pref[ r - 1 ] - pref[ i - 1 ] ) ;
        }
        int mx1 , mx2 ;
        mx1 = mx2 = -1 ;
        int st = ( MAXN / y ) * y ;
        for ( int i = st ; i >= 0 ; i -= y ) {
            /// [ i .. r )
            int r = min ( MAXN , i + y ) ;
            int sr = prv[ r - 1 ] ;
            if ( sr >= i ) {
                for ( int tm = 0 ; tm < min ( 2 , cnt[ sr ] ) ; ++ tm ) {
                    if ( mx1 < ( sr % y ) ) {
                        mx2 = mx1 ;
                        mx1 = ( sr % y ) ;
                    }
                    else if ( mx2 < ( sr % y ) ) {
                        mx2 = ( sr % y ) ;
                    }
                }
                if ( sr >= 1 ) {
                    sr = prv[ sr - 1 ] ;
                    if ( sr >= i ) {
                        if ( mx1 < ( sr % y ) ) {
                            mx2 = mx1 ;
                            mx1 = ( sr % y ) ;
                        }
                        else if ( mx2 < ( sr % y ) ) {
                            mx2 = ( sr % y ) ;
                        }
                    }
                }

            }
            if ( mx1 >= 0 ) {
                int hh = ( i + mx1 ) / 2 ;
                if ( min ( (ll)hh , tot - ( i / y ) ) >= 2 ) {
                    ans = max ( ans , 1LL * y * min ( (ll)hh , tot - ( i / y ) ) ) ;
                }
            }

            if ( mx2 >= 0 ) {
                int hh = i + mx2 ;
                if ( min ( (ll)hh , tot - 2 * ( i / y ) ) >= 2 ) {
                    ans = max ( ans , 1LL * y * min ( (ll)hh , tot - 2 * ( i / y ) ) ) ;
                }
            }
            if ( mx1 >= 0 ) {
                int hh = i + mx1 ;
                if ( pref[ MAXN - 1 ] - pref[ hh - 1 ] >= 2 ) {
                    if ( min ( (ll)hh , tot - 2 * ( i / y ) - 1 ) >= 2 ) {
                        ans = max ( ans , 1LL * y * min ( (ll)hh , tot - 2 * ( i / y ) - 1 ) ) ;
                    }
                }
            }
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    /// cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}