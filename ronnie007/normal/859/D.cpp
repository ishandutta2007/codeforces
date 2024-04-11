#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std ;

#define MAXN 72

int id ;
int n ;
int a[ MAXN ][ MAXN ] ;
double dp[ MAXN ][ MAXN ][ MAXN ] ;
double p[ MAXN ][ MAXN ][ MAXN ] ;

int pw[ MAXN ] ;

void dfs ( int st , int en , int lvl ) {
    if ( st == en ) { p[ st ][ st ][ st ] = 1.000000000 ; return ; }
    int mid = ( st + en ) / 2 ;
    dfs ( st , mid , lvl - 1 ) ;
    dfs ( mid + 1 , en , lvl - 1 ) ;
    int i , j ;
    for ( i = st ; i <= mid ; i ++ ) {
        double cur = 0.00000 ;
        for ( j = mid + 1 ; j <= en ; j ++ ) {
            if ( cur < dp[ mid + 1 ][ en ][ j ] ) {
                cur = dp[ mid + 1 ][ en ][ j ] ;
            }
            dp[ st ][ en ][ i ] += p[ st ][ mid ][ i ] * p[ mid + 1 ][ en ][ j ] * ((double)a[ i ][ j ] / 100 ) * pw[ lvl ] ;
            p[ st ][ en ][ i ] += p[ st ][ mid ][ i ] * p[ mid + 1 ][ en ][ j ] * ((double)a[ i ][ j ] / 100 ) ;
        }
        dp[ st ][ en ][ i ] += dp[ st ][ mid ][ i ] + cur ;
    }
    for ( i = mid + 1 ; i <= en ; i ++ ) {
        double cur = 0.0000000000 ;
        for ( j = st ; j <= mid ; j ++ ) {
            if ( cur < dp[ st ][ mid ][ j ] ) {
                cur = dp[ st ][ mid ][ j ] ;
            }
            dp[ st ][ en ][ i ] += p[ st ][ mid ][ j ] * p[ mid + 1 ][ en ][ i ] * ((double)a[ i ][ j ] / 100 ) * pw[ lvl ] ;
            p[ st ][ en ][ i ] += p[ st ][ mid ][ j ] * p[ mid + 1 ][ en ][ i ] * ((double)a[ i ][ j ] / 100 ) ;
        }
        dp[ st ][ en ][ i ] += dp[ mid + 1 ][ en ][ i ] + cur ;
    }
}

void input ( ) {
    scanf ( "%d" , &id ) ;
    n = 1 ;
    int i , j ;
    pw[ 0 ] = 1 ;
    for ( i = 1 ; i <= id ; i ++ ) {
        pw[ i ] = 2 * pw[ i - 1 ] ;
        n *= 2 ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= n ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    int i , j , t ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= n ; j ++ ) {
            for ( t = 1 ; t <= n ; t ++ ) {
                dp[ i ][ j ][ t ] = 0.0000000 ;
            }
        }
    }
    dfs ( 1 , n , id - 1 ) ;
    double mx = 0.00000 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( dp[ 1 ][ n ][ i ] > mx ) { mx = dp[ 1 ][ n ][ i ] ; }
    }
    printf ( "%.12lf\n" , mx ) ;
}

int main ( ) {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}