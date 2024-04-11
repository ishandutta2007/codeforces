#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;


class Tree {
public :
    int tr[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void unite ( int where ) {
        ////
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ] += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ] = lazy[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update_range ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_range ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update_range ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        unite ( where ) ;
    }
    void update_pos ( int where , int IL , int IR , int pos , int nw ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            ///// 
            tr[ where ] = max ( tr[ where ] , nw ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_pos ( 2 * where , IL , mid , pos , nw ) ;
        update_pos ( 2 * where + 1 , mid + 1 , IR , pos , nw ) ;
        unite ( where ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        ///
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        ///
        if ( CURR < IL || IR < CURL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        ////
        return max ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int coef = 0 ;
        if ( a[ i ] != a[ i - 1 ] ) { ++ coef ; }

        int cand1 = w.query ( 1 , 1 , n , 1 , a[ i ] - 1 ) + 1 ;
        int cand2 = w.query ( 1 , 1 , n , a[ i ] + 1 , n ) + 1 ;
        int cand3 = w.query ( 1 , 1 , n , a[ i ] , a[ i ] ) ;
        int aux = max ( cand1 , cand2 ) ;
        aux = max ( aux , cand3 ) ;

        if ( coef == 1 ) {
            w.update_range ( 1 , 1 , n , 1 , n , 1 ) ;
        }
        if ( i > 1 ) {
            w.update_pos ( 1 , 1 , n , a[ i - 1 ] , aux ) ;
        }
    }
    cout << w.query ( 1 , 1 , n , 1 , n ) << "\n" ;
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