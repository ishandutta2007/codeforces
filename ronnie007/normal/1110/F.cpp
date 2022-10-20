#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007
#define inf 1e15


int n , q ;
vector < pair < int , int > > v[ MAXN ] ;

struct query {
    int l , r ;
    int id ;
    query ( ) { l = r = id = 0 ; }
    query ( int _l , int _r , int _id ) {
        l = _l ;
        r = _r ;
        id = _id ;
    }
};

vector < query > to_solve[ MAXN ] ;
long long ans[ MAXN ] ;

long long dist[ MAXN ] ;
int st[ MAXN ] ;
int en[ MAXN ] ;
int rv[ MAXN ] ;
int tpid ;

void setup ( int vertex ) {
    st[ vertex ] = ++ tpid ;
    rv[ tpid ] = vertex ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int c = v[ vertex ][ i ].second ;
        dist[ h ] = dist[ vertex ] + c ;
        setup ( h ) ;
    }
    en[ vertex ] = tpid ;
}

class Tree {
public :
    long long tr[ 4 * MAXN ] ;
    long long lazy[ 4 * MAXN ] ;

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
        lazy[ where ] = 0 ;
        if ( IL == IR ) {
            if ( v[ rv[ IL ] ].size ( ) == 0 ) {
                tr[ where ] = dist[ rv[ IL ] ] ;
            }
            else {
                tr[ where ] = inf ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , long long aux ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += aux ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , aux ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , aux ) ;
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR ) { return inf ; }
        if ( IR < CURL || CURR < IL ) { return inf ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return min ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void act ( int vertex , int add ) {
    w.update ( 1 , 1 , n , 1 , st[ vertex ] - 1 , add ) ;
    w.update ( 1 , 1 , n , en[ vertex ] + 1 , n , add ) ;
    w.update ( 1 , 1 , n , st[ vertex ] , en[ vertex ] , - add ) ;
}

void dfs ( int vertex ) {
    int sz = to_solve[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int l = to_solve[ vertex ][ i ].l ;
        int r = to_solve[ vertex ][ i ].r ;
        int id = to_solve[ vertex ][ i ].id ;
        ans[ id ] = w.query ( 1 , 1 , n , l , r ) ;
    }
    sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int c = v[ vertex ][ i ].second ;
        act ( h , c ) ;
        dfs ( h ) ;
        act ( h , -c ) ;
    }
}

void input ( ) {
    cin >> n >> q ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( { i , y } ) ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        int x , y , z ;
        cin >> x >> y >> z ;
        to_solve[ x ].push_back ( query ( y , z , i ) ) ;
    }
    setup ( 1 ) ;
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    dfs ( 1 ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        cout << ans[ i ] << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}