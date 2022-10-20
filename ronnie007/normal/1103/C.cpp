#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n , k ;
vector < int > v[ MAXN ] ;
int lvl[ MAXN ] ;
int prv[ MAXN ] ;
bool leaf[ MAXN ] ;
vector < int > aux[ MAXN ] ;

void dfs ( int vertex ) {
    if ( 1LL * k * lvl[ vertex ] >= n ) {
        printf ( "PATH\n" ) ;
        printf ( "%d\n" , lvl[ vertex ] ) ;
        int x = vertex ;
        while ( x > 0 ) {
            printf ( "%d " , x ) ;
            x = prv[ x ] ; 
        }
        printf ( "\n" ) ;
        exit ( 0 ) ;
    }
    int sz = v[ vertex ].size ( ) ;
    leaf[ vertex ] = true ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( lvl[ v[ vertex ][ i ] ] > 0 ) {
            if ( lvl[ v[ vertex ][ i ] ] < lvl[ vertex ] && lvl[ v[ vertex ][ i ] ] != lvl[ vertex ] - 1 ) {
                aux[ vertex ].push_back ( v[ vertex ][ i ] ) ;
            }
            continue ;
        }
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        prv[ v[ vertex ][ i ] ] = vertex ;
        leaf[ vertex ] = false ;
        dfs ( v[ vertex ][ i ] ) ;
    }
}

void move ( int st , int en ) {
    while ( st != prv[ en ] ) {
        printf ( "%d " , st ) ;
        st = prv[ st ] ; 
    }
}

void input ( ) {
    int m ;
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    lvl[ 1 ] = 1 ;
    dfs ( 1 ) ;
    printf ( "CYCLES\n" ) ;
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( cnt == k ) { break ; }
        if ( leaf[ i ] == false ) { continue ; }
        ++ cnt ;
        int x = aux[ i ][ 0 ] ;
        int y = aux[ i ][ 1 ] ;
        if ( lvl[ x ] > lvl[ y ] ) { swap ( x , y ) ; }
        if ( ( lvl[ i ] - lvl[ x ] + 1 ) % 3 != 0 ) {
            printf ( "%d\n" , lvl[ i ] - lvl[ x ] + 1 ) ;
            move ( i , x ) ;
            printf ( "\n" ) ;
        }
        else if ( ( lvl[ i ] - lvl[ y ] + 1 ) % 3 != 0 ) {
            printf ( "%d\n" , lvl[ i ] - lvl[ y ] + 1 ) ;
            move ( i , y ) ;
            printf ( "\n" ) ;
        }
        else {
            printf ( "%d\n" , lvl[ y ] - lvl[ x ] + 2 ) ;
            move ( y , x ) ;
            printf ( "%d\n" , i ) ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}