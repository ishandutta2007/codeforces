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

#define MOD 1000000007
#define MAXN 200007

using ll = long long ;

int n ;
pair < int , int > a[ MAXN ] ;

pair < ll , ll > dp[ MAXN ] ;

vector < int > srt ;

map < int , int > ZX ;

int MAXID ;

struct tuhla {
    tuhla ( ) { val = times = 0 ; fl = false ; }
    ll val ;
    ll times ;
    bool fl ;
};

tuhla merge ( tuhla p1 , tuhla p2 ) {
    if ( p1.fl == false ) { return p2 ; }
    if ( p2.fl == false ) { return p1 ; }
    tuhla ret ;
    ret.fl = true ;
    ret.val = min ( p1.val , p2.val ) ;
    ret.times = 0 ;
    if ( p1.val == ret.val ) {
        ret.times += p1.times ;
        ret.times %= MOD ;
    }
    if ( p2.val == ret.val ) {
        ret.times += p2.times ;
        ret.times %= MOD ;
    }
    return ret ;
}

class Tree {
    public :
    tuhla tr[ 10 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ].val = tr[ where ].times = 0 ;
        tr[ where ].fl = false ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }

    void update ( int where , int IL , int IR , int pos , pair < ll , ll > aux ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            if ( tr[ where ].fl == false ) {
                tr[ where ].val = aux.first ;
                tr[ where ].times = aux.second ;
                tr[ where ].fl = true ;
                return ;
            }
            if ( aux.first < tr[ where ].val ) {
                tr[ where ].val = aux.first ;
                tr[ where ].times = 0 ;
            }
            if ( aux.first == tr[ where ].val ) {
                tr[ where ].times += aux.second ;
                tr[ where ].times %= MOD ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , aux ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , aux ) ;
        }
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    tuhla query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURR < IL || IR < CURL ) { return tuhla ( ) ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return merge ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void compress ( ) {
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    int sz = srt.size ( ) ;
    MAXID = 1 ;
    ZX[ srt[ 0 ] ] = 1 ;
    for ( int i = 1 ; i < sz ; i ++ ) {
        if ( srt[ i ] == srt[ i - 1 ] ) { continue ; }
        ZX[ srt[ i ] ] = ++ MAXID ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        srt.push_back ( a[ i ].first ) ;
        srt.push_back ( a[ i ].second ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    compress ( ) ;
}

void solve ( ) {
    w.init ( 1 , 1 , MAXID ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        tuhla ret = w.query ( 1 , 1 , MAXID , 1 , ZX[ a[ i ].second ] ) ;
        if ( ret.fl == false ) {
            dp[ i ] = { a[ i ].second , 1 } ;
        }
        else {
            dp[ i ] = { ret.val + a[ i ].second , ret.times } ;
        }
        w.update ( 1 , 1 , MAXID , ZX[ a[ i ].first ] , { dp[ i ].first - a[ i ].first , dp[ i ].second } ) ;
    }
    int mxsecond = -1 ;
    pair < ll , ll > ans = { 0 , 0 } ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( a[ i ].first <= mxsecond ) { break ; }
        if ( mxsecond < a[ i ].second ) { mxsecond = a[ i ].second ; }
        if ( ans.first > dp[ i ].first || i == n ) { ans = dp[ i ] ; }
        else if ( ans.first == dp[ i ].first ) {
            ans.second += dp[ i ].second ;
            ans.second %= MOD ;
        }
    }
    printf ( "%I64d\n" , ans.second ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}