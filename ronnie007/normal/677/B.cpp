#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 100007

long long ans ;
int n , h , k ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &h , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int cur = 0 ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( cur + a[ i ] <= h ) {
            cur += a[ i ] ;
        }
        else {
            int lim = ( h - a[ i ] ) ;
            int diff = ( cur - lim ) ;
            ans += ( diff / k ) ;
            cur -= ( diff / k ) * k ;
            if ( ( diff % k ) != 0 ) { ans ++ ; cur -= k ; }
            if ( cur < 0 ) { cur = 0 ; }
            cur += a[ i ] ;
        }
    }
    ans += ( cur / k ) ;
    if ( ( cur % k ) != 0 ) { ans ++ ; }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}