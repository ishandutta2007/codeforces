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


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int j ;
        for ( j = i - 1 ; j >= 1 ; -- j ) {
            if ( ( a[ i ] % a[ j ] ) == 0 ) { break ; }
        }
        if ( j == 0 ) { ++ ans ; }
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