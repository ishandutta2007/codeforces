#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
long long inf = ( 1LL << 36 ) ;

int n ;
long long a[ MAXN ] ;
long long b[ MAXN ] ;


int rv[ 4 * MAXN ] ;

long long init ;

struct tuhla {
    long long x ;
    int type ;
    int id ;
    tuhla ( ) { x = type = id = 0 ; }
    tuhla ( long long _x , int _type , int _id ) {
        x = _x ; type = _type ; id = _id ;
    }
};

vector < tuhla > srt ;

int stat[ MAXN ] ;

int MAXVAL ;

void input ( ) {
    cin >> n ;
    
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        srt.push_back ( tuhla ( a[ i ] , 1 , i ) ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
        srt.push_back ( tuhla ( b[ i ] , -1 , i ) ) ;
        if ( a[ i ] >= b[ i ] ) { init += a[ i ] - b[ i ] ; }
        else { init += b[ i ] - a[ i ] ; }
    }
    sort ( srt.begin ( ) , srt.end ( ) , [ & ] ( tuhla p1 , tuhla p2 ) {
        if ( p1.x != p2.x ) { return ( p1.x < p2.x ) ; }
        return p1.type < p2.type ;
    } ) ;

    set < int > hh ;
    map < int , int > w ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        hh.insert ( a[ i ] ) ;
        hh.insert ( b[ i ] ) ;
    }
    int mxid = 1 ;
    for ( auto val : hh ) {
        rv[ mxid ] = val ;
        w[ val ] = mxid ++ ;
    }
    MAXVAL = mxid - 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = w[ a[ i ] ] ;
        b[ i ] = w[ b[ i ] ] ;
    }
}

class Tree {
public :
    long long tr[ 10 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = inf ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , long long sr ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = min ( tr[ where ] , sr ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) { update ( 2 * where , IL , mid , pos , sr ) ; }
        else { update ( 2 * where + 1 , mid + 1 , IR , pos , sr ) ; }

        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }

    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return inf ; }
        if ( IR < CURL || CURR < IL ) { return inf ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return min ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w_AB ;
Tree w_BA ;

void solve ( ) {
    long long ans = 0 ;
    w_AB.init ( 1 , 1 , MAXVAL ) ;
    w_BA.init ( 1 , 1 , MAXVAL ) ;    
    // BA/AB AB/BA
    for ( int i = 0 ; i < 2 * n ; ++ i ) {
        int wh = srt[ i ].id ;
        if ( srt[ i ].type == 1 ) {
            if ( stat[ wh ] == 0 ) {
                long long cand = - ( rv[ b[ wh ] ] - rv[ a[ wh ] ] ) ;
                cand -= rv[ b[ wh ] ] ;
                cand -= rv[ a[ wh ] ] ;
                w_AB.update ( 1 , 1 , MAXVAL , b[ wh ] , cand ) ;


                long long sr = w_BA.query ( 1 , 1 , MAXVAL , a[ wh ] , b[ wh ] ) + rv[ a[ wh ] ] + rv[ b[ wh ] ] - ( rv[ b[ wh ] ] - rv[ a[ wh ] ] ) ;
                ans = min ( ans , sr ) ;
            }
        }
        else {
            if ( stat[ wh ] == 0 ) {
                long long cand = - ( rv[ a[ wh ] ] - rv[ b[ wh ] ] ) ;
                cand -= rv[ b[ wh ] ] ;
                cand -= rv[ a[ wh ] ] ;
                w_BA.update ( 1 , 1 , MAXVAL , a[ wh ] , cand ) ;

                long long sr = w_AB.query ( 1 , 1 , MAXVAL , b[ wh ] , a[ wh ] ) + rv[ a[ wh ] ] + rv[ b[ wh ] ] - ( rv[ a[ wh ] ] - rv[ b[ wh ] ] ) ;
                ans = min ( ans , sr ) ;
            }
        }
        stat[ wh ] ^= 1 ;
    }
    w_AB.init ( 1 , 1 , MAXVAL ) ;
    w_BA.init ( 1 , 1 , MAXVAL ) ;    
    // B/AB\A A/BA\B

    for ( int i = 0 ; i < 2 * n ; ++ i ) {
        int wh = srt[ i ].id ;
        if ( srt[ i ].type == 1 ) {
            if ( stat[ wh ] == 0 ) {
                long long cand = - ( rv[ b[ wh ] ] - rv[ a[ wh ] ] ) ;
                cand += rv[ b[ wh ] ] ;
                cand -= rv[ a[ wh ] ] ;
                w_AB.update ( 1 , 1 , MAXVAL , b[ wh ] , cand ) ;


                long long sr = w_BA.query ( 1 , 1 , MAXVAL , b[ wh ] , MAXVAL ) + rv[ a[ wh ] ] - rv[ b[ wh ] ] - ( rv[ b[ wh ] ] - rv[ a[ wh ] ] ) ;
                ans = min ( ans , sr ) ;
            }
        }
        else {
            if ( stat[ wh ] == 0 ) {
                long long cand = - ( rv[ a[ wh ] ] - rv[ b[ wh ] ] ) ;
                cand -= rv[ b[ wh ] ] ;
                cand += rv[ a[ wh ] ] ;
                w_BA.update ( 1 , 1 , MAXVAL , a[ wh ] , cand ) ;

                long long sr = w_AB.query ( 1 , 1 , MAXVAL , a[ wh ] , MAXVAL ) - rv[ a[ wh ] ] + rv[ b[ wh ] ] - ( rv[ a[ wh ] ] - rv[ b[ wh ] ] ) ;
                ans = min ( ans , sr ) ;
            }
        }
        stat[ wh ] ^= 1 ;
    }
    cout << ans + init << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}