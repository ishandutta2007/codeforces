#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n ;
int a[ MAXN ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void unite ( int where ) {
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = val ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        unite ( where ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return max ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w[ 2 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    if ( n == 1 ) {
        printf ( "%d\n" , a[ 1 ] ) ;
        return ;
    }
    for ( auto i : { 0 , 1 } ) { w[ i ].init ( 1 , 1 , n ) ; }
    for ( int i = 1 ; i < n ; ++ i ) {
        w[ 0 ].update ( 1 , 1 , n , i , max ( a[ i ] , a[ i + 1 ] ) ) ;
    }
    for ( int i = 2 ; i < n ; ++ i ) {
        w[ 1 ].update ( 1 , 1 , n , i , max ( min ( a[ i - 1 ] , a[ i ] ) , min ( a[ i + 1 ] , a[ i ] ) ) ) ;
    }
    int l[ 2 ] , r[ 2 ] ;
    int turn = ( n % 2 ) ;
    if ( turn == 0 ) {
        l[ 0 ] = r[ 0 ] = ( n / 2 ) ;
        l[ 1 ] = l[ 0 ] ; r[ 1 ] = r[ 0 ] + 1 ;
    }
    else {
        l[ 1 ] = r[ 1 ] = ( ( n + 1 ) / 2 ) ;
        l[ 0 ] = l[ 1 ] - 1 ; r[ 0 ] = r[ 1 ] ;
    }
    for ( int i = 0 ; i < n - 2 ; ++ i ) {
        printf ( "%d " , w[ turn ].query ( 1 , 1 , n , l[ turn ] , r[ turn ] ) ) ;
        -- l[ turn ] ; ++ r[ turn ] ;
        turn ^= 1 ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    printf ( "%d %d\n" , a[ n ] , a[ n ] ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}