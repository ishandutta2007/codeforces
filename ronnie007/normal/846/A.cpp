#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j ;
    int ans = 0 ;
    int cur = 0 ;
    int br = 0 ;
    for ( i = 0 ; i <= n ; i ++ ) {
        cur = 0 ;
        br = i ;
        for ( j = 1 ; j <= n ; j ++ ) {
            if ( br != 0 ) {
                if ( a[ j ] == 0 ) { br -- ; cur ++ ; }
            }
            else {
                if ( a[ j ] == 1 ) { cur ++ ; }
            }
        }
        if ( ans < cur ) { ans = cur ; }
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