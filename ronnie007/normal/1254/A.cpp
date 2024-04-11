#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 107

int n , m , k ;
string a[ MAXN ] ;

int high_val , high_cnt ;

int ans[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n >> m >> k ;
    for ( int i = 0 ; i < n ; ++ i ) { cin >> a[ i ] ; }
    int total = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            total += ( a[ i ][ j ] == 'R' ) ;
        }
    }
    high_val = ( total / k ) + 1 , high_cnt = ( total % k ) ;
}

void solve ( ) {
    int curr = 0 ;
    int x , y ;
    x = y = 0 ;
    int id = 0 ;
    int dy = 1 ;
    for ( int steps = 0 ; steps < n * m ; ++ steps ) {
        curr += ( a[ x ][ y ] == 'R' ) ;
        ans[ x ][ y ] = id ;
        if ( curr == high_val && high_cnt > 0 ) {
            -- high_cnt , curr = 0 , ++ id ;
        }
        else if ( curr == high_val - 1 && high_cnt == 0 && id < k - 1 ) {
                curr = 0 , ++ id ;
        }
        y += dy ;
        if ( y == m ) { ++ x , dy = - dy , -- y ; }
        if ( y == -1 ) { ++ x , dy = - dy , ++ y ; }
    }
    for ( int i = 0 ; i < n ; ++ i , cout << "\n" ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( ans[ i ][ j ] < 10 ) { cout << char ( '0' + ans[ i ][ j ] ) ; }
            else if ( ans[ i ][ j ] < 36 ) { cout << char ( 'a' + ( ans[ i ][ j ] - 10 ) ) ; }
            else { cout << char ( 'A' + ( ans[ i ][ j ] - 36 ) ) ; }
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}