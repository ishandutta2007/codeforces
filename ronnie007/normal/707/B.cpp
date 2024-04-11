#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 100007

int n , m , k ;
struct tuhla {
    int to ;
    int len ;
    tuhla ( ) { to = len = 0 ; }
    tuhla ( int _to , int _len ) { to = _to ; len = _len ; }
};

vector < tuhla > v[ MAXN ] ;
bool used[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d"  , &n , &m , &k ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        v[ x ].push_back ( tuhla ( y , z ) ) ;
        v[ y ].push_back ( tuhla ( x , z ) ) ;
    }
    for ( i = 1 ; i <= k ; i ++ ) {
        int x ;
        scanf ( "%d" , &x ) ;
        used[ x ] = true ;
    }
}

void solve ( ) {
    int i , j ;
    int ans = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ i ] == false ) { continue ; }
        int sz = v[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            if ( used[ v[ i ][ j ].to ] == false ) {
                if ( ans == -1 ) { ans = v[ i ][ j ].len ; }
                if ( ans > v[ i ][ j ].len ) {
                    ans = v[ i ][ j ].len ;
                }
            }
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}