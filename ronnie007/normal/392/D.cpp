#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 100007
#define inf 1000000007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;
int c[ MAXN ] ;

int br[ 3 * MAXN ] ;

int fa[ 3 * MAXN ] ;
int fb[ 3 * MAXN ] ;
int fc[ 3 * MAXN ] ;


vector < int > srt ;

map < int , int > ZX ;

int MXVAL ;

void compress ( ) {
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    int i ;
    int id = 1 ;
    ZX[ srt[ 0 ] ] = 1 ;
    int sz = srt.size ( ) ;
    for ( i = 1 ; i < sz ; i ++ ) {
        if ( srt[ i ] == srt[ i - 1 ] ) { continue ; }
        id ++ ;
        ZX[ srt[ i ] ] = id ;
    }
    MXVAL = id ;
    for ( i = 1 ; i <= n ; i ++ ) {
        a[ i ] = ZX[ a[ i ] ] ;
        b[ i ] = ZX[ b[ i ] ] ;
        c[ i ] = ZX[ c[ i ] ] ;
    }
}


class Tree {
    public :
    int tr[ 3 * MAXN ] ;
    int ans[ 3 * MAXN ] ;
    int lazy[ 3 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = lazy[ where ] = 0 ;
        ans[ where ] = IL ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ] = max ( tr[ where ] , lazy[ where ] ) ;
        ans[ where ] = tr[ where ] + IL ;
        if ( IL != IR ) {
            lazy[ 2 * where ] = max ( lazy[ 2 * where ] , lazy[ where ] ) ;
            lazy[ 2 * where + 1 ] = max ( lazy[ 2 * where + 1 ] , lazy[ where ] ) ;
        }
        lazy[ where ] = 0 ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] = val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
        ans[ where ] = min ( ans[ 2 * where ] , ans[ 2 * where + 1 ] ) ;
    }
    pair < int , int > getmx ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return make_pair ( 0 , inf ) ; }
        if ( CURL <= IL && IR <= CURR ) { return make_pair ( tr[ where ] , ans[ where ] ) ; }
        int mid = ( IL + IR ) / 2 ;
        pair < int , int > ret1 = getmx ( 2 * where , IL , mid , CURL , CURR ) ;
        pair < int , int > ret2 = getmx ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        ret1.first = max ( ret1.first , ret2.first ) ;
        ret1.second = min ( ret1.second , ret2.second ) ;
        return ret1 ;
    }
};

Tree w ;

void add ( int x ) {
    if ( fc[ x ] == 0 ) {
        w.update ( 1 , 0 , n , 0 , fb[ x ] - 1 , inf ) ;
        return ;
    }
    int l , r , mid ;
    l = 0 ;
    r = n ;
    if ( fb[ x ] != 0 ) { r = fb[ x ] - 1 ; }
    while ( r - l > 3 ) {
        int mid = ( l + r ) / 2 ;
        int ret = w.getmx ( 1 , 0 , n , mid , mid ).first ;
        if ( ret >= fc[ x ] ) { l = mid ; }
        else { r = mid ; }
    }
    while ( l <= r ) {
        int ret = w.getmx ( 1 , 0 , n , l , l ).first ;
        if ( ret < fc[ x ] ) { break ; }
        l ++ ;
    }
    int st = l ;
    int en = n ;
    if ( fb[ x ] != 0 ) { en = fb[ x ] - 1 ; }
    if ( st <= en ) {
        w.update ( 1 , 0 , n , st , en , fc[ x ] ) ;
    }
}


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        srt.push_back ( a[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
        srt.push_back ( b[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &c[ i ] ) ;
        srt.push_back ( c[ i ] ) ;
    }
    compress ( ) ;
}

void solve ( ) {
    int i ;
    for ( i = n ; i >= 1 ; i -- ) {
        fa[ a[ i ] ] = i ;
        fb[ b[ i ] ] = i ;
        fc[ c[ i ] ] = i ;
        br[ a[ i ] ] ++ ;
    }
    w.init ( 1 , 0 , n ) ;
    for ( i = 1 ; i <= MXVAL ; i ++ ) {
        if ( br[ i ] == 0 ) {
            add ( i ) ;
        }
    }
    int ans = inf ;
    for ( i = n ; i >= 0 ; i -- ) {
        int ret = w.getmx ( 1 , 0 , n , 0 , n ).second ;
        ret += i ;
        if ( ans > ret ) { ans = ret ; }
        if ( i == 0 ) { break ; }
        br[ a[ i ] ] -- ;
        if ( br[ a[ i ] ] == 0 ) {
            if ( fb[ a[ i ] ] == 0 && fc[ a[ i ] ] == 0 ) { break ; }
            add ( a[ i ] ) ;
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}