#include<bits/stdc++.h>
using namespace std ;

#define MAXN 207

int n ;
int a[ MAXN ] , b[ MAXN ] ;

int sm1 = 0 , sm2 = 0 ;
long long ans = 0 ;


bool dp[ 2 ][ MAXN * MAXN ] ;
int OFFSET ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
        if ( b[ i ] < a[ i ] ) {
            swap ( a[ i ] , b[ i ] ) ;
        }
    }
}

void solve ( ) {
    OFFSET = n * MAXN ;
    int prv = 0 , nxt = 1 ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < MAXN * MAXN ; ++ j ) {
            dp[ i ][ j ] = false ;
        }
    }

    dp[ prv ][ OFFSET ] = true ;
    for ( int pos = 1 ; pos <= n ; ++ pos ) {
        int val = b[ pos ] - a[ pos ] ;
        for ( int i = 0 ; i < MAXN * MAXN ; ++ i ) {
            if ( dp[ prv ][ i ] == false ) { continue ; }
            dp[ nxt ][ i + val ] = true ;
            dp[ nxt ][ i - val ] = true ;

            dp[ prv ][ i ] = false ;
        }
        prv ^= 1 , nxt ^= 1 ;
    }
    ans = 0 ;
    int tot = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        tot += a[ i ] + b[ i ] ;
        ans += ( n - 2 ) * a[ i ] * a[ i ] ;
        ans += ( n - 2 ) * b[ i ] * b[ i ] ;
    }
    for ( int diff = 0 ; diff < n * MAXN ; ++ diff ) {
        if ( dp[ prv ][ OFFSET + diff ] == true ) {
            long long hh1 = ( tot + diff ) / 2 ;
            long long hh2 = tot - hh1 ;

            ans += hh1 * hh1 + hh2 * hh2 ;
            break ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    /// freopen ( "in.txt" , "r" , stdin ) ;
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