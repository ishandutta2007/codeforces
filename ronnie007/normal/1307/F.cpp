#include<bits/stdc++.h>
using namespace std ;

#define MAXN 400007
#define LOG 20


int n , k , r ;
vector < int > v[ MAXN ] ;
int lvl[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;
int hh[ MAXN ] ;

int dist[ MAXN ] ;
int ori[ MAXN ] ;

int prv[ MAXN ] ;
int rnk[ MAXN ] ;

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
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            prv[ k2 ] = k1 ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
    }
}

void dfs ( int vertex , int prv ) {
    for ( int i = 1 ; i < LOG ; ++ i ) {
        LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
    }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        lvl[ x ] = lvl[ vertex ] + 1 ;
        LCA[ x ][ 0 ] = vertex ;
        dfs ( x , vertex ) ;
    }
}
int get_LCA ( int x , int y ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( lvl[ x ] - ( 1 << i ) >= lvl[ y ] ) {
            x = LCA[ x ][ i ] ;
        }
        if ( lvl[ y ] - ( 1 << i ) >= lvl[ x ] ) {
            y = LCA[ y ][ i ] ;
        }
    }
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( LCA[ x ][ i ] != LCA[ y ][ i ] ) {
            x = LCA[ x ][ i ] ;
            y = LCA[ y ][ i ] ;
        }
    }
    if ( x != y ) {
        x = LCA[ x ][ 0 ] ;
    }
    return x ;
}

int lift ( int x , int cnt ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( cnt >= ( 1 << i ) ) {
            cnt -= ( 1 << i ) ;
            x = LCA[ x ][ i ] ;
        }
    }
    return x ;
}

int advance ( int st , int en , int lca , int len ) {
    if ( lvl[ st ] - lvl[ lca ] >= len ) {
        return lift ( st , len ) ;
    }
    else { return lift ( en , ( lvl[ st ] + lvl[ en ] - 2 * lvl[ lca ] ) - len ) ; }
}

void input ( ) {
    cin >> n >> k >> r ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( i + n ) ;
        v[ i + n ].push_back ( y ) ;

        v[ y ].push_back ( i + n ) ;
        v[ i + n ].push_back ( x ) ;
    }
    for ( int i = 1 ; i <= r ; ++ i ) {
        cin >> hh[ i ] ;
    }
}



void solve ( ) {
    queue < int > q ;
    for ( int i = 1 ; i < 2 * n ; ++ i ) {
        dist[ i ] = -1 ;
    }
    for ( int i = 1 ; i <= r ; ++ i ) {
        dist[ hh[ i ] ] = 0 ;
        ori[ hh[ i ] ] = i ;
        q.push ( hh[ i ] ) ;
        prv[ i ] = -1 ;
    }
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        for ( auto y : v[ x ] ) {
            if ( dist[ y ] == -1 ) {
                if ( dist[ x ] < k ) {
                    dist[ y ] = dist[ x ] + 1 ;
                    ori[ y ] = ori[ x ] ;
                    q.push ( y ) ;
                }
            }
            else {
                unite ( ori[ x ] , ori[ y ] ) ;
            }
        }
    }
    dfs ( 1 , -1 ) ;
    int cnt ;
    cin >> cnt ;
    while ( cnt -- ) {
        int x , y ;
        cin >> x >> y ;
        int aux = get_LCA ( x , y ) ;
        if ( lvl[ x ] + lvl[ y ] - 2 * lvl[ aux ] <= 2 * k ) {
            cout << "YES\n" ;
            continue ;
        }
        int w1 = advance ( x , y , aux , k ) ;
        int w2 = advance ( y , x , aux , k ) ;
        if ( ori[ w1 ] > 0 && ori[ w2 ] > 0 ) {
            if ( get ( ori[ w1 ] ) == get ( ori[ w2 ] ) ) {
                cout << "YES\n" ;
                continue ;
            }
        }
        cout << "NO\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}