#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , q ;
int a[ MAXN ] ;

set < int > s[ MAXN ] ;

struct node {
    int mnval ;
    int sm , pref , suff ;
    int range_mx ;
    int lazy ;
    node ( ) { mnval = sm = pref = suff = range_mx = lazy = 0 ; }
};

node unite ( node p1 , node p2 ) {
    node ret ;
    ret.lazy = 0 ;
    ret.range_mx = max ( p1.range_mx , p2.range_mx ) ;
    ret.mnval = min ( p1.mnval , p2.mnval ) ;
    if ( p1.mnval < p2.mnval ) {
        ret.sm = p1.sm ;
        ret.pref = p1.pref ;
        ret.suff = max ( p1.suff , p2.range_mx ) ;
    }
    else if ( p1.mnval > p2.mnval ) {
        ret.sm = p2.sm ;
        ret.suff = p2.suff ;
        ret.pref = max ( p1.range_mx , p2.pref ) ;
    }
    else {
        ret.sm = p1.sm + p2.sm + max ( p1.suff , p2.pref ) ;
        ret.pref = p1.pref ;
        ret.suff = p2.suff ;
    }
    return ret ;
}

class Tree {
    public :
    node tr[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        if ( tr[ where ].lazy == 0 ) { return ; }
        tr[ where ].mnval += tr[ where ].lazy ;
        if ( IL != IR ) {
            tr[ 2 * where ].lazy += tr[ where ].lazy ;
            tr[ 2 * where + 1 ].lazy += tr[ where ].lazy ;
        }
        tr[ where ].lazy = 0 ;
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ] = node ( ) ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update_range ( int where , int IL , int IR , int CURL , int CURR , int add ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            tr[ where ].lazy += add ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_range ( 2 * where , IL , mid , CURL , CURR , add ) ;
        update_range ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , add ) ;
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update_pos ( int where , int IL , int IR , int pos , int nw ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ].range_mx = tr[ where ].suff = nw ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_pos ( 2 * where , IL , mid , pos , nw ) ;
        update_pos ( 2 * where + 1 , mid + 1 , IR , pos , nw ) ;
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
};
Tree w ;

void add_state ( int i , int coef ) {
    if ( s[ i ].empty ( ) == true ) { return ; }
    int fst = *s[ i ].begin ( ) ;
    int lst = *s[ i ].rbegin ( ) ;
    int sz = s[ i ].size ( ) ;
    w.update_range ( 1 , 1 , n + 1 , fst + 1 , lst , coef ) ;
    if ( coef == 1 ) {
        w.update_pos ( 1 , 1 , n + 1 , fst , sz ) ;
    }
    else {
        w.update_pos ( 1 , 1 , n + 1 , fst , 0 ) ;
    }
}

void input ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        s[ a[ i ] ].insert ( i ) ;
    }
    w.init ( 1 , 1 , n + 1 ) ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        if ( s[ i ].empty ( ) == false ) {
            add_state ( i , 1 ) ;
        }
    }
}

void solve ( ) {
    cout << n - w.tr[ 1 ].sm << "\n" ;
    while ( q -- ) {
        int wh , x ;
        cin >> wh >> x ;
        add_state ( a[ wh ] , -1 ) ;
        add_state ( x , -1 ) ;
        s[ a[ wh ] ].erase ( wh ) ;

        int rem = a[ wh ] ;
        a[ wh ] = x ;
        s[ a[ wh ] ].insert ( wh ) ;
        add_state ( rem , 1 ) ;
        add_state ( a[ wh ] , 1 ) ;

        cout << n - w.tr[ 1 ].sm << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    /// cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}