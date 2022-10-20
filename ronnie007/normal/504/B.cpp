#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int aux1[ MAXN ] ;
int aux2[ MAXN ] ;

class Tree {
    public :
    int tr[ 3 * MAXN ] ;
    void init ( int where , int IL , int IR , int stval ) {
        if ( IL == IR ) { tr[ where ] = stval ; return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid , stval ) ;
        init ( 2 * where + 1 , mid + 1 , IR , stval ) ;
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        tr[ where ] += val ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , pos , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
    int findk ( int where , int IL , int IR , int pos ) {
        if ( tr[ where ] < pos ) { return -1 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        if ( tr[ 2 * where ] >= pos ) { return findk ( 2 * where , IL , mid , pos ) ; }
        else { return findk ( 2 * where + 1 , mid + 1 , IR , pos - tr[ 2 * where ] ) ; }
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n , 1 ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        aux1[ i ] = w.query ( 1 , 1 , n , 1 , a[ i ] + 1 ) ;
        aux1[ i ] -- ;
        w.update ( 1 , 1 , n , a[ i ] + 1 , -1 ) ;
    }
    w.init ( 1 , 1 , n , 1 ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        aux2[ i ] = w.query ( 1 , 1 , n , 1 , b[ i ] + 1 ) ;
        aux2[ i ] -- ;
        w.update ( 1 , 1 , n , b[ i ] + 1 , -1 ) ;
    }
    w.init ( 1 , 1 , n , 1 ) ;
    for ( i = n ; i >= 1 ; i -- ) {
        aux1[ i ] = ( aux1[ i ] + aux2[ i ] ) ;
        if ( aux1[ i ] >= ( n - i + 1 ) ) {
            aux1[ i - 1 ] += ( aux1[ i ] / ( n - i + 1 ) ) ;
            aux1[ i ] %= ( n - i + 1 ) ;
        }
    }
    w.init ( 1 , 1 , n , 1 ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int h = w.findk ( 1 , 1 , n , aux1[ i ] + 1 ) ;
        printf ( "%d " , h - 1 ) ;
        w.update ( 1 , 1 , n , h , -1 ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}