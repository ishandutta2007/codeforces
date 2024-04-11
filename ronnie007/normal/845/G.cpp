#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , m ;
struct edge {
    int x , y ;
    int len ;
    bool in ;
};

edge a[ MAXN ] ;

int prv[ MAXN ] ;
int rnk[ MAXN ] ;
int dist[ MAXN ] ;

vector < pair < int , int > > v[ MAXN ] ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( edge &aux ) {
    int k1 = find ( aux.x ) ;
    int k2 = find ( aux.y ) ;
    if ( k1 != k2 ) {
        aux.in = true ;
        v[ aux.x ].push_back ( { aux.y , aux.len } ) ;
        v[ aux.y ].push_back ( { aux.x , aux.len } ) ;
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            prv[ k2 ] = k1 ;
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
    }
}

void dfs ( int vertex , int prv ) {
    for ( auto [ x , y ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dist[ x ] = dist[ vertex ] ^ y ;
        dfs ( x , vertex ) ;
    }
}


void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].y , &a[ i ].len ) ;
        UNITE ( a[ i ] ) ;
    }
}

int basis[ 32 ] ;

void add ( int x ) {
    for ( int i = 31 ; i >= 0 ; -- i ) {
        if ( ( x & ( 1 << i ) ) > 0 ) {
            if ( basis[ i ] > 0 ) {
                x ^= basis[ i ] ;
            }
            else {
                basis[ i ] = x ;
                return ;
            }
        }
    }
}

int get ( int x ) {
    for ( int i = 31 ; i >= 0 ; -- i ) {
        // if ( basis[ i ] == 0 ) { continue ; }
        if ( ( x & ( 1 << i ) ) > 0 ) {
            x ^= basis[ i ] ;
        }
    }
    return x ;
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( a[ i ].in == false ) {
            add ( dist[ a[ i ].x ] ^ dist[ a[ i ].y ] ^ a[ i ].len ) ;
        }
    }
    printf ( "%d\n" , get ( dist[ n ] ) ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}