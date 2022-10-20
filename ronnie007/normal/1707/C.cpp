#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 7 ;
const int LOG = 20 ;

int n , m ;
vector < int > v[ MAXN ] ;
pair < int , int > a[ MAXN ] ;
int st[ MAXN ] , en[ MAXN ] ;
int prv[ MAXN ] , rnk[ MAXN ] ;
int LCA[ MAXN ][ 20 ] , lvl[ MAXN ] ;

int get ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = get ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

bool unite ( int x , int y ) {
    int k1 = get ( x ) , k2 = get ( y ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            prv[ k2 ] = k1 ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
        return true ;
    }
    return false ;
}

bool used[ MAXN ] ;
int tp = 0 ;

void dfs ( int x , int lst ) {
    st[ x ] = ++ tp ;
    for ( int i = 1 ; i < LOG ; ++ i ) {
        LCA[ x ][ i ] = LCA[ LCA[ x ][ i - 1 ] ][ i - 1 ] ;
    }
    for ( auto y : v[ x ] ) {
        if ( y == lst ) { continue ; }
        LCA[ y ][ 0 ] = x ;
        lvl[ y ] = lvl[ x ] + 1 ;
        dfs ( y , x ) ;
    }
    en[ x ] = tp ;
}

class Tree {
public :
    bool tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = false ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            tr[ where ] = true ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
    int query ( int where , int IL , int IR , int pos ) {
        if ( tr[ where ] == true ) { return 0 ; }
        if ( IL == IR ) { return 1 ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) { return query ( 2 * where , IL , mid , pos ) ; }
        else { return query ( 2 * where + 1 , mid + 1 , IR , pos ) ; }
    }
};
Tree w ;

int move_up ( int x , int cnt ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( cnt >= ( 1 << i ) ) {
            cnt -= ( 1 << i ) ;
            x = LCA[ x ][ i ] ;
        }
    }
    return x ;
}

void solve ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 , rnk[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
        used[ i ] = unite ( a[ i ].first , a[ i ].second ) ;
        if ( used[ i ] == true ) {
            v[ a[ i ].first ].push_back ( a[ i ].second ) ;
            v[ a[ i ].second ].push_back ( a[ i ].first ) ;
        }
    }
    dfs ( 1 , -1 ) ;
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( used[ i ] == true ) { continue ; }
        int x = a[ i ].first , y = a[ i ].second ;
        if ( st[ x ] > st[ y ] ) { swap ( x , y ) ; }
        if ( st[ x ] <= st[ y ] && en[ y ] <= en[ x ] ) {
            int hh = move_up ( y , lvl[ y ] - lvl[ x ] - 1 ) ;
            w.update ( 1 , 1 , n , st[ hh ] , st[ y ] - 1 ) ;
            w.update ( 1 , 1 , n , en[ y ] + 1 , en[ hh ] ) ;
        }
        else {
            w.update ( 1 , 1 , n , 1 , st[ x ] - 1 ) ;
            w.update ( 1 , 1 , n , en[ x ] + 1 , st[ y ] - 1 ) ;
            w.update ( 1 , 1 , n , en[ y ] + 1 , n ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << w.query ( 1 , 1 , n , st[ i ] ) ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}