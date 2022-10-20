#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , k ;
int cap[ 2 ] ;
int q ;

class Tree {
public :
    long long tr[ 4 * MAXN ][ 2 ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ][ 0 ] = tr[ where ][ 1 ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void unite ( int where ) {
        for ( int i = 0 ; i < 2 ; ++ i ) {
            tr[ where ][ i ] = tr[ 2 * where ][ i ] + tr[ 2 * where + 1 ][ i ] ;
        }
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            for ( int i = 0 ; i < 2 ; ++ i ) {
                tr[ where ][ i ] += val ;
                tr[ where ][ i ] = min ( tr[ where ][ i ] , 1LL * cap[ i ] ) ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        unite ( where ) ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR , int id ) {
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ][ id ] ; }
        int mid = ( IL + IR ) / 2 ;
        return query ( 2 * where , IL , mid , CURL , CURR , id ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , id ) ;
    }
};
Tree w ;


void input ( ) {
    scanf ( "%d%d%d%d%d" , &n , &k , &cap[ 0 ] , &cap[ 1 ] , &q ) ;
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    while ( q -- ) {
        int type ;
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            int x , y ;
            scanf ( "%d%d" , &x , &y ) ;
            w.update ( 1 , 1 , n , x , y ) ;
        }
        else {
            int st ;
            scanf ( "%d" , &st ) ;
            int en = st + k - 1 ;
            long long ans = w.query ( 1 , 1 , n , 1 , st - 1 , 1 ) + w.query ( 1 , 1 , n , en + 1 , n , 0 ) ;
            printf ( "%lld\n" , ans ) ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}