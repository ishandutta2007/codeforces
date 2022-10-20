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
using namespace std ;

#define MAXN 707

int n ;
int a[ MAXN ] ;

bool dp[ MAXN ][ MAXN ][ 2 ] ;

int f[ MAXN ][ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= n ; j ++ ) {
            f[ i ][ j ] = __gcd ( a[ i ] , a[ j ] ) ;
        }
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( i > 0 && f[ i - 1 ][ i ] > 1 ) {
            dp[ i ][ i ][ 0 ] = true ;
        }
        if ( i < n && f[ i ][ i + 1 ] > 1 ) {
            dp[ i ][ i ][ 1 ] = true ;
        }
    }
    int len = 1 ;
    for ( len = 1 ; len < n ; len ++ ) {
        for ( i = 1 ; i + len <= n ; i ++ ) {
            int l = i ;
            int r = i + len ;
            for ( j = l ; j <= r ; j ++ ) {
                if ( f[ j ][ l - 1 ] <= 1 ) { continue ; }
                if ( j > l && dp[ l ][ j - 1 ][ 1 ] == false ) { continue ; }
                if ( j < r && dp[ j + 1 ][ r ][ 0 ] == false ) { continue ; }
                dp[ l ][ r ][ 0 ] = true ; break ;
            }
            for ( j = l ; j <= r ; j ++ ) {
                if ( f[ j ][ r + 1 ] <= 1 ) { continue ; }
                if ( j > l && dp[ l ][ j - 1 ][ 1 ] == false ) { continue ; }
                if ( j < r && dp[ j + 1 ][ r ][ 0 ] == false ) { continue ; }
                dp[ l ][ r ][ 1 ] = true ; break ;
            }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( i > 1 && dp[ 1 ][ i - 1 ][ 1 ] == false ) { continue ; }
        if ( i < n && dp[ i + 1 ][ n ][ 0 ] == false ) { continue ; }
        printf ( "Yes\n" ) ;
        return ;
    }
    printf ( "No\n" ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}