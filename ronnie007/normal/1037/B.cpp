#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;


#define MAXN 200007

int n , aux ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &aux ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int i ;
    int sr = ( n / 2 ) + 1 ;
    long long ans = 0 ;
    for ( i = 1 ; i < sr ; i ++ ) {
        if ( a[ i ] > aux ) {
            ans += ( a[ i ] - aux ) ;
        }
    }
    ans += abs ( aux - a[ sr ] ) ;
    for ( i = sr + 1 ; i <= n ; i ++ ) {
        if ( a[ i ] < aux ) {
            ans += ( aux - a[ i ] ) ;
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}