#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 300007

int n ;
int a[ MAXN ] ;

long long x , y ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        int h = ( a[ i ] >> 1 ) ;
        if ( ( i & 1 ) != 0 ) { x += h , y += a[ i ] - h ; }
        else { x += a[ i ] - h , y += h ; }
    }
}

void solve ( ) {
    printf ( "%I64d\n" , min ( x , y ) ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}