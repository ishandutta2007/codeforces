#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 5007

int n ;
int a[ MAXN ] ;

int br[ MAXN ] ;

int ans[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j ;
    int mx = 0 ;
    int id = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        mx = id = 0 ;
        for ( j = 1 ; j <= n ; j ++ ) {
            br[ j ] = 0 ;
        }
        for ( j = i ; j <= n ; j ++ ) {
            br[ a[ j ] ] ++ ;
            if ( mx < br[ a[ j ] ] ) { mx = br[ a[ j ] ] ; id = a[ j ] ; }
            if ( mx == br[ a[ j ] ] ) {
                if ( id > a[ j ] ) {
                    id = a[ j ] ;
                }
            }
            ans[ id ] ++ ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}