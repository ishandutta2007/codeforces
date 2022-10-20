#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
long long inf ;

int n ;
int a[ MAXN ] ;

long long base ;
pair < long long , long long > diff[ MAXN ] ;

struct node {
    bool fl ;
    long long mxneg ;
    long long mxsum ;
    node ( ) { fl = false , mxneg = -inf , mxsum = -2 * inf ; }
    node ( long long fst , long long scd ) {
        fl = ( fst >= 0 && scd >= 0 ) ;
        if ( fl == false ) {
            if ( fst >= 0 ) {
                mxneg = scd ;
                mxsum = -2 * inf ;
            }
            else if ( scd >= 0 ) {
                mxneg = fst ;
                mxsum = -2 * inf ;
            }
            else {
                mxneg = -inf ;
                mxsum = fst + scd ;
            }
        }
        else {
            mxneg = - inf ;
            mxsum = -2 * inf ;
        }
    }
};

node unite ( node p1 , node p2 ) {
    node ret ;
    ret.fl = ( p1.fl | p2.fl ) ;
    ret.mxneg = max ( p1.mxneg , p2.mxneg ) ;
    ret.mxsum = max ( p1.mxsum , p2.mxsum ) ;
    return ret ;
}

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where ,  int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = node ( diff[ IL ].first , diff[ IL ].second ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = node ( diff[ IL ].first , diff[ IL ].second ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos ) ;
        }
        else { update ( 2 * where + 1 , mid + 1 , IR , pos ) ; }
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return node ( ) ; }
        if ( IR < CURL || CURR < IL ) { return node ( ) ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return unite ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        if ( i > 1 ) {
            base += abs ( a[ i ] - a[ i - 1 ] ) ;
            diff[ i ].first = a[ i ] - a[ i - 1 ] ;
            diff[ i - 1 ].second = a[ i - 1 ] - a[ i ] ;
        }
    }
    inf = 1 ;
    for ( int i = 1 ; i <= 15 ; ++ i ) { inf *= 10 ; }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int q ;
    int type , l , r , x ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        scanf ( "%d%d%d%d" , &type , &l , &r , &x ) ;
        if ( type == 2 ) {
            if ( l > 1 ) {
                base -= llabs ( diff[ l ].first ) ;
                diff[ l - 1 ].second -= x ; 
                diff[ l ].first += x ;
                base += llabs ( diff[ l ].first ) ;
                w.update ( 1 , 1 , n , l - 1 ) ;
                w.update ( 1 , 1 , n , l ) ;
            }
            if ( r < n ) {
                base -= llabs ( diff[ r ].second ) ;
                diff[ r ].second += x ;
                diff[ r + 1 ].first -= x ;
                base += llabs ( diff[ r ].second ) ;
                w.update ( 1 , 1 , n , r ) ;
                w.update ( 1 , 1 , n , r + 1 ) ;
            }
        }
        else {
            node ret = w.query ( 1 , 1 , n , l , r ) ;
            if ( ret.fl == true ) {
                printf ( "%lld\n" , base + 2 * x ) ;
            }
            else {
                if ( l == r ) {
                    long long hh = base ;
                    if ( l > 1 ) {
                        hh -= llabs ( diff[ l ].first ) ;
                        hh += llabs ( diff[ l ].first + x ) ;
                    }
                    if ( r < n ) {
                        hh -= llabs ( diff[ r ].second ) ;
                        hh += llabs ( diff[ r ].second + x ) ;
                    }
                    printf ( "%lld\n" , hh ) ;
                }
                else {
                    long long cand1 = base + x - llabs ( ret.mxneg ) + llabs ( x + ret.mxneg ) ;
                    long long cand2 = base - llabs ( ret.mxsum ) + llabs ( ret.mxsum + 2 * x ) ;
                    printf ( "%lld\n" , max ( cand1 , cand2 ) ) ;
                }
            }
        }
    }
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