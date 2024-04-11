#include<bits/stdc++.h>
using namespace std ;

#define MAXN 5017

int n ;
int a[ MAXN ] ;
long long add[ MAXN ] ;


long long ans ;

void input ( ) {
    cin >> n ;
    ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 0 ; i <= n + 5 ; ++ i ) {
        add[ i ] = 0 ;
    }
}

void solve ( ) {
    long long coef = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        coef += add[ i ] ;
        if ( a[ i ] >= 2 ) {
            int en = min ( i + a[ i ] , n ) ;
            ++ add[ i + 2 ] ;
            -- add[ en + 1 ] ;
        }
        if ( coef >= a[ i ] ) {
            add[ i + 1 ] += ( coef - a[ i ] + 1 ) ;
            add[ i + 2 ] -= ( coef - a[ i ] + 1 ) ;
        }
        a[ i ] -= coef ;
        if ( a[ i ] < 1 ) { a[ i ] = 1 ; }
        ans += ( a[ i ] - 1 ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}