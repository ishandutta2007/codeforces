#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007


struct edge {
    int x , y ;
    int cost ;
    edge ( ) { x = y = cost = 0 ; }
    edge ( int _x , int _y , int _cost ) {
        x = _x , y = _y , cost = _cost ;
    }
};

int n , m ;
vector < struct edge > v ;

class uf {
public :
    int comp ;
    int prv[ MAXN ] ;
    int rnk[ MAXN ] ;
    void init ( ) {
        comp = n ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            prv[ i ] = -1 ;
            rnk[ i ] = 0 ;
        }
    }
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
            -- comp ;
            if ( rnk[ k1 ] >= rnk[ k2 ] ) {
                rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
                prv[ k2 ] = k1 ;
            }
            else {
                prv[ k1 ] = k2 ;
            }
        }
    }
};

uf w ;

void input ( ) {
    cin >> n >> m ;
    v.resize ( m ) ;
    for ( int i = 0 ; i < m ; ++ i ) {
        cin >> v[ i ].x >> v[ i ].y >> v[ i ].cost ;
    }
}

edge aux[ MAXN ] ;

void solve ( ) {
    int ans = 0 ;
    int sz = v.size ( ) ;
    for ( int i = 29 ; i >= 0 ; -- i ) {
        int tp = 0 ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            if ( ( v[ j ].cost & ( 1 << i ) ) == 0 ) {
                aux[ tp ++ ] = v[ j ] ;
            }
        }
        if ( tp >= n - 1 ) { 
            w.init ( ) ;
            for ( int j = 0 ; j < tp ; ++ j ) {
                w.unite ( aux[ j ].x , aux[ j ].y ) ;
            }
            if ( w.comp == 1 ) {
                sz = tp ;
                for ( int j = 0 ; j < sz ; ++ j ) {
                    v[ j ] = aux[ j ] ;
                }
            }
            else {
                ans += ( 1 << i ) ;
            }
        }
        else {
            ans += ( 1 << i ) ;
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}