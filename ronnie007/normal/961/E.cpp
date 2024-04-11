#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

pair < int , int > b[ MAXN ] ;

class Tree {
    public :
    int tr[ 4 * MAXN ] ;
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
            tr[ where ] += val ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        if ( a[ i ] > n ) { a[ i ] = n ; }
        b[ i ] = make_pair ( a[ i ] , i ) ;
    }
    sort ( b + 1 , b + n + 1 ) ;
}

void solve ( ) {
    int i ;
    int id = 1 ;
    long long ans = 0 ;
    w.init ( 1 , 1 , n ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        w.update ( 1 , 1 , n , i , 1 ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        while ( id <= n && b[ id ].first < i ) {
            w.update ( 1 , 1 , n , b[ id ].second , -1 ) ;
            id ++ ;
        }
        ans += w.query ( 1 , 1 , n , 1 , a[ i ] ) ;
        if ( a[ i ] >= i ) { ans -- ; }
    }
    printf ( "%I64d\n" , ( ans / 2 ) ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}