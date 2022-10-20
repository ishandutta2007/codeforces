#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 4e5 + 7 ;

int l , r ;
vector < int > divs[ MAXN ] ;

void init ( ) {
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        for ( int j = 2 * i ; j < MAXN ; j += i ) {
            divs[ j ].push_back ( i ) ;
        }
    }
}

ll lcm ( ll x , ll y ) {
    ll ret = x * y ;
    ll aux = __gcd ( x , y ) ;
    ret /= aux ;
    return ret ;
}

int q ;
pair < int , int > a[ MAXN ] ;
vector < pair < int , int > > qlist[ MAXN ] ;
ll ans[ MAXN ] ;
int coef[ MAXN ] ;

class Tree {
public :
    ll tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int add ) {
        if ( IL == IR ) {
            tr[ where ] += add ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) { update ( 2 * where , IL , mid , pos , add ) ; }
        else { update ( 2 * where + 1 , mid + 1 , IR , pos , add ) ; }
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    ll query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};
Tree w ;

const int mx = 2e5 ;

void solve ( ) {
    cin >> q ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
        qlist[ a[ i ].second ].push_back ( { a[ i ].first , i } ) ;
    }
    w.init ( 1 , 1 , mx ) ;
    for ( int i = 1 ; i <= mx ; ++ i ) {
        ll hh = 0 ;
        int tp = divs[ i ].size ( ) ;
        for ( auto x : divs[ i ] ) {
            -- tp ;
            w.update ( 1 , 1 , mx , x , tp ) ;
        }
        int sz = divs[ 2 * i ].size ( ) ;
        for ( int j = sz - 2 ; j >= 0 ; -- j ) {
            if ( divs[ 2 * i ][ j ] < l ) { break ; }
            if ( divs[ 2 * i ][ j ] == i ) { continue ; }
            for ( int t = sz - 1 ; t > j ; -- t ) {
                if ( divs[ 2 * i ][ t ] < l ) { break ; }
                if ( divs[ 2 * i ][ t ] == i ) { continue ; }
                ll hh = lcm ( divs[ 2 * i ][ j ] , divs[ 2 * i ][ t ] ) ;
                hh = lcm ( hh , i ) ;
                if ( hh != 2 * i ) { continue ; }
                if ( divs[ 2 * i ][ j ] + divs[ 2 * i ][ t ] + i <= 2 * i ) { break ; }
                ++ coef[ divs[ 2 * i ][ j ] ] ;
            }
        }
        for ( auto x : divs[ 2 * i ] ) {
            w.update ( 1 , 1 , mx , x , coef[ x ] ) ;
            coef[ x ] = 0 ;
        }

        for ( auto [ l , id ] : qlist[ i ] ) {
            ans[ id ] = w.query ( 1 , 1 , mx , l , i ) ;
        }
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        ll len = ( a[ i ].second - a[ i ].first + 1 ) ;
        ll ret = len * ( len - 1 ) * ( len - 2 ) / 6 ;
        cout << ret - ans[ i ] << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}