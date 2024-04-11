#include<bits/stdc++.h>
using namespace std ;

int n , m , x , y ;
long long k ;

long long ans[ 107 ][ 107 ] ;

long long f ( int x , int y ) {
    long long p = m * n ;
    if ( n > 2 ) { p += m * ( n - 2 ) ; }
    long long ret = ( k / p ) ;
    long long aux = k - ret * p ;
    if ( x != 1 && x != n ) { ret *= 2 ; }
    if ( aux >= m * ( x - 1 ) + y ) { ret ++ ; }
    if ( x != n ) {
        if ( aux >= m * n + ( n - x - 1 ) * m + y ) { ret ++ ; }
    }
    return ret ;
}

void input ( ) {
    cin >> n >> m >> k >> x >> y ;
}

void solve ( ) {
    int i , j ;
    long long mn = -1 ;
    long long mx = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            ans[ i ][ j ] = f ( i , j ) ;
            if ( mn == -1 ) { mn = ans[ i ][ j ] ; }
            if ( mx == -1 ) { mx = ans[ i ][ j ] ; }
            if ( mn > ans[ i ][ j ] ) { mn = ans[ i ][ j ] ; }
            if ( mx < ans[ i ][ j ] ) { mx = ans[ i ][ j ] ; }
        }
    }
    cout << mx << " " << mn << " " << ans[ x ][ y ] << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}