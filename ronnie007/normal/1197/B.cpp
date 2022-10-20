#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int st ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        if ( a[ i ] == n ) { st = i ; }
    }
}

void solve ( ) {
    int l , r ;
    l = st - 1 , r = st + 1 ;
    int val = n - 1 ;
    while ( val > 0 ) {
        if ( l > 0 && a[ l ] == val ) { -- l ; }
        else if ( r <= n && a[ r ] == val ) { ++ r ; }
        else {
            printf ( "NO\n" ) ;
            return ;
        }
        -- val ;
    }
    printf ( "YES\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}