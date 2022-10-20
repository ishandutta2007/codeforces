#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 200007
#define MOD 998244353
long long base[ 2 ] = { 31 , 83 } ;


struct hsh {
    int len ;
    long long h[ 2 ] ;
    hsh ( ) { len = h[ 0 ] = h[ 1 ] = 0 ; }
    bool operator < ( const hsh other ) const {
        if ( len < other.len ) { return true ; }
        if ( len > other.len ) { return false ; }
        if ( h[ 0 ] < other.h[ 0 ] ) { return true ; }
        if ( h[ 0 ] > other.h[ 0 ] ) { return false ; }
        if ( h[ 1 ] < other.h[ 1 ] ) { return true ; }
        return false ;
    }
};

long long pw[ 2 ][ MAXN ] ;
hsh in , out ;

hsh unite ( hsh st , hsh en ) {
    hsh ret = st ;
    ret.len += en.len ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        ret.h[ i ] = ( ret.h[ i ] * pw[ i ][ en.len ] ) % MOD ;
        ret.h[ i ] += en.h[ i ] ;
        if ( ret.h[ i ] >= MOD ) { ret.h[ i ] -= MOD ; }
    }
    return ret ;
}

int n ;
vector < pair < int , int > > v[ MAXN ] ;
int prv_edge[ MAXN ] ;
hsh up[ MAXN ] ;
hsh down[ MAXN ] ;

vector < pair < hsh , int > > aux ;

void dfs_down ( int vertex , int prv ) {
    for ( auto [ x , pos ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        prv_edge[ x ] = pos ;
        dfs_down ( x , vertex ) ;
    }
    aux.clear ( ) ;
    for ( auto [ x , pos ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        aux.push_back ( { down[ pos ] , 0 } ) ;
    }
    if ( vertex == 1 ) { return ; }
    sort ( aux.begin ( ) , aux.end ( ) ) ;
    int wh = prv_edge[ vertex ] ;
    down[ wh ] = hsh ( ) ;
    for ( auto [ nw , foo ] : aux ) {
        down[ wh ] = unite ( down[ wh ] , in ) ;
        down[ wh ] = unite ( down[ wh ] , nw ) ;
        down[ wh ] = unite ( down[ wh ] , out ) ;
    }
}

hsh pref[ MAXN ] ;
hsh suff[ MAXN ] ;

void dfs_up ( int vertex , int prv ) {
    aux.clear ( ) ;
    for ( auto [ x , pos ] : v[ vertex ] ) {
        if ( x == prv ) { aux.push_back ( { up[ pos ] , -1 } ) ; }
        else { aux.push_back ( { down[ pos ] , pos } ) ; }
    }
    sort ( aux.begin ( ) , aux.end ( ) ) ;
    int sz = aux.size ( ) ;
    pref[ 0 ] = hsh ( ) ; suff[ sz + 1 ] = hsh ( ) ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        pref[ i ] = unite ( pref[ i - 1 ] , in ) ;
        pref[ i ] = unite ( pref[ i ] , aux[ i - 1 ].first ) ;
        pref[ i ] = unite ( pref[ i ] , out ) ;
    }
    for ( int i = sz ; i >= 1 ; -- i ) {
        suff[ i ] = unite ( in , aux[ i - 1 ].first ) ;
        suff[ i ] = unite ( suff[ i ] , out ) ;
        suff[ i ] = unite ( suff[ i ] , suff[ i + 1 ] ) ;
    }
    for ( int i = 1 ; i <= sz ; ++ i ) {
        if ( aux[ i - 1 ].second < 0 ) { continue ; }
        up[ aux[ i - 1 ].second ] = unite ( pref[ i - 1 ] , suff[ i + 1 ] ) ;
    }
    for ( auto [ x , pos ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dfs_up ( x , vertex ) ;
    }
}


int mxans = -2 ;
int mxid = 0 ;
map < hsh , int > w ;


void calc ( int vertex , int prv ) {
    int sr = w.size ( ) ;
    if ( mxans < sr ) { mxans = sr , mxid = vertex ; }
    for ( auto [ x , pos ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        ++ w[ up[ pos ] ] ;
        -- w[ down[ pos ] ] ;
        if ( w[ down[ pos ] ] == 0 ) { w.erase ( down[ pos ] ) ; }

        calc ( x , vertex ) ;

        ++ w[ down[ pos ] ] ;
        -- w[ up[ pos ] ] ;
        if ( w[ up[ pos ] ] == 0 ) { w.erase ( up[ pos ] ) ; }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ; scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( { y , i } ) ;
        v[ y ].push_back ( { x , i } ) ;
    }
    pw[ 0 ][ 0 ] = pw[ 1 ][ 0 ] = 1 ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            pw[ j ][ i ] = ( pw[ j ][ i - 1 ] * base[ j ] ) % MOD ;
        }
    }
    in = out = hsh ( ) ;
    in.len = out.len = 1 ;
    in.h[ 0 ] = in.h[ 1 ] = 2 ;
    out.h[ 0 ] = out.h[ 1 ] = 5 ;
}

void solve ( ) {
    dfs_down ( 1 , -1 ) ;
    dfs_up ( 1 , -1 ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        ++ w[ down[ i ] ] ;
    }
    calc ( 1 , -1 ) ;
    printf ( "%d\n" , mxid ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}