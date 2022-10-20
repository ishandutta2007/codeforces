#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 607
#define MOD 998244353

int n , m ;
vector < int > v[ MAXN ] ;

int dist[ 2 ][ MAXN ] ;

long long ans[ MAXN ][ MAXN ] ;

vector < int > exact[ 2 * MAXN ] ;
vector < int > diff ;

void bfs ( int ori , int id ) {
    queue < int > q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dist[ id ][ i ] = MAXN ;
    }
    dist[ id ][ ori ] = 0 ;
    q.push ( ori ) ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        for ( auto y : v[ x ] ) {
            if ( dist[ id ][ y ] == MAXN ) {
                dist[ id ][ y ] = dist[ id ][ x ] + 1 ;
                q.push ( y ) ;
            }
        }
    }
}

int calc ( int x , int y ) {
    bfs ( x , 0 ) ;
    bfs ( y , 1 ) ;
    for ( int i = 0 ; i <= 2 * m ; ++ i ) {
        exact[ i ].clear ( ) ;
    }
    diff.clear ( ) ;
    int mxid = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( dist[ 0 ][ i ] + dist[ 1 ][ i ] == dist[ 0 ][ y ] ) {
            exact[ dist[ 0 ][ i ] ].push_back ( i ) ;
        }
        else {
            diff.push_back ( i ) ;
            mxid = max ( mxid , min ( dist[ 0 ][ i ] , dist[ 1 ][ i ] ) ) ;
        }
    }
    long long ans = 1 ;
    for ( int i = 1 ; i <= dist[ 0 ][ y ] ; ++ i ) {
        if ( exact[ i ].size ( ) > 1 ) { return 0 ; }
        for ( auto p : exact[ i ] ) {
            int coef = 0 ;
            for ( auto w : v[ p ] ) {
                if ( dist[ 0 ][ w ] + dist[ 1 ][ w ] == dist[ 0 ][ y ] && dist[ 0 ][ w ] == dist[ 0 ][ p ] - 1 ) {
                    ++ coef ;
                }
            }
            ans = ( ans * coef ) % MOD ;
            if ( ans == 0 ) { return ans ; }
        }
    }
    for ( auto p : diff ) {
        int coef = 0 ;
        for ( auto w : v[ p ] ) {
            if ( dist[ 0 ][ w ] == dist[ 0 ][ p ] - 1 && dist[ 1 ][ w ] == dist[ 1 ][ p ] - 1 ) {
                ++ coef ;
            }
        }
        ans = ( ans * coef ) % MOD ;
        if ( ans == 0 ) { return ans ; }
    }
    return ans ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = i ; j <= n ; ++ j ) {
            ans[ i ][ j ] = calc ( i , j ) ;
            ans[ j ][ i ] = ans[ i ][ j ] ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            cout << ans[ i ][ j ] << " " ;
        }
        cout << "\n" ;
    }
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