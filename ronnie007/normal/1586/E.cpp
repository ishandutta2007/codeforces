#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n , m ;
vector < int > v[ MAXN ] ;
int lvl[ MAXN ] ;
int lst[ MAXN ] ;
int st[ MAXN ] , en[ MAXN ] ;


int prv[ MAXN ] ;
int rnk[ MAXN ] ;
int cnt[ MAXN ] ;
pair < int , int > rem[ MAXN ] ;

int get ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = get ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void unite ( int x , int y ) {
    int k1 = get ( x ) ;
    int k2 = get ( y ) ;
    if ( k1 != k2 ) {
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            prv[ k2 ] = k1 ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
    }
}
int tp ;
void dfs ( int vertex , int prv ) {
    st[ vertex ] = ++ tp ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        lvl[ x ] = lvl[ vertex ] + 1 ;
        lst[ x ] = vertex ;
        dfs ( x , vertex ) ;
    }
    en[ vertex ] = tp ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        unite ( x , y ) ;
    }
}

void solve ( ) {
    int q ;
    cin >> q ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        rem[ i ] = { x , y } ;
        ++ cnt[ x ] , ++ cnt[ y ] ;
    }
    int hh = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        hh += ( cnt[ i ] % 2 ) ;
    }
    if ( hh > 0 ) {
        cout << "NO\n" ;
        cout << hh / 2 << "\n" ;
        return ;
    }
    cout << "YES\n" ;
    dfs ( 1 , -1 ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        int x = rem[ i ].first , y = rem[ i ].second ;
        vector < int > w1 , w2 ;
        while ( lvl[ x ] > lvl[ y ] ) {
            w1.push_back ( x ) ;
            x = lst[ x ] ;
        }
        while ( lvl[ y ] > lvl[ x ] ) {
            w2.push_back ( y ) ;
            y = lst[ y ] ;
        }
        while ( x != y ) {
            w1.push_back ( x ) ;
            w2.push_back ( y ) ;
            x = lst[ x ] , y = lst[ y ] ;
        }
        cout << w1.size ( ) + 1 + w2.size ( ) << "\n" ;
        for ( auto p : w1 ) {
            cout << p << " " ;
        }
        cout << x << " " ;
        for ( int j = w2.size ( ) - 1 ; j >= 0 ; -- j ) {
            cout << w2[ j ] << " " ;
        }
        cout << "\n" ;
    }
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