#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
using namespace std ;

#define MAXN 307

int n , m , p ;
int a[ MAXN ][ MAXN ] ;

int dp[ MAXN ][ MAXN ] ;

vector < pair < int , int > > v[ MAXN * MAXN ] ;

vector < int > col[ MAXN ] ;

int pos[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &p ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
            v[ a[ i ][ j ] ].push_back ( make_pair ( i , j ) ) ;
        }
    }
    for ( i = 1 ; i <= p ; i ++ ) {
        sort ( v[ i ].begin ( ) , v[ i ].end ( ) ) ;
    }
}

void solve ( ) {
    int i , j , t ;
    int ans = -1 ;
    for ( i = 1 ; i <= p ; i ++ ) {
        int sz = v[ i ].size ( ) ;
        if ( i == 1 ) {
            for ( j = 0 ; j < sz ; j ++ ) {
                dp[ v[ i ][ j ].first ][ v[ i ][ j ].second ] = ( v[ i ][ j ].first + v[ i ][ j ].second - 2 ) ;
            }
        }
        else {
            for ( j = 1 ; j <= m ; j ++ ) {
                pos[ j ] = 0 ;
            }
            for ( j = 0 ; j < sz ; j ++ ) {
                for ( t = 1 ; t <= m ; t ++ ) {
                    if ( pos[ t ] >= col[ t ].size ( ) ) { continue ; }
                    while ( pos[ t ] + 1 < col[ t ].size ( ) ) {
                        if ( col[ t ][ pos[ t ] + 1 ] <= v[ i ][ j ].first ) { pos[ t ] ++ ; }
                        else { break ; }
                    }
                    int cur = dp[ col[ t ][ pos[ t ] ] ][ t ] + ( abs ( v[ i ][ j ].first - col[ t ][ pos[ t ] ] ) + abs ( v[ i ][ j ].second - t ) ) ;
                    if ( dp[ v[ i ][ j ].first ][ v[ i ][ j ].second ] == 0 || dp[ v[ i ][ j ].first ][ v[ i ][ j ].second ] > cur ) {
                        dp[ v[ i ][ j ].first ][ v[ i ][ j ].second ] = cur ;
                    }
                }
            }
            for ( j = 1 ; j <= m ; j ++ ) {
                pos[ j ] = col[ j ].size ( ) - 1 ;
            }
            for ( j = sz - 1 ; j >= 0 ; j -- ) {
                for ( t = 1 ; t <= m ; t ++ ) {
                    if ( pos[ t ] < 0 ) { continue ; }
                    while ( pos[ t ] - 1 >= 0 ) {
                        if ( col[ t ][ pos[ t ] - 1 ] >= v[ i ][ j ].first ) { pos[ t ] -- ; }
                        else { break ; }
                    }
                    int cur = dp[ col[ t ][ pos[ t ] ] ][ t ] + ( abs ( v[ i ][ j ].first - col[ t ][ pos[ t ] ] ) + abs ( v[ i ][ j ].second - t ) ) ;
                    if ( dp[ v[ i ][ j ].first ][ v[ i ][ j ].second ] == 0 || dp[ v[ i ][ j ].first ][ v[ i ][ j ].second ] > cur ) {
                        dp[ v[ i ][ j ].first ][ v[ i ][ j ].second ] = cur ;
                    }
                }
            }
        }
        for ( j = 1 ; j <= m ; j ++ ) {
            col[ j ].clear ( ) ;
        }
        for ( j = 0 ; j < sz ; j ++ ) {
            col[ v[ i ][ j ].second ].push_back ( v[ i ][ j ].first ) ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            if ( a[ i ][ j ] != p ) { continue ; }
            if ( ans == -1 || ans > dp[ i ][ j ] ) {
                ans = dp[ i ][ j ] ;
            }
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ///ios::sync_with_stdio ( false ) ;
    ///cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}