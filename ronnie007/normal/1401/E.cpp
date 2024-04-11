#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 1e6 + 7 ;

vector < pair < int , int > > v[ MAXN ] ;
vector < pair < int , int > > ask[ MAXN ] ;

int tr[ MAXN ] ;
void upd ( int pos , int x ) {
    for ( int wh = pos ; wh < MAXN ; wh += ( wh & -wh ) ) {
        tr[ wh ] += x ;
    }
}

int query ( int pos ) {
    int ret = 0 ;
    for ( int wh = pos ; wh > 0 ; wh -= ( wh & -wh ) ) {
        ret += tr[ wh ] ;
    }
    return ret ;
}


void solve ( ) {
    int n , m ; cin >> n >> m ;
    ll ans = 1 ;
    for ( int i = 1 , y , l , r ; i <= n ; ++ i ) {
        cin >> y >> l >> r ;
        ask[ y ].push_back ( { l , r } ) ;
        if ( l == 0 && r == 1e6 ) { ++ ans ; }
    }
    for ( int i = 1 , x , l , r ; i <= m ; ++ i ) {
        cin >> x >> l >> r ;
        v[ l ].push_back ( { x , 1 } ) ;
        v[ r + 1 ].push_back ( { x , - 1 } ) ;
        if ( l == 0 && r == 1e6 ) { ++ ans ; }
    }
    for ( int i = 0 ; i <= 1e6 ; ++ i ) {
        for ( auto [ x , coef ] : v[ i ] ) {
            upd ( x , coef ) ;
        }
        for ( auto [ l , r ] : ask[ i ] ) {
            ans += query ( r ) - query ( l - 1 ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}