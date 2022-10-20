#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 100007 ;

int n , m ;
vector < int > v[ MAXN ] ;
ll indeg[ MAXN ] , outdeg[ MAXN ] ;


void solve ( ) {
    cin >> n >> m ;
    for ( int i = 1 , x , y ; i <= m ; ++ i ) {
        cin >> x >> y ;
        if ( x > y ) { swap ( x , y ) ; }
        v[ x ].push_back ( y ) ;
        ++ indeg[ y ] , ++ outdeg[ x ] ;
    }
    ll ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += indeg[ i ] * outdeg[ i ] ;
    }
    cout << ans << "\n" ;
    int q ; cin >> q ;
    while ( q -- ) {
        int x ; cin >> x ;
        ans -= indeg[ x ] * outdeg[ x ] ;
        for ( auto y : v[ x ] ) {
            -- outdeg[ x ] , ++ indeg[ x ] ;
            ans -= indeg[ y ] * outdeg[ y ] ;
            ++ outdeg[ y ] , -- indeg[ y ] ;
            ans += indeg[ y ] * outdeg[ y ] ;
            v[ y ].push_back ( x ) ;
        }
        v[ x ].clear ( ) ;
        cout << ans << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}