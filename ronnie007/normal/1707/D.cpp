#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 2007 ;

int n , mod ;
ll dp[ MAXN ][ MAXN ] ;
ll pref[ MAXN ][ MAXN ] ;
vector < int > v[ MAXN ] ;
ll fac[ MAXN ] , inv[ MAXN ] ;
ll ans[ MAXN ] ;

ll fastpow ( ll x , ll pw ) {
    ll ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = ( x * x ) % mod ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % mod ;
            -- pw ;
        }
    }
    return ret ;
}

ll comb ( int up , int down ) {
    if ( up < down || down < 0 ) { return 0 ; }
    ll ret = fac[ up ] ;
    ret = ( ret * inv[ down ] ) % mod ;
    ret = ( ret * inv[ up - down ] ) % mod ;
    return ret ;
}

ll without[ MAXN ] ;
ll hh_front[ MAXN ] , hh_back[ MAXN ] ;

void dfs ( int x , int prv ) {
    for ( auto y : v[ x ] ) {
        if ( y == prv ) { continue ; }
        dfs ( y , x ) ;
    }
    for ( auto y : v[ x ] ) {
        if ( y == prv ) { continue ; }
        without[ y ] = 0 ;
    }
    int sz = v[ x ].size ( ) ;
    ll prod = 1 ;
    for ( int t = 1 ; t < n ; ++ t ) {
        if ( x > 1 ) { 
            for ( auto y : v[ x ] ) {
                if ( y == prv ) { continue ; }
                ll aux = ( without[ y ] * dp[ y ][ t ] ) % mod ;
                dp[ x ][ t ] = ( dp[ x ][ t ] + aux ) % mod ;
            }
        }
        prod = 1 ;
        int tp = 0 ;
        hh_front[ 0 ] = 1 ;
        for ( auto y : v[ x ] ) {
            if ( y == prv ) { continue ; }
            ++ tp ;
            hh_front[ tp ] = ( hh_front[ tp - 1 ] * pref[ y ][ t ] ) % mod ;
            prod = ( prod * pref[ y ][ t ] ) % mod ;
        }
        int en = tp ;
        hh_back[ tp + 1 ] = 1 ;
        for ( int i = sz - 1 ; i >= 0 ; -- i ) {
            int y = v[ x ][ i ] ;
            if ( y == prv ) { continue ; }
            hh_back[ en ] = ( hh_back[ en + 1 ] * pref[ y ][ t ] ) % mod ;
            -- en ;
        }
        if ( x > 1 ) {
            tp = 0 ;
            for ( auto y : v[ x ] ) {
                if ( y == prv ) { continue ; }
                ++ tp ;
                ll aux = ( hh_front[ tp - 1 ] * hh_back[ tp + 1 ] ) % mod ;
                without[ y ] = ( without[ y ] + aux ) % mod ;
            }
        }
        dp[ x ][ t ] = ( dp[ x ][ t ] + prod ) % mod ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        pref[ x ][ i ] = ( pref[ x ][ i - 1 ] + dp[ x ][ i ] ) % mod ;
    }
}


void solve ( ) {
    cin >> n >> mod ;
    for ( int i = 1 , x , y ; i < n ; ++ i ) {
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % mod ;
    }
    inv[ n ] = fastpow ( fac[ n ] , mod - 2 ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % mod ;
    }
    dfs ( 1 , -1 ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        ans[ i ] = dp[ 1 ][ i ] ;
        for ( int j = 1 ; j < i ; ++ j ) {
            ans[ i ] -= ( ans[ j ] * comb ( i , j ) ) % mod ;
            if ( ans[ i ] < 0 ) { ans[ i ] += mod ; }
        }
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}