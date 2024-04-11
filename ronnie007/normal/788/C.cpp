#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std ;

#define MAXN 1007
#define OFFSET 1000

int n , k ;
bool a[ 2 * MAXN ] ;
int dp[ 2 * MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &k , &n ) ;
    int i ;
    int x ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &x ) ;
        a[ x ] = true ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 0 ; i <= 2000 ; i ++ ) { dp[ i ] = 3 * MAXN + 27 ; }
    dp[ OFFSET ] = 0 ;
    queue < int > q ;
    int ans = 3 * MAXN + 27 ;
    q.push ( OFFSET ) ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        for ( i = 0 ; i <= 1000 ; i ++ ) {
            if ( a[ i ] == false ) { continue ; }
            int h = ( x + i - k ) ;
            if ( h < 0 ) { continue ; }
            if ( h > 2000 ) { continue ; }
            if ( h == OFFSET ) { printf ( "%d\n" , dp[ x ] + 1 ) ; return ; }
            if ( dp[ x ] + 1 >= dp[ h ] ) { continue ; }
            dp[ h ] = dp[ x ] + 1 ;
            q.push ( h ) ;
        }
    }
    printf ( "-1\n" ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}