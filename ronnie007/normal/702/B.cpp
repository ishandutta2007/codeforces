#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

map < int , int > ZX ;

int mx ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        ZX[ a[ i ] ] ++ ;
        if ( mx < a[ i ] ) { mx = a[ i ] ; }
    }
}

void solve ( ) {
    int i ;
    long long u ;
    long long ans = 0 ;
    for ( u = 1 ; u <= 2 * mx ; u *= 2 ) {
        for ( i = 1 ; i <= n ; i ++ ) {
            if ( a[ i ] > u ) { continue ; }
            int h = ZX[ u - a[ i ] ] ;
            if ( u - a[ i ] == a[ i ] ) { ans += ( h - 1 ) ; }
            else { ans += h ; }
        }
    }
    ans /= 2 ;
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}