#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int n , m ;
int a[ 1007 ][ 1007 ] ;
long long dpf[ 1007 ][ 1007 ] ;
long long dps[ 1007 ][ 1007 ] ;

long long dp3[ 1007 ][ 1007 ] ;
long long dp4[ 1007 ][ 1007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    int i , j ;
    scanf ( "%d%d" , &n , &m ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
}


void solve ( )  {
    int i , j ;
    long long mx = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            mx = max ( dpf[ i - 1 ][ j ] , dpf[ i ][ j - 1 ] ) ;
            dpf[ i ][ j ] = mx + a[ i ][ j ] ;
        }
    }

    for ( i = n ; i >= 1 ; i -- ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            mx = max ( dps[ i + 1 ][ j ] , dps[ i ][ j - 1 ] ) ;
            dps[ i ][ j ] = mx + a[ i ][ j ] ;
        }
    }


    for ( i = 1 ; i <= n  ; i ++ ) {
        for ( j = m ; j >= 1  ; j -- ) {
            mx = max ( dp3[ i - 1 ][ j ] , dp3[ i ][ j + 1 ] ) ;
            dp3[ i ][ j ] = mx + a[ i ][ j ] ;
        }
    }

    for ( i = n ; i >= 1  ; i -- ) {
        for ( j = m ; j >= 1  ; j -- ) {
            mx = max ( dp4[ i + 1 ][ j ] , dp4[ i ][ j + 1 ] ) ;
            dp4[ i ][ j ] = mx + a[ i ][ j ] ;
        }
    }
    long long ans = 0 ;
    long long cur = 0 ;
    long long best = 0 ;
    for ( i = 2 ; i < n ; i ++ ) {
        for ( j = 2 ; j < m ; j ++ ) {
            best = 0 ;
            cur = dpf[ i ][ j - 1 ] + dps[ i + 1 ][ j ] ;
            cur += dp3[ i - 1 ][ j ] + dp4[ i ][ j + 1 ] ;
            if ( best < cur ) best = cur ;

            cur = dpf[ i - 1 ][ j ] + dps[ i  ][ j - 1 ] ;
            cur += dp3[ i ][ j + 1 ] + dp4[ i + 1 ][ j ] ;
            if ( best < cur ) best = cur ;
            if ( ans < best ) ans = best ;
        }
    }
    printf ( "%I64d\n" , ans ) ;
}