#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 300007

int n ;
string a ;

int dp[ MAXN ][ 2 ][ 2 ] ;
int en[ MAXN ][ 2 ] ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    int i , j , t ;
    int ans = 0 ;
    if ( a[ 0 ] == '0' ) {
        dp[ 0 ][ 0 ][ 0 ] = 1 ;
        dp[ 0 ][ 1 ][ 1 ] = 1 ;
    }
    else {
        dp[ 0 ][ 0 ][ 1 ] = 1 ;
        dp[ 0 ][ 1 ][ 0 ] = 1 ;
    }
    a += '#' ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < 2 ; j ++ ) {
            for ( t = 0 ; t < 2 ; t ++ ) {
                if ( j == 0 ) {
                    if ( t != ( a[ i + 1 ] - '0' ) ) {
                        dp[ i + 1 ][ j ][ t^1 ] = max ( dp[ i + 1 ][ j ][ t^1 ] , dp[ i ][ j ][ t ] + 1 ) ;
                        dp[ i + 1 ][ 1 ][ t ] = max ( dp[ i + 1 ][ 1 ][ t ] , dp[ i ][ j ][ t ] ) ;
                    }
                    else {
                        dp[ i + 1 ][ j ][ t ] = max ( dp[ i + 1 ][ j ][ t ] , dp[ i ][ j ][ t ] ) ;
                        dp[ i + 1 ][ 1 ][ t^1 ] = max ( dp[ i + 1 ][ 1 ][ t^1 ] , dp[ i ][ j ][ t ] + 1 ) ;
                    }
                }
                else {
                    if ( t == ( a[ i + 1 ] - '0' ) ) {
                        dp[ i + 1 ][ j ][ t^1 ] = max ( dp[ i + 1 ][ j ][ t^1 ] , dp[ i ][ j ][ t ] + 1 ) ;
                        dp[ i + 1 ][ j ][ t ] = max ( dp[ i + 1 ][ j ][ t ] , dp[ i ][ j ][ t ] ) ;
                    }
                    else {
                        dp[ i + 1 ][ j ][ t ] = max ( dp[ i + 1 ][ j ][ t ] , dp[ i ][ j ][ t ] ) ;
                    }
                }
            }
        }
    }
    en[ n ][ 0 ] = en[ n ][ 1 ] = 0 ;
    for ( i = n - 1 ; i >= 0 ; i -- ) {
        en[ i ][ 0 ] = en[ i + 1 ][ 0 ] ;
        en[ i ][ 1 ] = en[ i + 1 ][ 1 ] ;
        if ( a[ i ] == '0' && en[ i ][ 0 ] < en[ i + 1 ][ 1 ] + 1 ) { en[ i ][ 0 ] = en[ i + 1 ][ 1 ] + 1 ; }
        if ( a[ i ] == '1' && en[ i ][ 1 ] < en[ i + 1 ][ 0 ] + 1 ) { en[ i ][ 1 ] = en[ i + 1 ][ 0 ] + 1 ; }
    }
    for ( i = n - 1 ; i >= 0 ; i -- ) {
        if ( ans < dp[ i ][ 1 ][ 0 ] + en[ i + 1 ][ 1 ] ) {
            ans = dp[ i ][ 1 ][ 0 ] + en[ i + 1 ][ 1 ] ;
        }
        if ( ans < dp[ i ][ 1 ][ 1 ] + en[ i + 1 ][ 0 ] ) {
            ans = dp[ i ][ 1 ][ 1 ] + en[ i + 1 ][ 0 ] ;
        }
    }
    if ( ans < en[ 0 ][ 0 ] ) { ans = en[ 0 ][ 0 ] ; }
    if ( ans < en[ 0 ][ 1 ] ) { ans = en[ 0 ][ 1 ] ; }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}