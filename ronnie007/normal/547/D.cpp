#include<bits/stdc++.h>
using namespace std ;

#define MAXN 400007
#define OFFSET 200000

int n ;
vector < pair < int , int > > v[ MAXN ] ;

pair < int , int > edge_list[ MAXN ] ;

int deg[ MAXN ] ;
int f[ MAXN ] ;

set < int > odd ;
vector < int > to_add ;
bool block[ MAXN ] ;
int st[ MAXN ] ;
int ans[ MAXN ] ;

int type = 1 ;

void dfs ( int x ) {
    int sz = v[ x ].size ( ) ;
    while ( st[ x ] < sz ) {
        int y = v[ x ][ st[ x ] ].first ;
        int id = v[ x ][ st[ x ] ].second ;
        ++ st[ x ] ;
        if ( block[ id ] == true ) { continue ; }
        block[ id ] = true ;
        ans[ id ] = type ;
        type = 0 - type ;
        f[ x ] += type ; f[ y ] += type ;
        -- deg[ x ] ; -- deg[ y ] ;
        dfs ( y ) ;
        break ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        edge_list[ i ] = { x , OFFSET + y } ; 
        v[ x ].push_back ( { OFFSET + y , i } ) ;
        v[ OFFSET + y ].push_back ( { x , i } ) ;
        ++ deg[ x ] ; ++ deg[ OFFSET + y ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= 2 * OFFSET ; ++ i ) {
        if ( ( deg[ i ] % 2 ) == 1 ) {
            odd.insert ( i ) ;
        }
    }
    while ( odd.empty ( ) == false ) {
        int x = *(odd.begin ( )) ;
        odd.erase ( x ) ;
        while ( block[ v[ x ][ st[ x ] ].second ] == true ) { ++ st[ x ] ; }
        int id = st[ x ] ++ ;
        int y = v[ x ][ id ].first ;
        -- deg[ x ] ;
        -- deg[ y ] ;
        to_add.push_back ( v[ x ][ id ].second ) ;
        block[ v[ x ][ id ].second ] = true ;
        if ( edge_list[ v[ x ][ id ].second ].first != x ) {
            swap ( edge_list[ v[ x ][ id ].second ].first , edge_list[ v[ x ][ id ].second ].second ) ;
        }
        if ( ( deg[ y ] % 2 ) == 1 ) {
            odd.insert ( y ) ;
        }
        else {
            odd.erase ( y ) ;
        }
    }
    for ( int i = 1 ; i <= 2 * OFFSET ; ++ i ) {
        st[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= 2 * OFFSET ; ++ i ) {
        while ( deg[ i ] > 0 ) {
            dfs ( i ) ;
        }
    }
    int sz = to_add.size ( ) ;
    for ( int i = sz - 1 ; i >= 0 ; -- i ) {
        int id = to_add[ i ] ;
        int x = edge_list[ id ].first ;
        int y = edge_list[ id ].second ;

        if ( f[ y ] < 0 ) {
            ans[ id ] = 1 ; 
        }
        else { ans[ id ] = -1 ; }

        f[ x ] += ans[ id ] ;
        f[ y ] += ans[ id ] ;
        ++ deg[ x ] ; ++ deg[ y ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( ans[ i ] == 1 ) { printf ( "b" ) ; }
        else { printf ( "r" ) ; }
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}