#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
int st ;

void input ( ) {
    scanf ( "%d%d" , &n , &st ) ;
}

void solve ( ) {
    int i ;
    int ans = -1 ;
    int id = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        int diff = ( st - x ) ;
        if ( diff < 0 ) { diff = 0 ; }
        int times = ( diff / y ) + ( ( ( diff % y ) != 0 ) ? 1 : 0 ) ;
        x += times * y ;
        if ( ans < 0 ) { ans = x ; id = i ; }
        if ( ans > x ) { ans = x ; id = i ; }
    }
    printf ( "%d\n" , id ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}