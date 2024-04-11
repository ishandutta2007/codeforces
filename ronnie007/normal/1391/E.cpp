#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

int n , m ;
vector < int > v[ MAXN ] ;
vector < int > aux[ MAXN ] ;
int dist[ MAXN ] ;
int prv[ MAXN ] ;
vector < pair < int , int > > hh ;

void dfs ( int vertex ) {
    aux[ dist[ vertex ] ].push_back ( vertex ) ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( dist[ v[ vertex ][ i ] ] == 0 ) {
            dist[ v[ vertex ][ i ] ] = dist[ vertex ] + 1 ;
            prv[ v[ vertex ][ i ] ] = vertex ;
            dfs ( v[ vertex ][ i ] ) ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
        aux[ i ].clear ( ) ;
        dist[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dist[ 1 ] = 1 ;
    dfs ( 1 ) ;
    for ( int i = n ; 2 * i >= n ; -- i ) {
        if ( aux[ i ].size ( ) > 0 ) {
            int x = aux[ i ][ 0 ] ;
            printf ( "PATH\n" ) ;
            printf ( "%d\n" , i ) ;
            while ( x > 0 ) {
                printf ( "%d " , x ) ;
                x = prv[ x ] ;
            }
            printf ( "\n" ) ;
            return ;
        }
    }
    hh.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz = aux[ i ].size ( ) ;
        for ( int j = 0 ; j + 1 < sz ; j += 2 ) {
            hh.push_back ( { aux[ i ][ j ] , aux[ i ][ j + 1 ] } ) ;
        }
    }
    printf ( "PAIRING\n" ) ;
    int sz = hh.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d %d\n" , hh[ i ].first , hh[ i ].second ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}