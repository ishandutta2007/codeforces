#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 500007

int n ;
int a[ MAXN ] ;

vector < int > v[ MAXN ] ;
int pos[ MAXN ] ;


class Tree {
public :
    pair < int , int > tr[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = { 0 , IR - IL + 1 } ;
        lazy[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ].first += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < IL || CURL > CURR ) { return ; }
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        tr[ where ].first = min ( tr[ 2 * where ].first , tr[ 2 * where + 1 ].first ) ;
        tr[ where ].second = ( tr[ 2 * where ].first == tr[ where ].first ) * tr[ 2 * where ].second
                        + ( tr[ 2 * where + 1 ].first == tr[ where ].first ) * tr[ 2 * where + 1 ].second ;
    }
    pair < int , int > query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < IL ) { return { MAXN , 0 } ; }
        if ( IR < CURL || CURR < IL ) { return { MAXN , 0 } ; }
        if ( CURL <= IL && IR <= CURR ) {
                return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        pair < int , int > ret1 , ret2 ;
        ret1 = query ( 2 * where , IL , mid , CURL , CURR ) ;
        ret2 = query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        if ( ret1.first == ret2.first ) { ret1.second += ret2.second ; }
        else {
            if ( ret1.first > ret2.first ) { ret1 = ret2 ; }
        }
        return ret1 ;
    }
};
Tree w ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        v[ a[ i ] ].push_back ( i ) ;
    }
    for ( int i = 0 ; i < MAXN ; ++ i ) {
        pos[ i ] = v[ i ].size ( ) - 1 ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    long long ans = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( pos[ a[ i ] ] + 3 < v[ a[ i ] ].size ( ) ) {
            int st = v[ a[ i ] ][ pos[ a[ i ] ] + 3 ] ;
            int en = n ;
            if ( pos[ a[ i ] ] + 4 < v[ a[ i ] ].size ( ) ) {
                en = v[ a[ i ] ][ pos[ a[ i ] ] + 4 ] - 1 ;
            }
            int nxt = v[ a[ i ] ][ pos[ a[ i ] ] + 1 ] ;
            w.update ( 1 , 1 , n , nxt , st - 1 , -1 ) ;
            w.update ( 1 , 1 , n , en + 1 ,  n , -1 ) ;
        }
        if ( pos[ a[ i ] ] + 2 < v[ a[ i ] ].size ( ) ) {
            if ( pos[ a[ i ] ] + 2 == v[ a[ i ] ].size ( ) - 1 ) {
                int nxt = v[ a[ i ] ][ pos[ a[ i ] ] + 1 ] ;
                w.update ( 1 , 1 , n , nxt , n , -1 ) ;
            }
            int st = v[ a[ i ] ][ pos[ a[ i ] ] + 2 ] ;
            int en = n ;
            if ( pos[ a[ i ] ] + 3 < v[ a[ i ] ].size ( ) ) {
                en = v[ a[ i ] ][ pos[ a[ i ] ] + 3 ] - 1 ;
            }
            w.update ( 1 , 1 , n , i , st - 1 , 1 ) ;
            w.update ( 1 , 1 , n , en + 1 ,  n , 1 ) ;
        }
        else {
            int nxt = n + 1 ;
            if ( pos[ a[ i ] ] + 1 < v[ a[ i ] ].size ( ) ) {
                nxt = v[ a[ i ] ][ pos[ a[ i ] ] + 1 ] ;
            }
            w.update ( 1 , 1 , n , i , nxt - 1 , 1 ) ;
        }
        pair < int , int > aux = w.query ( 1 , 1 , n , i , n ) ;
        ans += ( aux.first == 0 ) * aux.second ;
        -- pos[ a[ i ] ] ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}