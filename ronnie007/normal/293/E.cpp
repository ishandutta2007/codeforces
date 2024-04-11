#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n , mxlen , mxdist ;
vector < pair < int , int > > v[ MAXN ] ;

bool used[ MAXN ] ;
int subtree[ MAXN ] ;
int lvl[ MAXN ] ;
int dist[ MAXN ] ;

long long ans ;

int tot ;

void init ( int vertex , int prv ) {
    ++ tot ;
    int sz = v[ vertex ].size ( ) ;
    subtree[ vertex ] = 1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ vertex ][ i ].first ;
        int cost = v[ vertex ][ i ].second ;
        if ( to == prv ) { continue ; }
        if ( used[ to ] == true ) { continue ; }
        lvl[ to ] = lvl[ vertex ] + 1 ;
        dist[ to ] = dist[ vertex ] + cost ;
        init ( to , vertex ) ;
        subtree[ vertex ] += subtree[ to ] ;
    }
}

int get_centroid ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ vertex ][ i ].first ;
        if ( to == prv ) { continue ; }
        if ( used[ to ] == true ) { continue ; }
        if ( subtree[ to ] > ( tot / 2 ) ) {
            return get_centroid ( to , vertex ) ;
        }
    }
    return vertex ;
}

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        tr[ where ] += val ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
    }
    void query ( int where , int IL , int IR , int CURL , int CURR , int coef ) {
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            ans += coef * tr[ where ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        query ( 2 * where , IL , mid , CURL , CURR , coef ) ;
        query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , coef ) ;
    }
};
Tree w ;

void add ( int vertex , int prv , int coef , vector < pair < int , int > > &ret ) {
    int sz = v[ vertex ].size ( ) ;
    if ( lvl[ vertex ] <= mxlen && dist[ vertex ] <= mxdist ) { ans += 2 ; }
    ret.push_back ( { dist[ vertex ] , lvl[ vertex ] } ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ vertex ][ i ].first ;
        if ( used[ to ] == true ) { continue ; }
        if ( to == prv ) { continue ; }
        add ( to , vertex , coef , ret ) ;
    }
}

void calc ( vector < pair < int , int > > &aux , int coef ) {
    int sz = aux.size ( ) ;
    int id = 0 ;
    for ( int i = sz - 1 ; i >= 0 ; -- i ) {
        while ( id < sz && aux[ id ].first + aux[ i ].first <= mxdist ) {
            w.update ( 1 , 1 , mxlen , aux[ id ].second , 1 ) ;
            ++ id ;
        }
        w.query ( 1 , 1 , mxlen , 1 , mxlen - aux[ i ].second , coef ) ;
    }
    for ( int i = 0 ; i < id ; ++ i ) {
        w.update ( 1 , 1 , mxlen , aux[ i ].second , -1 ) ;
    }
}

void decompose ( int vertex ) {
    tot = 0 ;
    init ( vertex , -1 ) ;
    int cen = get_centroid ( vertex , -1 ) ;
    tot = lvl[ cen ] = dist[ cen ] = 0 ;
    init ( cen , -1 ) ;
    int sz = v[ cen ].size ( ) ;
    vector < pair < int , int > > hh ;
    hh.clear ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ cen ][ i ].first ;
        if ( used[ to ] == true ) { continue ; }
        vector < pair < int , int > > aux ;
        aux.clear ( ) ;
        add ( to , cen , 1 , aux ) ;
        sort ( aux.begin ( ) , aux.end ( ) ) ;
        calc ( aux , -1 ) ;
        for ( auto val : aux ) {
            hh.push_back ( val ) ;
        }
    }
    sort ( hh.begin ( ) , hh.end ( ) ) ;
    calc ( hh , 1 ) ;
    used[ cen ] = true ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int to = v[ cen ][ i ].first ;
        if ( used[ to ] == true ) { continue ; }
        decompose ( to ) ;
    }
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &mxlen , &mxdist ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( { i , y } ) ;
        v[ i ].push_back ( { x , y } ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , mxlen ) ;
    decompose ( 1 ) ;
    printf ( "%I64d\n" , ( ans / 2 ) ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}