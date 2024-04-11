#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int mxbit[ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        for ( int j = 0 ; j < 30 ; ++ j ) {
            if ( ( a[ i ] & ( 1 << j ) ) > 0 ) {
                mxbit[ i ] = j ;
            }
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i + 2 <= n ; ++ i ) {
        if ( mxbit[ i ] == mxbit[ i + 1 ] && mxbit[ i + 1 ] == mxbit[ i + 2 ] ) {
            printf ( "1\n" ) ;
            return ;
        }
    }
    int ans = MAXN ;
    for ( int l = 1 ; l <= n ; ++ l ) {
        int tot = a[ l ] ;
        for ( int r = l + 1 ; r <= n ; ++ r ) {
            tot ^= a[ r ] ;
            if ( l > 1 && tot < a[ l - 1 ] ) { ans = min ( ans , r - l ) ; }
            int sr = 0 ;
            for ( int z = r + 1 ; z <= n ; ++ z ) {
                sr ^= a[ z ] ;
                if ( tot > sr ) { ans = min ( ans , r - l + z - r - 1 ) ; }
            }

        }
    }
    if ( ans == MAXN ) { ans = -1 ; }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    ///scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}