#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 100007

int n ;
long long x , y , z ;
long long a[ MAXN ] ;

long long l[ MAXN ] ;
long long r[ MAXN ] ;

void input ( ) {
    cin >> n >> x >> y >> z ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        long long val = a[ i ] * x ;
        if ( i == 1 ) { l[ i ] = val ; continue ; }
        l[ i ] = l[ i - 1 ] ;
        if ( l[ i ] < val ) { l[ i ] = val ; }
    }
    for ( i = n ; i >= 1 ; i -- ) {
        long long val = a[ i ] * z ;
        if ( i == n ) { r[ i ] = val ; continue ; }
        r[ i ] = r[ i + 1 ] ;
        if ( r[ i ] < val ) { r[ i ] = val ; }
    }
    long long ans ;
    for ( i = 1 ; i <= n ; i ++ ) {
        long long val = a[ i ] * y ;
        val += l[ i ] + r[ i ] ;
        if ( i == 1 ) { ans = val ; continue ; }
        if ( ans < val ) { ans = val ; }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}