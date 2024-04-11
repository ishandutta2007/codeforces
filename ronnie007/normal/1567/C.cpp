#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    long long ans = 0 ;
    int lim = 1 ;
    if ( n >= 2 ) { lim = ( 1 << ( n - 2 ) ) ; }
    for ( int mask = 0 ; mask < lim ; ++ mask ) {
        long long aux = 1 ;
        for ( int i = n - 1 ; i >= 0 ; -- i ) {
            int target = a[ i ] - '0' ;
            if ( i - 2 >= 0 ) {
                if ( ( mask & ( 1 << ( i - 2 ) ) ) > 0 ) {
                    target += 10 ;
                }
            }
            if ( ( mask & ( 1 << i ) ) > 0 ) { -- target ; }

            if ( target < 0 ) {
                aux = 0 ;
                break ;
            }
            int coef = 0 ;
            for ( int x = 0 ; x < 10 ; ++ x ) {
                int y = target - x ;
                if ( y >= 0 && y < 10 ) { ++ coef ; }
            }
            aux = ( aux * coef ) ;
        }
        ans = ans + aux ;
    }
    cout << ans - 2 << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}