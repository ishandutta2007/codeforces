#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 507

int n , m ;

int a[ MAXN ][ MAXN ] ;
int b[ MAXN ][ MAXN ] ;

vector < int > v[ 3 * MAXN ] ;
vector < int > h[ 3 * MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < m ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
            v[ i + j ].push_back ( a[ i ][ j ] ) ;
        }
    }
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < m ; j ++ ) {
            scanf ( "%d" , &b[ i ][ j ] ) ;
            h[ i + j ].push_back ( b[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i < ( n + m ) ; i ++ ) {
        sort ( v[ i ].begin ( ) , v[ i ].end ( ) ) ;
        sort ( h[ i ].begin ( ) , h[ i ].end ( ) ) ;
        if ( v[ i ].size ( ) != h[ i ].size ( ) ) { printf ( "NO\n" ) ; return ; }
        int sz = v[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            if ( v[ i ][ j ] != h[ i ][ j ] ) { printf ( "NO\n" ) ; return ; }
        }
    }
    printf ( "YES\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}