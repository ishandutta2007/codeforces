#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n ;
long long f1 , f2 , f3 , d ;
long long a[ MAXN ] ;

long long dp[ MAXN ][ 2 ] ;


long long kill ( long long x ) {
    return x * f1 + f3 ;
}

long long half ( long long x ) {
    long long ret = x * f1 + f1 + f1 ;
    ret = min ( ret , f2 + f1 ) ;
    return ret ;
}

void input ( ) {
    cin >> n >> f1 >> f2 >> f3 >> d ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            dp[ i ][ j ] = -1 ;
        }
    }
    dp[ 0 ][ 0 ] = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        long long x = kill ( a[ i + 1 ] ) ;
        long long y = half ( a[ i + 1 ] ) ;
        for ( int j = 0 ; j < 2 ; ++ j ) {
            if ( dp[ i ][ j ] == -1 ) { continue ; }
            long long add = j * ( 2 * d ) ;
            if ( dp[ i + 1 ][ 0 ] < 0 ) {
                dp[ i + 1 ][ 0 ] = dp[ i ][ j ] + add + x + d * ( i > 0 ) ;
            }
            dp[ i + 1 ][ 0 ] = min ( dp[ i + 1 ][ 0 ] , dp[ i ][ j ] + add + x + d * ( i > 0 ) ) ;

            if ( dp[ i + 1 ][ 1 ] < 0 ) {
                dp[ i + 1 ][ 1 ] = dp[ i ][ j ] + add + y + d * ( i > 0 ) ;
            }
            dp[ i + 1 ][ 1 ] = min ( dp[ i + 1 ][ 1 ] , dp[ i ][ j ] + add + y + d * ( i > 0 ) ) ;

            if ( j == 1 ) {
                dp[ i + 1 ][ 0 ] = min ( dp[ i + 1 ][ 0 ] , dp[ i ][ j ] + add + y + d * ( i > 0 ) ) ;
            }
        }
    }
    long long ans = dp[ n - 1 ][ 1 ] + kill ( a[ n ] ) + 2 * d ;
    ans = min ( ans , dp[ n ][ 0 ] ) ;
    ans = min ( ans , dp[ n ][ 1 ] + 2 * d ) ;
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}