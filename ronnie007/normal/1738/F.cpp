#include<bits/stdc++.h>
using namespace std ;
#define fi first
#define se second 
typedef long long ll ;
typedef pair < int , int > pii ;

const int MAXN = 1007 ; 

int n ;
pii a[ MAXN ] ;
bool mrk[ MAXN ] ;

int prv[ MAXN ] , rnk[ MAXN ] , sm[ MAXN ] , cnt[ MAXN ] ;

int get ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = get ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void unite ( int x , int y ) {
    int k1 = get ( x ) , k2 = get ( y ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            sm[ k1 ] += sm[ k2 ] ;
            cnt[ k1 ] += cnt[ k2 ] ;
            prv[ k2 ] = k1 ;
        }
        else {
            sm[ k2 ] += sm[ k1 ] ;
            cnt[ k2 ] += cnt[ k1 ] ;
            prv[ k1 ] = k2 ;
        }
    }
}

int ask ( int x ) {
    cout << "? " << x << "\n" ;
    fflush ( stdout ) ;
    int ret ; cin >> ret ;
    return ret ;
}

int ans[ MAXN ] ;
int deg[ MAXN ] ;

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        mrk[ i ] = false ;
        cin >> a[ i ].fi ;
        deg[ i ] = a[ i ].fi ;
        a[ i ].se = i ;
        prv[ i ] = -1 , rnk[ i ] = 0 ;
        sm[ i ] = deg[ i ] ;
        cnt[ i ] = 1 ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( mrk[ a[ i ].se ] == false ) {
            while ( 1 ) {
                int wh = get ( a[ i ].se ) ;
                if ( sm[ wh ] <= cnt[ wh ] * cnt[ wh ] ) { break ; }
                if ( deg[ a[ i ].se ] == 0 ) { break ; }
                -- deg[ a[ i ].se ] ;
                int aux = ask ( a[ i ].se ) ;
                if ( aux == -1 ) { break ; }
                unite ( aux , a[ i ].se ) ;
                if ( mrk[ aux ] == true ) { break ; }
                mrk[ aux ] = true ;
            }
        }
    }
    int tp = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( prv[ i ] == -1 ) {
            ans[ i ] = ++ tp ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( prv[ i ] != -1 ) {
            ans[ i ] = ans[ get ( i ) ] ;
        }
    }
    cout << "! " ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
    fflush ( stdout ) ;
}

int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}