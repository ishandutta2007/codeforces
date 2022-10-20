#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n , m ;
int a[ MAXN ] ;
int c[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d" , &c[ i ] ) ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    int pos = n ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( pos > 0 && a[ pos ] >= i ) {
            ans += c[ i ] ;
            -- pos ;
        }
    }
    while ( pos > 0 ) {
        ans += c[ a[ pos ] ] ;
        -- pos ;
    }
    printf ( "%lld\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    // cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}