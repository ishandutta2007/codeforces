#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 1007

int n , k1 , k2 ;
long long a[ MAXN ] ;
long long b[ MAXN ] ;

long long diff[ MAXN ] ;

priority_queue < long long > pq ;

void input ( ) {
    cin >> n >> k1 >> k2 ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> b[ i ] ;
        diff[ i ] = ( a[ i ] - b[ i ] ) ;
        if ( diff[ i ] < 0 ) { diff[ i ] = -diff[ i ] ; }
        pq.push ( diff[ i ] ) ;
    }
}

void solve ( ) {
    k1 += k2 ;
    while ( k1 != 0 ) {
        int x = pq.top ( ) ;
        pq.pop ( ) ;
        k1 -- ;
        if ( x == 0 ) { pq.push ( 1 ) ; }
        else { pq.push ( x - 1 ) ; }
    }
    long long ans = 0 ;
    while ( pq.empty ( ) == false ) {
        long long aux = pq.top ( ) ;
        pq.pop ( ) ;
        ans += aux * aux ;
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