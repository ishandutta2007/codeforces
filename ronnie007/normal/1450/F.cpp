#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

int cnt[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        ++ cnt[ a[ i ] ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( cnt[ i ] > ( n + 1 ) / 2 ) {
            printf ( "-1\n" ) ;
            return ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    int ans = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] == a[ i - 1 ] ) {
            ++ ans ;
            cnt[ a[ i ] ] += 2 ;
        }
    }
    ++ cnt[ a[ 1 ] ] ; ++ cnt[ a[ n ] ] ;
    int mx = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        mx = max ( mx , cnt[ i ] ) ;
    }
    if ( mx > ans + 2 ) { ans += ( mx - ans - 2 ) ; }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}