#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
long long inf ;


int n , m ;
vector < pair < int , int > > v[ MAXN ] ;

struct tuhla {
    int where ;
    int lst ;
    long long cost ;
    tuhla ( ) { where = lst = cost = 0 ; }
    tuhla ( int _where , int _lst , long long _cost ) {
        where = _where ; lst = _lst ; cost = _cost ;
    }
    bool operator < ( tuhla other ) const {
        return ( cost > other.cost ) ;
    }
};

long long dist[ MAXN ][ 53 ] ;

priority_queue < tuhla > q ;

void input ( ) {
    cin >> n >> m ;
    inf = 1 ;
    for ( int i = 1 ; i <= 15 ; ++ i ) { inf *= 10 ; }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y , z ;
        cin >> x >> y >> z ;
        v[ x ].push_back ( { y , z } ) ;
        v[ y ].push_back ( { x , z } ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= 51 ; ++ j ) {
            dist[ i ][ j ] = inf ;
        }
    }
}

void solve ( ) {
    dist[ 1 ][ 0 ] = 0 ;
    q.push ( tuhla ( 1 , 0 , 0 ) ) ;
    while ( q.empty ( ) == false ) {
        tuhla aux = q.top ( ) ;
        q.pop ( ) ;
        if ( aux.cost != dist[ aux.where ][ aux.lst ] ) { continue ; }
        for ( auto [ to , len ] : v[ aux.where ] ) {
            if ( aux.lst == 0 ) {
                if ( dist[ to ][ len ] > aux.cost ) {
                    dist[ to ][ len ] = aux.cost ;
                    q.push ( tuhla ( to , len , aux.cost ) ) ;
                }
            }
            else {
                if ( dist[ to ][ 0 ] > aux.cost + ( aux.lst + len ) * ( aux.lst + len ) ) {
                    dist[ to ][ 0 ] = aux.cost + ( aux.lst + len ) * ( aux.lst + len ) ;
                    q.push ( tuhla ( to , 0 , dist[ to ][ 0 ] ) ) ;
                }
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( dist[ i ][ 0 ] == inf ) { dist[ i ][ 0 ] = -1 ; }
        cout << dist[ i ][ 0 ] << " " ;
    }
    cout << "\n" ;
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