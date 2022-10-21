#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 107

int n , k ;
string a[ MAXN ] ;
int aux[ MAXN ] ;

struct tuhla {
    int x , y ;
    int val ;
    tuhla ( ) { x = y = val = 0 ; }
    tuhla ( int _x , int _y , int _val ) {
        x = _x ;
        y = _y ;
        val = _val ;
    }
};

vector < tuhla > v ;
bool cmp ( tuhla p1 , tuhla p2 ) {
    return ( p1.val < p2.val ) ;
}

void input ( ) {
    cin >> n >> k ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int i , j ;
    int sz = a[ 0 ].size ( ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < sz ; j ++ ) {
            aux[ j ] = 0 ;
            if ( a[ i ][ j ] != '.' ) { aux[ j ] = 100000 ; }
        }
        for ( j = 0 ; j < sz - 1 ; j ++ ) {
            if ( a[ i ][ j + 1 ] == 'S' ) { aux[ j ] ++ ; }
        }
        for ( j = 1 ; j < sz ; j ++ ) {
            if ( a[ i ][ j - 1 ] == 'S' ) { aux[ j ] ++ ; }
        }
        for ( j = 0 ; j < sz ; j ++ ) {
            if ( a[ i ][ j ] == '.' ) {
                v.push_back ( tuhla ( i , j , aux[ j ] ) ) ;
            }
        }
    }
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
    for ( i = 0 ; i < k ; i ++ ) {
        a[ v[ i ].x ][ v[ i ].y ] = 'x' ;
    }
    int ans = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < sz - 1 ; j ++ ) {
            if ( a[ i ][ j ] == 'S' ) {
                if ( a[ i ][ j + 1 ] == 'S' ) { ans ++ ; }
                else if ( a[ i ][ j + 1 ] == 'P' ) { ans ++ ; }
                else if ( a[ i ][ j + 1 ] == 'x' ) { ans ++ ; }
            }
        }
        for ( j = 1 ; j < sz ; j ++ ) {
            if ( a[ i ][ j ] == 'S' ) {
                if ( a[ i ][ j - 1 ] == 'S' ) { ans ++ ; }
                else if ( a[ i ][ j - 1 ] == 'P' ) { ans ++ ; }
                else if ( a[ i ][ j - 1 ] == 'x' ) { ans ++ ; }
            }
        }
    }
    cout << ans << "\n" ;
    for ( i = 0 ; i < n ; i ++ ) {
        cout << a[ i ] << "\n" ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}