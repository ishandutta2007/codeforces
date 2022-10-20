#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 107

int n , m ;
int a[ MAXN ] ;


void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= 20000 ; i ++ ) {
        int sm = 0 ;
        for ( j = 1 ; j <= n ; j ++ ) {
            if ( a[ j ] <= i ) {
                sm += ( i - a[ j ] ) ;
            }
        }
        if ( sm >= m ) { printf ( "%d %d\n" , max ( i , a[ n ] ) , a[ n ] + m ) ; return ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}