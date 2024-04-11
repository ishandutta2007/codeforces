#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

int decl[ MAXN ] ;
int decr[ MAXN ] ;

int incl[ MAXN ] ;
int incr[ MAXN ] ;

int pref[ MAXN ] ;
int suff[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    incl[ 1 ] = decl[ 1 ] = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i - 1 ] < a[ i ] ) {
            decl[ i ] = decl[ i - 1 ] + 1 ;
            incl[ i ] = 0 ;
        }
        else {
            decl[ i ] = 0 ;
            incl[ i ] = incl[ i - 1 ] + 1 ;
        }
    }

    incr[ n ] = decr[ n ] = 0 ;
    for ( int i = n - 1 ; i >= 1 ; -- i ) {
        if ( a[ i ] > a[ i + 1 ] ) {
            decr[ i ] = decr[ i + 1 ] + 1 ;
            incr[ i ] = 0 ;
        }
        else {
            decr[ i ] = 0 ;
            incr[ i ] = incr[ i + 1 ] + 1 ;
        }
    }
    pref[ 1 ] = max ( incl[ 1 ] , incr[ 1 ] ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        pref[ i ] = max ( incl[ i ] , incr[ i ] ) ;
        pref[ i ] = max ( pref[ i - 1 ] , pref[ i ] ) ;
    }
    suff[ n ] = max ( incl[ n ] , incr[ n ] ) ;
    for ( int i = n - 1 ; i >= 1 ; -- i ) {
        suff[ i ] = max ( incl[ i ] , incr[ i ] ) ;
        suff[ i ] = max ( suff[ i ] , suff[ i + 1 ] ) ;
    }
    int ans = 0 ;
    for ( int i = 2 ; i < n ; ++ i ) {
        if ( decl[ i ] == 0 || decr[ i ] == 0 ) { continue ; }
        if ( decl[ i ] != decr[ i ] ) { continue ; }
        int st = i - decl[ i ] ;
        int en = i + decr[ i ] ;

        int sr = max ( pref[ st - 1 ] , suff[ en + 1 ] ) ;
        sr = max ( sr , incl[ st ] ) ;
        sr = max ( sr , incr[ en ] ) ;

        if ( sr >= decl[ i ] ) { continue ; }
        if ( ( decl[ i ] % 2 ) == 1 ) { continue ; }
        ++ ans ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}