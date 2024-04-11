#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 100007

int n ;
struct tuhla {
    int type ;
    long long l , r ;
};

tuhla a[ MAXN ] ;
vector < long long > srt ;

map < long long , int > ZX ;
map < int , long long > REVZX ;

int MXVAL ;

class Tree {
    public :
    int tr[ 11 * MAXN ] ;
    int lazy[ 11 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = lazy[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        if ( lazy[ where ] == 1 ) {
            tr[ where ] = ( IR - IL + 1 ) ;
        }
        else if ( lazy[ where ] == 2 ) {
            tr[ where ] = 0 ;
        }
        else {
            tr[ where ] = ( IR - IL + 1 ) - tr[ where ] ;
        }
        if ( IL != IR ) {
            if ( lazy[ where ] == 3 ) {
                int mid = ( IL + IR ) / 2 ;
                if ( lazy[ 2 * where ] != 0 ) {
                    push_lazy ( 2 * where , IL , mid ) ;
                }
                if ( lazy[ 2 * where + 1 ] != 0 ) {
                    push_lazy ( 2 * where + 1 , mid + 1 , IR ) ;
                }
            }
            lazy[ 2 * where ] = lazy[ where ] ;
            lazy[ 2 * where + 1 ] = lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] = val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR ) {
        push_lazy ( where , IL , IR ) ;
        if ( tr[ where ] == ( IR - IL + 1 ) ) { return 0 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = query ( 2 * where , IL , mid ) ;
        if ( ret == 0 ) { return query ( 2 * where + 1 , mid + 1 , IR ) ; }
        return ret ;
    }
};
Tree w ;

void compress ( ) {
    int i ;
    srt.clear ( ) ;
    srt.push_back ( 1 ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        srt.push_back ( a[ i ].l ) ;
        srt.push_back ( a[ i ].l + 1 ) ;
        srt.push_back ( a[ i ].r ) ;
        srt.push_back ( a[ i ].r + 1 ) ;
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    int id = 1 ;
    ZX[ srt[ 0 ] ] = 1 ;
    REVZX[ 1 ] = srt[ 0 ] ;
    int sz = srt.size ( ) ;
    for ( i = 1 ; i < sz ; i ++ ) {
        if ( srt[ i ] == srt[ i - 1 ] ) { continue ; }
        id ++ ;
        ZX[ srt[ i ] ] = id ;
        REVZX[ id ] = srt[ i ] ;
    }
    MXVAL = id ;
    for ( i = 1 ; i <= n ; i ++ ) {
        a[ i ].l = ZX[ a[ i ].l ] ;
        a[ i ].r = ZX[ a[ i ].r ] ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%I64d%I64d" , &a[ i ].type , &a[ i ].l , &a[ i ].r ) ;
    }
    compress ( ) ;
}

void solve ( ) {
    w.init ( 1 , 1 , MXVAL ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        w.update ( 1 , 1 , MXVAL , a[ i ].l , a[ i ].r , a[ i ].type ) ;
        printf ( "%I64d\n" , REVZX[ w.query ( 1 , 1 , MXVAL ) ] ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}