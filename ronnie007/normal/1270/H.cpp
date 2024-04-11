#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007
#define MAXVAL 1000002

int n , q ;
int a[ MAXN ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    pair < int , int > valid[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        valid[ where ] = { 10 * MAXN , 0 } ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void unite ( int where , int ls , int rs ) {
        tr[ where ] = min ( tr[ ls ] , tr[ rs ] ) ;
        valid[ where ].first = min ( valid[ ls ].first , valid[ rs ].first ) ;
        valid[ where ].second = ( valid[ where ].first == valid[ ls ].first ) * valid[ ls ].second
                            + ( valid[ where ].first == valid[ rs ].first ) * valid[ rs ].second ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ] += lazy[ where ] ;
        valid[ where ].first += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }

    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        unite ( where , 2 * where , 2 * where + 1 ) ;
    }
    void act ( int where , int IL , int IR , int pos , int nw ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            if ( nw == 1 ) {
                valid[ where ] = { tr[ where ] , 1 } ;
            }
            else {
                valid[ where ] = { 10 * MAXN , 0 } ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        act ( 2 * where , IL , mid , pos , nw ) ;
        act ( 2 * where + 1 , mid + 1 , IR , pos , nw ) ;
        unite ( where , 2 * where , 2 * where + 1 ) ;
    }
};
Tree w ;

void handle ( int pos , int coef ) {
    w.update ( 1 , 1 , MAXVAL , min ( a[ pos - 1 ] , a[ pos ] ) + 1 , max ( a[ pos - 1 ] , a[ pos ] ) , coef ) ;
    w.update ( 1 , 1 , MAXVAL , min ( a[ pos ] , a[ pos + 1 ] ) + 1 , max ( a[ pos ] , a[ pos + 1 ] ) , coef ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    a[ 0 ] = MAXVAL ;
    a[ n + 1 ] = 0 ;
    w.init ( 1 , 1 , MAXVAL ) ;
    for ( int i = 1 ; i <= n + 1 ; ++ i ) {
        w.update ( 1 , 1 , MAXVAL , min ( a[ i - 1 ] , a[ i ] ) + 1 , max ( a[ i - 1 ] , a[ i ] ) , 1 ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        w.act ( 1 , 1 , MAXVAL , a[ i ] , 1 ) ;
    }
}

void solve ( ) {
    while ( q -- ) {
        int pos , x ;
        scanf ( "%d%d" , &pos , &x ) ;
        w.act ( 1 , 1 , MAXVAL , a[ pos ] , 0 ) ;
        handle ( pos , -1 ) ;
        a[ pos ] = x ;
        handle ( pos , 1 ) ;
        w.act ( 1 , 1 , MAXVAL , a[ pos ] , 1 ) ;
        printf ( "%d\n" , w.valid[ 1 ].second ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}