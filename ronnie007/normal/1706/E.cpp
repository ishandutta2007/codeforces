#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 2e5 + 7 ;
const int LOG = 20 ;

int n , m , q ;
pair < int , int > a[ MAXN ] ;

vector < pair < int , int > > rootlist[ MAXN ] ;

int prv[ MAXN ] , sz[ MAXN ] ;
vector < int > comp[ MAXN ] ;

int get ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = get ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void unite ( int x , int y , int id ) {
    int k1 = get ( x ) , k2 = get ( y ) ;
    if ( k1 != k2 ) {
        if ( sz[ k1 ] > sz[ k2 ] ) { swap ( k1 , k2 ) ; }
        sz[ k2 ] += sz[ k1 ] ;
        for ( auto x : comp[ k1 ] ) {
            prv[ x ] = k2 ;
            rootlist[ x ].push_back ( { k2 , id } ) ;
            comp[ k2 ].push_back ( x ) ;
        }
    }
}

int mxst[ MAXN ] ;
pair < int , int > LCA[ LOG ][ MAXN ] ;

pair < int , int > merge ( pair < int , int > p1 , pair < int , int > p2 ) {
    int x = p1.first , y = p2.first ;
    pair < int , int > ret ;
    ret.second = max ( p1.second , p2.second ) ;
    int len1 = rootlist[ x ].size ( ) , len2 = rootlist[ y ].size ( ) ;
    for ( int i = 0 ; i < len1 ; ++ i ) {
        for ( int j = 0 ; j < len2 ; ++ j ) {
            if ( rootlist[ x ][ i ].first == rootlist[ y ][ j ].first ) {
                ret.first = rootlist[ x ][ i ].first ;
                ret.second = max ( ret.second , rootlist[ x ][ i ].second ) ;
                ret.second = max ( ret.second , rootlist[ y ][ j ].second ) ;
                return ret ;
            }
        }
    }
    return ret ;
}

void solve ( ) {
    cin >> n >> m >> q ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        comp[ i ].clear ( ) ;
        rootlist[ i ].clear ( ) ;
        prv[ i ] = -1 , sz[ i ] = 1 ;
        rootlist[ i ].push_back ( { i , 0 } ) ;
        comp[ i ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        unite ( a[ i ].first , a[ i ].second , i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        LCA[ 0 ][ i ] = rootlist[ i ][ 0 ] ;
    }
    for ( int lvl = 1 ; lvl < LOG ; ++ lvl ) {
        for ( int i = 1 ; i + ( 1 << lvl ) - 1 <= n ; ++ i ) {
            LCA[ lvl ][ i ] = merge ( LCA[ lvl - 1 ][ i ] , LCA[ lvl - 1 ][ i + ( 1 << ( lvl - 1 ) ) ] ) ;
        }
    }
    int pos = 0 , len = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( 2 * len < i ) {
            len *= 2 , ++ pos ;
        }
        mxst[ i ] = pos ;
    }
    for ( int i = 1 , l , r ; i <= q ; ++ i ) {
        cin >> l >> r ; 
        pair < int , int > aux1 = LCA[ mxst[ r - l + 1 ] ][ l ] ;
        pair < int , int > aux2 = LCA[ mxst[ r - l + 1 ] ][ r - ( 1 << mxst[ r - l + 1 ] ) + 1 ] ;
        pair < int , int > ret = merge ( aux1 , aux2 ) ;
        cout << ret.second << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}