#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 10007

int n , k ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    int cur = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cur += a[ i ] ;
        k -= min ( cur , 8 ) ;
        if ( cur < 8 ) { cur = 0 ; }
        else { cur -= 8 ; }
        if ( k <= 0 ) { printf ( "%d\n" , i ) ; return ; }
    }
    printf ( "-1\n" ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}