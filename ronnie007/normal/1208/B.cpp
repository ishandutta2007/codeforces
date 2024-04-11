#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 2007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int tot[ MAXN ] ;
int init ;

int cnt[ MAXN ] ;
int lft ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = i ;
        for ( int j = 1 ; j < i ; ++ j ) {
            if ( b[ j ] == b[ i ] ) { a[ i ] = a[ j ] ; break ; }
        }
        ++ tot[ a[ i ] ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( tot[ i ] > 1 ) { ++ init ; }
    }
    if ( init == 0 ) { printf ( "0\n" ) ; return ; }
    int ans = n + 2 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        lft = 0 ;
        for ( int j = 1 ; j <= n ; ++ j ) { cnt[ j ] = 0 ; }
        for ( int j = i ; j <= n ; ++ j ) {
            ++ cnt[ a[ j ] ] ;
            if ( cnt[ a[ j ] ] == tot[ a[ j ] ] - 1 ) { ++ lft ; }
            if ( lft == init ) {
                if ( ans > j - i + 1 ) {
                    ans = j - i + 1 ;
                }
                break ;
            }
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}