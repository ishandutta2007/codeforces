#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , m ;
vector < pair < int , int > > v[ MAXN ] ;
long long dist[ MAXN ][ 2 ][ 2 ] ;
long long inf = 1e16 ;

struct node {
    int vertex , fl1 , fl2 ;
    node ( ) { vertex = fl1 = fl2 = 0 ; }
    node ( int _vertex , int _fl1 , int _fl2 ) {
        vertex = _vertex ;
        fl1 = _fl1 ; fl2 = _fl2 ;
    }
    bool operator < ( node other ) const {
        if ( vertex != other.vertex ) {
            return vertex < other.vertex ;
        }
        if ( fl1 != other.fl1 ) {
            return fl1 < other.fl1 ;
        }
        return fl2 < other.fl2 ;
    }
};

void dijkstra ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                dist[ i ][ j ][ t ] = inf ;
            }
        }
    }
    priority_queue < pair < long long , node > > q ;
    dist[ 1 ][ 0 ][ 0 ] = 0 ;
    q.push ( { 0 , node ( 1 , 0 , 0 ) } ) ;
    while ( q.empty ( ) == false ) {
        auto [ cost , aux ] = q.top ( ) ;
        q.pop ( ) ;
        cost = -cost ;
        if ( dist[ aux.vertex ][ aux.fl1 ][ aux.fl2 ] != cost ) { continue ; }
        int sz = v[ aux.vertex ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            int nxt = v[ aux.vertex ][ i ].first ;
            int add = v[ aux.vertex ][ i ].second ;
            if ( dist[ nxt ][ aux.fl1 ][ aux.fl2 ] > cost + add ) {
                dist[ nxt ][ aux.fl1 ][ aux.fl2 ] = cost + add ;
                q.push ( { -dist[ nxt ][ aux.fl1 ][ aux.fl2 ] , node ( nxt , aux.fl1 , aux.fl2 ) } ) ;
            }
            if ( aux.fl1 == 0 && aux.fl2 == 0 && dist[ nxt ][ 1 ][ 1 ] > cost + add ) {
                dist[ nxt ][ 1 ][ 1 ] = cost + add ;
                q.push ( { -dist[ nxt ][ 1 ][ 1 ] , node ( nxt , 1 , 1 ) } ) ;
            }
            if ( aux.fl1 == 0 && dist[ nxt ][ 1 ][ aux.fl2 ] > cost ) {
                dist[ nxt ][ 1 ][ aux.fl2 ] = cost ;
                q.push ( { -dist[ nxt ][ 1 ][ aux.fl2 ] , node ( nxt , 1 , aux.fl2 ) } ) ;
            }
            if ( aux.fl2 == 0 && dist[ nxt ][ aux.fl1 ][ 1 ] > cost + 2 * add ) {
                dist[ nxt ][ aux.fl1 ][ 1 ] = cost + 2 * add ;
                q.push ( { -dist[ nxt ][ aux.fl1 ][ 1 ] , node ( nxt , aux.fl1 , 1 ) } ) ;
            }
        }
    }
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y , len ;
        cin >> x >> y >> len ;
        v[ x ].push_back ( { y , len } ) ;
        v[ y ].push_back ( { x , len } ) ;
    }
}

void solve ( ) {
    dijkstra ( ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        cout << dist[ i ][ 1 ][ 1 ] << " " ;
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