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

#define MAXN 6007

int n , m ;
char a[ MAXN ][ MAXN ] ;

int f[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        scanf ( "\n%s" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int cnt1 = 0 ;
    int cnt2 = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            cnt1 += ( a[ i ][ j ] == 'A' ) ;
            cnt2 += ( a[ i ][ j ] == 'P' ) ;
            if ( cnt1 > 0 && cnt2 > 0 ) { break ; }
        }
        if ( cnt1 > 0 && cnt2 > 0 ) { break ; }        
    }
    if ( cnt1 == 0 ) { printf ( "MORTAL\n" ) ; return ; }
    if ( cnt2 == 0 ) { printf ( "0\n" ) ; return ; }
    bool side = false ;
    int step = ( n - 1 ) ;
    if ( step == 0 ) { step = 1 ; }
    for ( int i = 0 ; i < n ; i += step ) {
        int val = 0 ;
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] == 'P' ) { ++ val ; }
        }
        if ( val == 0 ) { printf ( "1\n" ) ; return ; }
    }
    for ( int j = 0 ; j < m ; ++ j ) { f[ j ] = 0 ; }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] == 'A' ) {
                ++ f[ j ] ;
                if ( i == 0 || i == ( n - 1 ) ) { side = true ; }
                if ( j == 0 || j == ( m - 1 ) ) { side = true ; }
            }
        }
    }
    if ( f[ 0 ] == n || f[ m - 1 ] == n ) { printf ( "1\n" ) ; return ; }
    
    for ( int j = 0 ; j < m ; ++ j ) {
        if ( f[ j ] == n ) { printf ( "2\n" ) ; return ; }
    }
    if ( a[ 0 ][ 0 ] == 'A' || a[ 0 ][ m - 1 ] == 'A' || a[ n - 1 ][ 0 ] == 'A' || a[ n - 1 ][ m - 1 ] == 'A' ) {
        printf ( "2\n" ) ;
        return ;
    }
    
    for ( int i = 0 ; i < n ; ++ i ) {
        int j ;
        for ( j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] == 'P' ) { break ; }
        }
        if ( j == m ) { printf ( "2\n" ) ; return ; }
    }
    printf ( "%d\n" , ( ( side == true ) ? 3 : 4 ) ) ;
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