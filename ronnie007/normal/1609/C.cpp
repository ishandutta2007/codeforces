#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

bool fl[ MAXN ] ;

void init ( ) {
    fl[ 1 ] = true ;
    for ( int i = 2 ; i < MAXN ; ++ i ) {
        if ( fl[ i ] == true ) { continue ; }
        for ( int j = 2 * i ; j < MAXN ; j += i ) {
            fl[ j ] = true ;
        }
    }
}

int n , dist ;
int a[ MAXN ] ;

int l[ MAXN ] ;
int r[ MAXN ] ;


void input ( ) {
    cin >> n >> dist ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}


void solve ( ) {
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] != 1 ) {
            l[ i ] = 0 ;
            continue ;
        }
        if ( i - dist >= 1 ) {
            l[ i ] = l[ i - dist ] + 1 ;
        }
        else {
            l[ i ] = 1 ;
        }
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( a[ i ] != 1 ) {
            r[ i ] = 0 ;
            continue ;
        }
        if ( i + dist <= n ) {
            r[ i ] = r[ i + dist ] + 1 ;
        }
        else {
            r[ i ] = 1 ;
        }
    }

    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( fl[ a[ i ] ] == true ) { continue ; }
        long long hh1 = 0 , hh2 = 0 ;
        if ( i - dist >= 1 ) {
            hh1 = l[ i - dist ] ;
        }
        if ( i + dist <= n ) {
            hh2 = r[ i + dist ] ;
        }
        ans += ( ( hh1 + 1 ) * ( hh2 + 1 ) - 1 ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    init ( ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}