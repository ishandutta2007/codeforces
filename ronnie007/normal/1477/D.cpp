#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define MAXN 500007
int n , m ;
set < int > s[ MAXN ] ;

vector < int > v[ MAXN ] ;
int deg[ MAXN ] ;
bool used[ MAXN ] ;
int ans[ 2 ][ MAXN ] ;

set < int > rem ;


void dfs ( int vertex ) {
    rem.erase ( vertex ) ;
    int nw = 0 ;
    while ( 1 ) {
        auto it = rem.upper_bound ( nw ) ;
        if ( it == rem.end ( ) ) { break ; }
        nw = ( * it ) ;
        if ( s[ vertex ].find ( nw ) == s[ vertex ].end ( ) ) {
            v[ vertex ].push_back ( nw ) ;
            v[ nw ].push_back ( vertex ) ;
            dfs ( nw ) ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        s[ x ].insert ( y ) ;
        s[ y ].insert ( x ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        rem.insert ( i ) ;
    }
}

void solve ( ) {
    while ( rem.empty ( ) == false ) {
        int aux = * ( rem.begin ( ) ) ;
        dfs ( aux ) ;
    }
    queue < int > q ;
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        deg[ i ] = v[ i ].size ( ) ;
        if ( deg[ i ] == 1 ) { q.push ( i ) ; }
        if ( deg[ i ] == 0 ) {
            ans[ 0 ][ i ] = ans[ 1 ][ i ] = ++ cnt ;
        }
    }
    auto kill = [ & ] ( int x ) {
        used[ x ] = true ;
        for ( auto y : v[ x ] ) {
            -- deg[ y ] ;
            if ( deg[ y ] == 1 ) { q.push ( y ) ; }
        }
    };
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        if ( used[ x ] == true ) { continue ; }
        int cen = -1 ;
        for ( auto y : v[ x ] ) {
            if ( used[ y ] == false ) {
                cen = y ; break ;
            }
        }
        vector < int > aux ;
        for ( auto y : v[ cen ] ) {
            if ( deg[ y ] == 1 && used[ y ] == false ) {
                aux.push_back ( y ) ;
            }
        }
        int val1 = cnt + 1 ;
        int val2 = cnt ;
        for ( auto y : aux ) {
            ans[ 0 ][ y ] = ++ val1 ;
            ans[ 1 ][ y ] = ++ val2 ; 
        }
        ans[ 0 ][ cen ] = cnt + 1 ;
        ans[ 1 ][ cen ] = ++ val2 ;
        cnt = val2 ;
        
        kill ( cen ) ;
        for ( auto y : aux ) { kill ( y ) ; }
    }

    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            printf ( "%d " , ans[ i ][ j ] ) ;
        }
        printf ( "\n" ) ;
    }

    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = false ;
        s[ i ].clear ( ) ;
        v[ i ].clear ( ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    scanf ( "%d" , &t ) ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}