#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 2000007

int n , m ;
vector < pair < int , int > > v[ MAXN ] ;
int deg[ MAXN ] ;
bool used[ MAXN ] ;
vector < pair < int , int > > ans ;

vector < int > path ;

bool hh[ 2 * MAXN ] ;

void dfs ( int vertex ) {
    used[ vertex ] = true ;
    while ( v[ vertex ].empty ( ) == false ) {
        pair < int , int > x = v[ vertex ].back ( ) ;
        v[ vertex ].pop_back ( ) ;
        if ( hh[ x.second ] == false ) {
            hh[ x.second ] = true ;
            dfs ( x.first ) ;
        }
    }
    path.push_back ( vertex ) ;
}


pair < int , int > get_edge ( int id , int &sz ) {
    if ( id < 0 ) { id += sz ; }
    if ( id >= sz ) { id -= sz ; }
    return make_pair ( path[ id ] , ( ( id < ( sz - 1 ) ) ? path[ id + 1 ] : path[ 0 ] ) ) ;
}
bool is_fictive ( pair < int , int > x ) {
    if ( x.first == 0 ) { return true ; }
    if ( x.second == 0 ) { return true ; }
    return false ;
}

void add_cycle ( int vertex ) {
    path.clear ( ) ;
    dfs ( vertex ) ;
    int sz = path.size ( ) ;
    int fl = 0 ;
    for ( int i = 0 ; i < sz - 1 ; ++ i ) {
        pair < int , int > w = get_edge ( i , sz ) ;
        if ( ( i % 2 ) == 0 && is_fictive ( w ) == false ) {
            fl ^= 1 ; if ( fl == 1 ) { ans.push_back ( w ) ; }
        }
        else if ( is_fictive ( w ) == false ) {
            fl = 0 ;
            pair < int , int > prv = get_edge ( i - 1 , sz ) ;
            pair < int , int > nxt = get_edge ( i + 1 , sz ) ;
            if ( is_fictive ( prv ) == true || is_fictive ( nxt ) == true ) {
                ans.push_back ( w ) ;
            }
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ; scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( make_pair ( y , i ) ) , v[ y ].push_back ( make_pair ( x , i ) ) ;
        deg[ x ] += 1 , deg[ y ] += 1 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if( ( deg[ i ] % 2 ) == 1 ) {
            v[ 0 ].push_back ( make_pair ( i , ++m ) ) ;
            v[ i ].push_back ( make_pair ( 0 , m ) ) ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) { add_cycle ( i ) ; }
    }
    int sz = ans.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d %d\n" , ans[ i ].first , ans[ i ].second ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}