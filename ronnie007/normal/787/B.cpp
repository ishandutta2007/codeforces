#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 10007

int n , m ;
int used[ MAXN ][ 2 ] ;

bool fl = false ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i , j ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int sz ;
        scanf ( "%d" , &sz ) ;
        vector < int > v ;
        v.clear ( ) ;
        bool h = false ;
        for ( j = 0 ; j < sz ; j ++ ) {
            int x ;
            scanf ( "%d" , &x ) ;
            int id = x ;
            if ( id < 0 ) { id = -id ; }
            int p ;
            if ( x < 0 ) { p = 0 ; }
            else { p = 1 ; }
            v.push_back ( x ) ;
            used[ id ][ p ] = 1 ;
            if ( used[ id ][ 0 ] == 1 && used[ id ][ 1 ] == 1 ) {
                h = true ;
            }
        }
        for ( j = 0 ; j < sz ; j ++ ) {
            int id = v[ j ] ;
            if ( id < 0 ) { id = -id ; }
            int p ;
            if ( v[ j ] < 0 ) { p = 0 ; }
            else { p = 1 ; }
            used[ id ][ p ] = 0 ;
        }
        if ( h == false ) { fl = true ; }
    }
}

void solve ( ) {
    if ( fl == true ) { printf ( "YES\n" ) ; }
    else { printf ( "NO\n" ) ; }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}