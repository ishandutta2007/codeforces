#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
using namespace std ;

#define MAXN 200007

int n , q ;
int a[ MAXN ] ;
int fst[ MAXN ] ;
int lst[ MAXN ] ;
int tot[ MAXN ] ;
int lft[ MAXN ] ;

int lftsm = 0 ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    int curr = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        if ( fst[ a[ i ] ] == 0 ) { fst[ a[ i ] ] = i ; }
        lst[ a[ i ] ] = i ;
        ++ tot[ a[ i ] ] ;
        ++ lft[ a[ i ] ] ;
    }

}


void solve ( ) {
    int mx = 0 ;
    int ans = n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( i == fst[ a[ i ] ] ) {
            mx = max ( mx , tot[ a[ i ] ] ) ;
            lftsm += lft[ a[ i ] ] ;
        }
        -- lft[ a[ i ] ] ;
        -- lftsm ;
        if ( lftsm == 0 ) {
            ans -= mx ;
            mx = 0 ;
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