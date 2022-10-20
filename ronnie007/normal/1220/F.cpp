#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

#define MAXN 200007

int n ;
int a[ 2 * MAXN ] ;

int l[ 2 * MAXN ] ;
int r[ 2 * MAXN ] ;

class Tree {
    public :
    int tr[ 8 * MAXN ] ;
    int lazy[ 8 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = lazy[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        tr[ where ] += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += val , push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return max ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void add ( int id , int coef ) {
    w.update ( 1 , 1 , 2 * n , l[ id ] + 1 , r[ id ] - 1 , coef ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        a[ n + i ] = a[ i ] ;
    }
}

void solve ( ) {
    stack < int > s ;
    s.push ( 0 ) ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        while ( a[ s.top ( ) ] >= a[ i ] ) { r[ s.top ( ) ] = i ; s.pop ( ) ; }
        l[ i ] = s.top ( ) ;
        s.push ( i ) ;
    }
    while ( s.empty ( ) == false ) {
        r[ s.top ( ) ] = 2 * n + 1 ;
        s.pop ( ) ;
    }
    w.init ( 1 , 1 , 2 * n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        add ( i , 1 ) ;
    }
    int ans = w.query ( 1 , 1 , 2 * n , 1 , n ) ;
    int id = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        add ( i , -1 ) ;
        add ( n + i , 1 ) ;
        int ret = w.query ( 1 , 1 , 2 * n , i + 1 , n + i ) ;
        if ( ans > ret ) {
            ans = ret , id = i ;
        }
    }
    printf ( "%d %d\n" , ans , id ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}