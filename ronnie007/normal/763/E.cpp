#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 100007

int n , k ;
vector < int > v[ MAXN ] ;

struct node {
    int comps , l , r ;
    vector < int > st ;
    vector < int > en ;
    node ( ) { comps = r = 0 ; l = MAXN ; st.clear ( ) ; en.clear ( ) ; }
    node ( int _l , int _r ) {
        l = _l , r = _r ;
        comps = r - l + 1 ;
        for ( int i = l ; i <= r ; ++ i ) { st.push_back ( i ) ; }
        for ( int i = r ; i >= l ; -- i ) { en.push_back ( i ) ; }
    }
};

node unite ( node p1 , node p2 ) {
    node ret = node ( ) ;
    ret.comps = p1.comps + p2.comps ;
    ret.l = min ( p1.l , p2.l ) , ret.r = max ( p1.r , p2.r ) ;

    int sz1 = p1.en.size ( ) ;
    int sz2 = p2.st.size ( ) ;
    for ( int i = 0 ; i < sz1 ; ++ i ) {
        int act = p1.r - i ;
        for ( auto nw : v[ act ] ) {
            if ( p2.l <= nw && nw <= p2.r ) {
                if ( nw - p2.l < sz2 ) {
                    int rem = p2.st[ nw - p2.l ] ;
                    if ( rem == p1.en[ i ] ) { continue ; }
                    -- ret.comps ;
                    for ( auto &x : p2.st ) {
                        if ( x == rem ) { x = p1.en[ i ] ; }
                    }
                    for ( auto &x : p2.en ) {
                        if ( x == rem ) { x = p1.en[ i ] ; }
                    }
                }
            }
        }
    }
    ret.st = p1.st ;
    for ( auto x : p2.st ) {
        if ( ret.st.size ( ) >= k ) { break ; }
        ret.st.push_back ( x ) ;
    }

    ret.en = p2.en ;
    for ( auto x : p1.en ) {
        if ( ret.en.size ( ) >= k ) { break ; }
        ret.en.push_back ( x ) ;
    }
    return ret ;
}

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = node ( IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
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
    scanf ( "%d%d" , &n , &k ) ;
    int m ; scanf ( "%d" , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ; scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int q ; scanf ( "%d" , &q ) ;
    while ( q -- ) {
        int l , r ; scanf ( "%d%d" , &l , &r ) ;
        node ret = w.query ( 1 , 1 , n , l , r ) ;
        printf ( "%d\n" , ret.comps ) ;
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