#include<bits/stdc++.h>
using namespace std ;

#define MAXN 71
#define MAXMASK ( 1 << 17 ) 
#define inf 2000000007

int n , m , a , b ;
vector < pair < int , int > > v[ MAXN ] ;

int prv[ MAXN ] , cnt[ MAXN ] ;
int comp[ MAXN ] , dist[ MAXN ][ MAXMASK ] ;

vector < pair < int , int > > aux ;

struct tuhla {
    int vertex , mask , cost ;
    tuhla ( ) { vertex = mask = cost = 0 ; }
    tuhla ( int _vertex , int _mask , int _cost ) {
        vertex = _vertex ;
        mask = _mask ;
        cost = _cost ;
    }
    bool operator < ( tuhla other ) const {
        return ( cost > other.cost ) ;
    }
};

priority_queue < tuhla > q ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    prv[ x ] = find ( prv[ x ] ) ;
    return prv[ x ] ;
}

void unite ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        cnt[ k2 ] += cnt[ k1 ] ;
        prv[ k1 ] = k2 ;
    }
}

void input ( ) {
    scanf ( "%d%d%d%d" , &n , &m , &a , &b ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
        cnt[ i ] = 1 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y , cost ;
        scanf ( "%d%d%d" , &x , &y , &cost ) ;
        if ( cost == a ) {
            v[ x ].push_back ( { y , cost } ) ;
            v[ y ].push_back ( { x , cost } ) ;
            unite ( x , y ) ;
        }
        else {
            aux.push_back ( { x , y } ) ;
        }
    }
}

int proc_mask ( int init , int add ) {
    if ( add == -1 ) { return init ; }
    return ( init | ( 1 << add ) ) ;
}

void solve ( ) {
    for ( auto [ x , y ] : aux ) {
        if ( find ( x ) != find ( y ) ) {
            v[ x ].push_back ( { y , b } ) ;
            v[ y ].push_back ( { x , b } ) ;
        }
    }
    int mxid = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        comp[ i ] = -1 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int root = find ( i ) ;
        if ( cnt[ root ] >= 4 ) {
            if ( comp[ root ] == -1 ) { comp[ root ] = mxid ++ ; }
            comp[ i ] = comp[ root ] ;
        }
    }
    int lim = ( 1 << mxid ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < lim ; ++ j ) {
            dist[ i ][ j ] = inf ;
        }
    }
    dist[ 1 ][ proc_mask ( 0 , comp[ 1 ] ) ] = 0 ;
    q.push ( tuhla ( 1 , proc_mask ( 0 , comp[ 1 ] ) , 0 ) ) ;
    while ( q.empty ( ) == false ) {
        auto [ x , mask , cost ] = q.top ( ) ;
        q.pop ( ) ;
        if ( dist[ x ][ mask ] != cost ) { continue ; }
        for ( auto [ nxt , edge ] : v[ x ] ) {
            if ( comp[ nxt ] == comp[ x ] ) {
                if ( dist[ nxt ][ mask ] > cost + edge ) {
                    dist[ nxt ][ mask ] = cost + edge ;
                    q.push ( tuhla ( nxt , mask , dist[ nxt ][ mask ] ) ) ;
                }
            }
            else if ( comp[ nxt ] == -1 || ( mask & ( 1 << comp[ nxt ] ) ) == 0 ) {
                int nwmask = proc_mask ( mask , comp[ nxt ] ) ;
                if ( dist[ nxt ][ nwmask ] > cost + edge ) {
                    dist[ nxt ][ nwmask ] = cost + edge ;
                    q.push ( tuhla ( nxt , nwmask , dist[ nxt ][ nwmask ] ) ) ;
                }
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int ret = inf ;
        for ( int j = 0 ; j < lim ; ++ j ) {
            ret = min ( ret , dist[ i ][ j ] ) ;
        }
        printf ( "%d " , ret ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}