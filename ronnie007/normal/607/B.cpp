#include<iostream>
#include<stdio.h>
using namespace std ;

#define inf 1000000007
#define MAXN 507

int n ;
int a[ MAXN ] ;
int dp[ MAXN ][ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j , len ;
    for ( i = 1 ; i <= n ; i ++ ) {
        dp[ i ][ i ] = 1 ;
        if ( i == n ) { continue ; }
        if ( a[ i ] == a[ i + 1 ] ) { dp[ i ][ i + 1 ] = 1 ; }
        else { dp[ i ][ i + 1 ] = 2 ; }
    }
    for ( len = 2 ; len < n ; len ++ ) {
        for ( i = 1 ; i + len <= n ; i ++ ) {
            int l = i ;
            int r = i + len ;
            dp[ l ][ r ] = inf ;
            if ( a[ l ] == a[ l + 1 ] ) {
                dp[ l ][ r ] = min ( dp[ l ][ r ] , dp[ l + 2 ][ r ] + 1 ) ;
            }
            for ( j = l + 2 ; j <= r ; j ++ ) {
                if ( a[ l ] != a[ j ] ) { continue ; }
                dp[ l ][ r ] = min ( dp[ l ][ r ] , dp[ l + 1 ][ j - 1 ] + dp[ j + 1 ][ r ] ) ;
            }
            dp[ l ][ r ] = min ( dp[ l ][ r ] , dp[ l + 1 ][ r ] + 1 ) ;
        }
    }
    printf ( "%d\n" , dp[ 1 ][ n ] ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}