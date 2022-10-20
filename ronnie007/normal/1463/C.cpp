#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
long long t[ MAXN ] ;
long long pos[ MAXN ] ;

int ans ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> t[ i ] >> pos[ i ] ;
    }
}

void solve ( ) {
    long long aux = 0 ;
    long long fst = 0 ;
    long long id = 0 ;
    ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( fst <= t[ i ] ) {
            aux = pos[ id ] ;
            long long dist = abs ( aux - pos[ i ] ) ;
            if ( i == n || dist <= t[ i + 1 ] - t[ i ] ) {
                ++ ans ;
            }
            id = i ;
            fst = t[ i ] + dist ;
        }
        else {
            long long st = min ( aux , pos[ id ] ) ;
            long long en = max ( aux , pos[ id ] ) ;
            if ( st <= pos[ i ] && pos[ i ] <= en ) {
                long long dist = pos[ i ] - pos[ id ] ;
                if ( dist < 0 ) { dist = -dist ; }
                long long hh = fst - dist ;
                if ( ( i == n && t[ i ] <= hh ) || ( t[ i ] <= hh && hh <= t[ i + 1 ] ) ) {
                    ++ ans ;
                }
            }
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}