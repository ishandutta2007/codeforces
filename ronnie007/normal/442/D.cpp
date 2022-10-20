#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n ;
int prv[ MAXN ] ;

int dp[ MAXN ] ;
int mx[ MAXN ][ 2 ] ;

void add ( int x ) {
    dp[ x ] = 1 ;
    while ( prv[ x ] > 0 ) {
        int y = prv[ x ] ;
        if ( mx[ y ][ 0 ] < dp[ x ] ) {
            mx[ y ][ 1 ] = mx[ y ][ 0 ] ;
            mx[ y ][ 0 ] = dp[ x ] ;
        }
        else if ( mx[ y ][ 1 ] < dp[ x ] ) {
            mx[ y ][ 1 ] = dp[ x ] ;
        }
        if ( y == 1 ) {
            dp[ y ] = mx[ y ][ 0 ] ;
            return ;
        }
        if ( dp[ y ] == max ( mx[ y ][ 0 ] , mx[ y ][ 1 ] + 1 ) ) {
            return ;
        }
        dp[ y ] = max ( mx[ y ][ 0 ] , mx[ y ][ 1 ] + 1 ) ;
        x = y ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    ++ n ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        scanf ( "%d" , &prv[ i ] ) ;
    }
}

void solve ( ) {
    dp[ 1 ] = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        add ( i ) ;
        printf ( "%d " , dp[ 1 ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}