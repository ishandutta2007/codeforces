#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std ;


#define MAXN 300007
#define LIM 1000007
#define mxtr 7

int n , q ;
int a[ MAXN ] ;

int to[ LIM ] ;

class Tree {
    public :
    long long tr[ 4 * MAXN ] ;
    bool lazy[ 4 * MAXN ] ;
    int mx[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        lazy[ where ] = false ;
        int i ;
        for ( i = IL ; i <= IR ; i ++ ) {
            tr[ where ] += a[ i ] ;
            if ( mx[ where ] < a[ i ] ) {
                mx[ where ] = a[ i ] ;
            }
        }
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == false ) { return ; }
        int i ;
        tr[ where ] = mx[ where ] = 0 ;
        for ( i = IL ; i <= IR ; i ++ ) {
            tr[ where ] += a[ i ] ;
            if ( mx[ where ] < a[ i ] ) {
                mx[ where ] = a[ i ] ;
            }
        }
        if ( IL != IR ) {
            lazy[ 2 * where ] = true ;
            lazy[ 2 * where + 1 ] = true ;
        }
        lazy[ where ] = false ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( mx[ where ] <= 2 ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            int i ;
            for ( i = IL ; i <= IR ; i ++ ) {
                a[ i ] = to[ a[ i ] ] ;
            }
            lazy[ where ] = true ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
        mx[ where ] = max ( mx[ 2 * where ] , mx[ 2 * where + 1 ] ) ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
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
    scanf ( "%d%d" , &n , &q ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j ;
    int mx = 0 ;
    int id = 0 ;
    for ( i = 1 ; i < LIM ; i ++ ) {
        for ( j = i ; j < LIM ; j += i ) {
            to[ j ] ++ ;
        }
    }
    w.init ( 1 , 1 , n ) ;
    while ( q != 0 ) {
        q -- ;
        int type , l , r ;
        scanf ( "%d%d%d" , &type , &l , &r ) ;
        if ( type == 1 ) {
            w.update ( 1 , 1 , n , l , r ) ;
        }
        else {
            printf ( "%I64d\n" , w.query ( 1 , 1 , n , l , r ) ) ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}