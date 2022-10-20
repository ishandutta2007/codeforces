#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , m ;
vector < int > v[ MAXN ] ;

int f[ MAXN ] ;
vector < int > ans ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        f[ i ] = 0 ;
        v[ i ].clear ( ) ;
    }
    ans.clear ( ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( f[ i ] == 2 ) { ans.push_back ( i ) ; continue ; }
        int sz = v[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            f[ v[ i ][ j ] ] = max ( f[ v[ i ][ j ] ] , f[ i ] + 1 ) ;
        }
    }
    int sz = ans.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
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