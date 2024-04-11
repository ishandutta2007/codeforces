#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 57

int n , m ;
string a[ MAXN ] ;

string s ;

int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;

int pos[ 7 ] ;
int ans = 0 ;
int stx , sty ;
int enx , eny ;

void check ( ) {
    int i ;
    int sz = s.size ( ) ;
    int x , y ;
    x = stx ;
    y = sty ;
    for ( i = 0 ; i < sz ; i ++ ) {
        int val = ( s[ i ] - '0' ) ;
        val ++ ;
        val = pos[ val ] ;
        val -- ;
        int nx = x + dx[ val ] ;
        int ny = y + dy[ val ] ;
        if ( nx < 0 || nx >= n ) { return ; }
        if ( ny < 0 || ny >= m ) { return ; }
        if ( a[ nx ][ ny ] == '#' ) { return ; }
        x = nx ;
        y = ny ;
        if ( a[ x ][ y ] == 'E' ) { ans ++ ; return ; }
    }
}

void input ( ) {
    cin >> n >> m ;
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a[ i ] ;
        for ( j = 0 ; j < m ; j ++ ) {
            if ( a[ i ][ j ] == 'S' ) {
                stx = i ;
                sty = j ;
            }
            if ( a[ i ][ j ] == 'E' ) {
                enx = i ;
                eny = j ;
            }
        }
    }
    cin >> s ;
    for ( i = 1 ; i <= 4 ; i ++ ) {
        pos[ i ] = i ;
    }
}

void solve ( ) {
    check ( ) ;
    while ( next_permutation ( pos + 1 , pos + 4 + 1 ) ) {
        check ( ) ;
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