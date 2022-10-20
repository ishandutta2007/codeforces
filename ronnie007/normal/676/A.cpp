#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;

int b[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j , t ;
    int ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = i ; j <= n ; j ++ ) {
            for ( t = 1 ; t <= n ; t ++ ) {
                b[ t ] = a[ t ] ;
            }
            swap ( b[ i ] , b[ j ] ) ;
            int u1 , u2 ;
            u1 = u2 = 0 ;
            for ( t = 1 ; t <= n ; t ++ ) {
                if ( b[ t ] == 1 ) { u1 = t ; }
                if ( b[ t ] == n ) { u2 = t ; }
            }
            int cur = ( abs ( u1 - u2 ) ) ;
            if ( ans < cur ) { ans = cur ; }
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