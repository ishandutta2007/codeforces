#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n , m ;
set < int > s[ MAXN ] ;
pair < int , int > edges[ MAXN ] ;

set < int > v[ MAXN ] ;

long long BASE[ 2 ] = { 3892 , 199997 } ;
long long MOD[ 2 ] = { 1000000007 , 998244353 } ;

struct hsh {
    long long h[ 2 ] ;
    hsh ( ) { h[ 0 ] = h[ 1 ] = 0 ; }
    void advance ( long long x ) {
        for ( int i = 0 ; i < 2 ; ++ i ) {
            h[ i ] = ( h[ i ] * BASE[ i ] + x ) % MOD[ i ] ;
        }
    }
    bool operator < ( hsh other ) const {
        if ( h[ 0 ] != other.h[ 0 ] ) { return h[ 0 ] < other.h[ 0 ] ; }
        return h[ 1 ] < other.h[ 1 ] ;
    }
};

pair < hsh , int > srt[ MAXN ] ;

int prv[ MAXN ] ;
int rnk[ MAXN ] ;


int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    prv[ x ] = find ( prv[ x ] ) ;
    return prv[ x ] ;
}

void unite ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            prv[ k2 ] = k1 ;
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
    }
}

bool eq ( set < int > &p1 , set < int > &p2 ) {
    for ( auto x : p1 ) {
        if ( p2.find ( x ) == p2.end ( ) ) { return false ; }
    }
    for ( auto x : p2 ) {
        if ( p1.find ( x ) == p1.end ( ) ) { return false ; }
    }
    return true ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d" , &edges[ i ].first , &edges[ i ].second ) ;
        s[ edges[ i ].first ].insert ( edges[ i ].second ) ;
        s[ edges[ i ].second ].insert ( edges[ i ].first ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        s[ i ].insert ( i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        srt[ i ] = { hsh ( ) , i } ;
        for ( auto x : s[ i ] ) {
            srt[ i ].first.advance ( x ) ;
        }
    }
    sort ( srt + 1 , srt + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( srt[ i - 1 ].first.h[ 0 ] == srt[ i ].first.h[ 0 ] ) {
            if ( srt[ i - 1 ].first.h[ 1 ] == srt[ i ].first.h[ 1 ] ) {
                unite ( srt[ i - 1 ].second , srt[ i ].second ) ;
            }
        }
    }
}

int tp = 1 ;
int col[ MAXN ] ;

void dfs ( int x ) {
    col[ x ] = ++ tp ;
    for ( auto z : v[ x ] ) {
        if ( col[ z ] > 0 ) { continue ; }
        dfs ( z ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= m ; ++ i ) {
        int k1 = find ( edges[ i ].first ) ;
        int k2 = find ( edges[ i ].second ) ;
        if ( k1 != k2 ) {
            v[ k1 ].insert ( k2 ) ;
            v[ k2 ].insert ( k1 ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( v[ i ].size ( ) > 2 ) {
            printf ( "NO\n" ) ;
            return ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( col[ i ] > 0 ) { continue ; }
        if ( find ( i ) != i ) { continue ; }
        if ( v[ i ].size ( ) == 1 ) {
            dfs ( i ) ;
            tp += 2 ;
        }
        else if ( v[ i ].size ( ) == 0 ) {
            col[ i ] = tp ;
            tp += 2 ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( col[ find ( i ) ] == 0 ) {
            printf ( "NO\n" ) ;
            return ;
        }
    }
    printf ( "YES\n" ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , col[ find ( i ) ] ) ;
    }
    printf ( "\n" ) ;
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