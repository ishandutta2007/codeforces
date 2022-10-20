#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 100007

int n , m ;
vector < int > v[ MAXN ] ;
int used[ MAXN ] ;
int c[ MAXN ] ;

bool mark[ MAXN ] ;

vector < int > aux ;
int cl_cnt[ 5 ] ;

void dfs ( int vertex ) {
    used[ vertex ] = 1 ;
    aux.push_back ( vertex ) ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( used[ v[ vertex ][ i ] ] == 0 ) {
            dfs ( v[ vertex ][ i ] ) ;
        }
    }
}

bool calc ( ) {
    int sz = aux.size ( ) ;
    int i = 0 ;
    for ( int cl = 1 ; cl <= 3 ; ++ cl ) {
        cl_cnt[ cl ] = 0 ;
        for ( ; i < sz ; ++ i ) {
            if ( c[ aux[ i ] ] == 0 ) { break ; }
        }
        if ( i == sz ) { return false ; }
        c[ aux[ i ] ] = cl ;
        ++ cl_cnt[ cl ] ;
        int hh = v[ aux[ i ] ].size ( ) ;
        for ( int j = 0 ; j < hh ; ++ j ) {
            mark[ v[ aux[ i ] ][ j ] ] = true ;
        }
        for ( int j = i + 1 ; j < sz ; ++ j ) {
            if ( mark[ aux[ j ] ] == false ) {
                c[ aux[ j ] ] = cl ;
                ++ cl_cnt[ cl ] ;
            }
        }
        for ( int j = 0 ; j < hh ; ++ j ) {
            mark[ v[ aux[ i ] ][ j ] ] = false ;
        }
        ++ i ;
    }
    int sm = cl_cnt[ 1 ] + cl_cnt[ 2 ] + cl_cnt[ 3 ] ;
    if ( sm != sz ) { return false ; }
    for ( i = 0 ; i < sz ; ++ i ) {
        int hh = v[ aux[ i ] ].size ( ) ;
        if ( hh != sm - cl_cnt[ c[ aux[ i ] ] ] ) { return false ; }
        for ( int j = 0 ; j < hh ; ++ j ) {
            if ( c[ aux[ i ] ] == c[ v[ aux[ i ] ][ j ] ] ) { return false ; }
        }
    }
    return true ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 0 ) {
            aux.clear ( ) ;
            dfs ( i ) ;
            bool ret = calc ( ) ;
            if ( ret == false ) { printf ( "-1\n" ) ; return ; }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , c[ i ] ) ;
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