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

#define MAXN 1000007

#define MOD1 1000000007
#define MOD2 1000003

int n , m ;
vector < string > a ;

vector < bool > vis[ MAXN ] ;
struct tuhla {
    long long x , y ;
    tuhla ( ) { x = y = 0 ; }
    tuhla ( long long _x , long long _y ) {
        x = _x ;
        y = _y ;
    }
};
vector < tuhla > ways[ MAXN ] ;
vector < tuhla > rev[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    a.resize ( n ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        ways[ i ].resize ( m ) ;
        rev[ i ].resize ( m ) ;
        vis[ i ].resize ( m ) ;
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    vis[ 0 ][ 0 ] = true ;
    ways[ 0 ][ 0 ] = tuhla ( 1 , 1 ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] =='#' ) { continue ; }
            if ( i == 0 && j == 0 ) { continue ; }
            if ( i > 0 && vis[ i - 1 ][ j ] == true ) {
                vis[ i ][ j ] = true ;
                ways[ i ][ j ].x += ways[ i - 1 ][ j ].x ;
                ways[ i ][ j ].y += ways[ i - 1 ][ j ].y ;
            }
            if ( j > 0 && vis[ i ][ j - 1 ] == true ) {
                vis[ i ][ j ] = true ;
                ways[ i ][ j ].x += ways[ i ][ j - 1 ].x ;
                ways[ i ][ j ].y += ways[ i ][ j - 1 ].y ;
            }
            while ( ways[ i ][ j ].x >= MOD1 ) {
                ways[ i ][ j ].x -= MOD1 ;
            }
            while ( ways[ i ][ j ].y >= MOD2 ) {
                ways[ i ][ j ].y -= MOD2 ;
            }
        }
    }
    if ( vis[ n - 1 ][ m - 1 ] == false ) { printf ( "0\n" ) ; return ; }

    rev[ n - 1 ][ m - 1 ] = tuhla ( 1 , 1 ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        for ( int j = m - 1 ; j >= 0 ; -- j ) {
            if ( a[ i ][ j ] =='#' ) { continue ; }
            if ( i == n - 1 && j == m - 1 ) { continue ; }
            if ( i < n - 1 ) {
                rev[ i ][ j ].x += rev[ i + 1 ][ j ].x ;
                rev[ i ][ j ].y += rev[ i + 1 ][ j ].y ;
            }
            if ( j < m - 1 ) {
                rev[ i ][ j ].x += rev[ i ][ j + 1 ].x ;
                rev[ i ][ j ].y += rev[ i ][ j + 1 ].y ;
            }
            while ( rev[ i ][ j ].x >= MOD1 ) {
                rev[ i ][ j ].x -= MOD1 ;
            }
            while ( rev[ i ][ j ].y >= MOD2 ) {
                rev[ i ][ j ].y -= MOD2 ;
            }
        }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] =='#' ) { continue ; }
            if ( i == 0 && j == 0 ) { continue ; }
            if ( i == n - 1 && j == m - 1 ) { continue ; }
            long long hh1 , hh2 ;

            hh1 = ( ways[ i ][ j ].x * rev[ i ][ j ].x ) % MOD1 ;
            hh2 = ( ways[ i ][ j ].y * rev[ i ][ j ].y ) % MOD2 ;
            if ( hh1 == ways[ n - 1 ][ m - 1 ].x && hh2 == ways[ n - 1 ][ m - 1 ].y ) {
                printf ( "1\n" ) ;
                return ;
            }
        }
    }
    printf ( "2\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}