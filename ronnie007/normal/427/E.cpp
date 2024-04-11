#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>


int n , m ;
long long a[ 10000007 ] ;
long long dpl[ 1000007 ] ;
long long dpr[ 1000007 ] ; 


void input ( ) {
    std::cin >> n >> m ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        std::cin >> a[ i ] ; 
    }
}

void solve ( ) {
    dpl[ 0 ] = 0 ;
    dpr[ n - 1 ] = 0 ;
    int i ;
    int lst ; 
    for ( i = 1 ; i < n ; i ++ ) {
        lst = std::max ( i - m , 0 ) ;
        dpl[ i ] = dpl[ i - 1 ] + ( i / m + ( i % m != 0 ) ) * ( a[ i ] - a[ i - 1 ] ) * 2 ;
    }
    for ( i = n - 2  ; i >= 0  ; i -- ) {
        lst = std::min ( i + m , n - 1 ) ;
        dpr[ i ] = dpr [ i + 1 ] + ( ( n - 1 - i ) / m + ( ( n - 1 - i ) % m != 0 ) ) * ( a[ i + 1 ] - a[ i ] ) * 2 ;
    }
    long long ans = dpr[ 0 ] + dpl[ 0 ] ; 
    for ( i = 1 ; i < n ; i ++ ) {
        ans = std::min ( ans , dpl[ i ] + dpr[ i ] ) ;
    }
    std::cout << ans << "\n" ;
}

int main ( ) {
    std::ios::sync_with_stdio ( false ) ;
    std::cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}