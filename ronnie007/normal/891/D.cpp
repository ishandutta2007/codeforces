#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 500007

int n ;
vector < int > v[ MAXN ] ;


struct node {
    int dp[ 2 ][ 2 ] ;
    node ( ) {
        for ( int i = 0 ; i < 2 ; ++ i ) {
            for ( int j = 0 ; j < 2 ; ++ j ) {
                dp[ i ][ j ] = 0 ;
            }
        }
    }
    node ( int cnt ) {
        for ( int i = 0 ; i < 2 ; ++ i ) {
            for ( int j = 0 ; j < 2 ; ++ j ) {
                dp[ i ][ j ] = 0 ;
            }
        }
        if ( cnt == 1 ) {
            dp[ 1 ][ 0 ] = dp[ 0 ][ 1 ] = 1 ;
        }
        else {
            dp[ 0 ][ 0 ] = 1 ;
        }
    }
};

node consume ( node x , node y ) {
    node ret = node ( ) ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                for ( int z = 0 ; z < 2 ; ++ z ) {
                    int unused = j + z ;
                    if ( unused > 1 ) { continue ; }
                    if ( i == 0 && t == 1 ) { continue ; }
                    int nw = i ;
                    if ( i == 1 && t == 1 ) { nw = 0 ; }
                    ret.dp[ nw ][ unused ] += x.dp[ i ][ j ] * y.dp[ t ][ z ] ;
                }
            }
        }
    }
    return ret ;
}

node unite ( node x , node y ) {
    node ret = node ( ) ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                for ( int z = 0 ; z < 2 ; ++ z ) {
                    int unused = j + z ;
                    if ( unused > 1 ) { continue ; }
                    int waiting = i + t ;
                    if ( waiting > 1 ) { continue ; }
                    ret.dp[ waiting ][ unused ] += x.dp[ i ][ j ] * y.dp[ t ][ z ] ;
                }
            }
        }
    }
    return ret ;
}

node down[ MAXN ] , up[ MAXN ] ;
int subtree[ MAXN ] ;

node pref[ MAXN ] , suff[ MAXN ] ;

void dfs_down ( int vertex , int prv ) {
    down[ vertex ] = node ( 1 ) ;
    subtree[ vertex ] = 1 ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dfs_down ( x , vertex ) ;
        subtree[ vertex ] += subtree[ x ] ;
        down[ vertex ] = consume ( down[ vertex ] , down[ x ] ) ;
    }
}

void dfs_up ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    pref[ 0 ] = node ( 0 ) ;
    suff[ sz + 1 ] = node ( 0 ) ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        if ( v[ vertex ][ i - 1 ] == prv ) {
            pref[ i ] = pref[ i - 1 ] ;
        }
        else {
            pref[ i ] = unite ( pref[ i - 1 ] , down[ v[ vertex ][ i - 1 ] ] ) ;
        }
    }
    for ( int i = sz ; i >= 1 ; -- i ) {
        if ( v[ vertex ][ i - 1 ] == prv ) {
            suff[ i ] = suff[ i + 1 ] ;
        }
        else {
            suff[ i ] = unite ( suff[ i + 1 ] , down[ v[ vertex ][ i - 1 ] ] ) ;
        }
    }
    for ( int i = 1 ; i <= sz ; ++ i ) {
        if ( v[ vertex ][ i - 1 ] == prv ) { continue ; }

        node aux = node ( 1 ) ;
        aux = consume ( aux , up[ vertex ] ) ;
        aux = consume ( aux , pref[ i - 1 ] ) ;
        aux = consume ( aux , suff[ i + 1 ] ) ;

        up[ v[ vertex ][ i - 1 ] ] = aux ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        dfs_up ( v[ vertex ][ i ] , vertex ) ;
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ; cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs_down ( 1 , -1 ) ;
    up[ 1 ] = node ( 0 ) ;
    dfs_up ( 1 , -1 ) ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += 1LL * down[ i ].dp[ 0 ][ 1 ] * up[ i ].dp[ 0 ][ 1 ] ;
        if ( down[ i ].dp[ 0 ][ 0 ] > 0 && up[ i ].dp[ 0 ][ 0 ] > 0 ) {
            ans += 1LL * subtree[ i ] * ( n - subtree[ i ] ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}