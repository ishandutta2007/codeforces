#include<bits/stdc++.h>
using namespace std ;


// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 2007

int n , p , q ;
double a[ MAXN ] ;
double b[ MAXN ] ;
double c[ MAXN ] ;

double dp[ MAXN ][ MAXN ] ;
int cnt[ MAXN ][ MAXN ] ;

void calc ( double sr ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= p ; ++ j ) {
            dp[ i ][ j ] = -1e10 ;
            cnt[ i ][ j ] = 0 ;
        }
    }
    dp[ 0 ][ 0 ] = 0.0 ;
    cnt[ 0 ][ 0 ] = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j <= p ; ++ j ) {
            if ( j > i ) { break ; }
            if ( dp[ i + 1 ][ j ] < dp[ i ][ j ] ) {
                dp[ i + 1 ][ j ] = dp[ i ][ j ] ;
                cnt[ i + 1 ][ j ] = cnt[ i ][ j ] ;
            }
            if ( j < p && dp[ i + 1 ][ j + 1 ] < dp[ i ][ j ] + a[ i + 1 ] ) {
                dp[ i + 1 ][ j + 1 ] = dp[ i ][ j ] + a[ i + 1 ] ;
                cnt[ i + 1 ][ j + 1 ] = cnt[ i ][ j ] ;
            }
            if ( dp[ i + 1 ][ j ] < dp[ i ][ j ] + b[ i + 1 ] + sr ) {
                dp[ i + 1 ][ j ] = dp[ i ][ j ] + b[ i + 1 ] + sr ;
                cnt[ i + 1 ][ j ] = cnt[ i ][ j ] + 1 ; 
            }
            if ( j < p && dp[ i + 1 ][ j + 1 ] < dp[ i ][ j ] + c[ i + 1 ] + sr ) {
                dp[ i + 1 ][ j + 1 ] = dp[ i ][ j ] + c[ i + 1 ] + sr ;
                cnt[ i + 1 ][ j + 1 ] = cnt[ i ][ j ] + 1 ;
            }
        }
    }
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &p , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%lf" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%lf" , &b[ i ] ) ;
        c[ i ] = 1.0 - ( 1.0 - a[ i ] ) * ( 1.0 - b[ i ] ) ;
    }
}

void solve ( ) {
    double l , r , mid ;
    l = -1e5 ; r = 1e5 ;
    for ( int i = 1 ; i <= 50 ; ++ i ) {
        mid = ( l + r ) / 2 ;
        calc ( mid ) ;
        if ( cnt[ n ][ p ] < q ) { l = mid ; }
        else { r = mid ; }
    }
    printf ( "%.15lf\n" , dp[ n ][ p ] - q * ( ( l + r ) / 2.0 ) ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}