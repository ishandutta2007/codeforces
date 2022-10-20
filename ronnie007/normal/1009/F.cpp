#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n ;
vector < int > v[ MAXN ] ;

int subtree[ MAXN ] ;
int heavy[ MAXN ] ;
int lvl[ MAXN ] ;

int ans[ MAXN ] ;

class Tree {
public :
    pair < int , int > tr[ 4 * MAXN ] ;
    void unite ( int where ) {
        int l = 2 * where , r = 2 * where + 1 ;
        if ( tr[ l ].first >= tr[ r ].first ) {
            tr[ where ] = tr[ l ] ;
        }
        else {
            tr[ where ] = tr[ r ] ;
        }
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ] = { 0 , IL } ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IL == IR ) {
            tr[ where ].first += val ;
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
};
Tree w ;

void add ( int vertex , int prv , int coef ) {
    w.update ( 1 , 1 , n , lvl[ vertex ] , coef ) ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        add ( v[ vertex ][ i ] , vertex , coef ) ;
    }
}

void init ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    subtree[ vertex ] = 1 ;
    int mx = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        init ( v[ vertex ][ i ] , vertex ) ;
        subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
        if ( mx < subtree[ v[ vertex ][ i ] ] ) {
            mx = subtree[ v[ vertex ][ i ] ] ;
            heavy[ vertex ] = v[ vertex ][ i ] ;
        }
    }
}

void dfs ( int vertex , int prv , bool fl ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( v[ vertex ][ i ] == heavy[ vertex ] ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex , false ) ;
    }
    if ( heavy[ vertex ] > 0 ) {
        dfs ( heavy[ vertex ] , vertex , true ) ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( v[ vertex ][ i ] == heavy[ vertex ] ) { continue ; }
        add ( v[ vertex ][ i ] , vertex , 1 ) ;
    }
    w.update ( 1 , 1 , n , lvl[ vertex ] , 1 ) ;
    ans[ vertex ] = w.tr[ 1 ].second ;
    if ( fl == false ) {
        w.update ( 1 , 1 , n , lvl[ vertex ] , -1 ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( v[ vertex ][ i ] == prv ) { continue ; }
            add ( v[ vertex ][ i ] , vertex , -1 ) ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    lvl[ 1 ] = 1 ;
    init ( 1 , -1 ) ;
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    dfs ( 1 , -1 , true ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d\n" , ans[ i ] - lvl[ i ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}