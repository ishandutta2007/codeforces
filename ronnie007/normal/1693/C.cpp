#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 200007 ;
const ll inf = 1e17 ;

int n , m ;
vector < int > rv[ MAXN ] ;
int deg[ MAXN ] ;
ll dist[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int x , y , i = 1 ; i <= m ; ++ i ) {
        cin >> x >> y ;
        rv[ y ].push_back ( x ) ;
        ++ deg[ x ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        dist[ i ] = inf ;
    }
}
void solve ( ) {
    dist[ n ] = 0 ;
    priority_queue < pair < ll , int > > q ;
    q.push ( { 0 , n } ) ;
    while ( q.empty ( ) == false ) {
        auto el = q.top ( ) ; q.pop ( ) ;
        int x = el.second ;
        if ( dist[ x ] != -el.first ) { continue ; }
        for ( auto nw : rv[ x ] ) {
            -- deg[ nw ] ;
            if ( dist[ nw ] > dist[ x ] + deg[ nw ] + 1 ) {
                dist[ nw ] = dist[ x ] + deg[ nw ] + 1 ;
                q.push ( { -dist[ nw ] , nw } ) ;
            }
        }
    }
    cout << dist[ 1 ] << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}