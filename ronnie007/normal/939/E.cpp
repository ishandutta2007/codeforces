#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 500007

int q ;

struct tuhla {
    int type ;
    int x ;
};
tuhla a[ MAXN ] ;

vector < pair < int , int > > srt ;
int MXVAL ;
map < int , int > REV ;

class Tree {
    public :
    int br[ 3 * MAXN ] ;
    long long sm[ 3 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        br[ where ] = sm[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            br[ where ] ++ ;
            sm[ where ] += val ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , pos , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        br[ where ] = ( br[ 2 * where ] + br[ 2 * where + 1 ] ) ;
        sm[ where ] = ( sm[ 2 * where ] + sm[ 2 * where + 1 ] ) ;
    }
    long long query ( int where , int IL , int IR , int sr ) {
        if ( br[ where ] == sr ) { return sm[ where ] ; }
        if ( sr == 0 ) { return 0 ; }
        long long ret = 0 ;
        int mid = ( IL + IR ) / 2 ;
        if ( br[ 2 * where ] <= sr ) {
            ret += sm[ 2 * where ] ;
            sr -= br[ 2 * where ] ;
        }
        else {
            return query ( 2 * where , IL , mid , sr ) ;
        }
        if ( sr > 0 ) {
            ret += query ( 2 * where + 1 , mid + 1 , IR , sr ) ;
        }
        return ret ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d" , &q ) ;
    int i ;
    for ( i = 1 ; i <= q ; i ++ ) {
        scanf ( "%d" , &a[ i ].type ) ;
        if ( a[ i ].type == 1 ) {
            scanf ( "%d" , &a[ i ].x ) ;
            srt.push_back ( make_pair ( a[ i ].x , i ) ) ;
        }
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    MXVAL = srt.size ( ) ;
    for ( i = 0 ; i < MXVAL ; i ++ ) {
        REV[ srt[ i ].second ] = i + 1 ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , MXVAL ) ;
    long long mx = 0 ;
    int br = 0 ;
    int tot = 0 ;
    int i ;
    for ( i = 1 ; i <= q ; i ++ ) {
        if ( a[ i ].type == 1 ) {
            w.update ( 1 , 1 , MXVAL , REV[ i ] , a[ i ].x ) ;
            if ( mx < a[ i ].x ) { mx = a[ i ].x ; }
            tot ++ ;
        }
        else {
            while ( br <= tot - 2 ) {
                long long u1 = w.query ( 1 , 1 , MXVAL , br ) ;
                long long u2 = w.query ( 1 , 1 , MXVAL , br + 1 ) ;
                u1 += mx ;
                u2 += mx ;
                double sr1 = ( 1.00 * u1 ) / ( br + 1 ) ;
                double sr2 = ( 1.00 * u2 ) / ( br + 2 ) ;
                if ( sr2 < sr1 ) { br ++ ; }
                else { break ; }
            }
            long long ret = w.query ( 1 , 1 , MXVAL , br ) ;
            ret += mx ;
            printf ( "%.12lf\n" , ( mx - ( 1.00 * ret ) / ( br + 1 ) ) ) ;
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