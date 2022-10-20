#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n ;
pair < int , int > a[ MAXN ] ;

int w[ MAXN ][ MAXN ] ;
int sm[ MAXN ] ;
bool eq[ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ].first ) ;
        a[ i ].second = i ;
    }
}

void solve ( ) {
    sort ( a + 1 , a + n + 1 , greater < pair < int , int > > ( ) ) ;
    for ( int i = 1 ; i < n + 1 ; ++ i ) {
        eq[ i ] = true ;
    }
    for ( int j = 1 ; j <= n ; ++ j ) {
        int k = a[ j ].first , where = a[ j ].second ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( k > 0 && eq[ i ] == true ) {
                w[ i ][ where ] = 1 ;
                -- k ;
                while ( i <= n && eq[ i ] == true ) { ++ i ; }
            }
        }
        for ( int i = 2 ; i <= n + 1 ; ++ i ) {
            if ( k > 0 && w[ i ][ where ] == 0 && eq[ i - 1 ] == false ) {
                w[ i ][ where ] = 1 ;
                -- k ;
            }
        }
        for ( int i = 2 ; i <= n ; ++ i ) {
            if ( k > 0 && w[ i - 1 ][ where ] == 1 && eq[ i - 1 ] == true && eq[ i ] == true ) {
                w[ i ][ where ] = 1 ;
                -- k ;
            }
        }
        for ( int i = 1 ; i <= n + 1 ; ++ i ) {
            if ( k > 0 && w[ i ][ where ] == 0 ) {
                w[ i ][ where ] = 1 ;
                -- k ;
            }
        }
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( eq[ i ] == true && w[ i ][ where ] != w[ i + 1 ][ where ] ) {
                eq[ i ] = false ;
            }
        }
    }
    int sz = 0 ;
    for ( int i = 1 ; i <= n + 1 ; ++ i ) {
        sm[ i ] = 0 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            sm[ i ] += w[ i ][ j ] ; 
        }
        if ( sm[ i ] > 0 ) { ++ sz ; }
    }
    printf ( "%d\n" , sz ) ;
    for ( int i = 1 ; i <= n + 1 ; ++ i ) {
        if ( sm[ i ] == 0 ) { continue ; }
        for ( int j = 1 ; j <= n ; ++ j ) {
            printf ( "%d" , w[ i ][ j ] ) ;
        }
        printf ( "\n" ) ;
    }
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