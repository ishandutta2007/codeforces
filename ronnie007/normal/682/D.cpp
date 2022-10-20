#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
using namespace std ;

#define MAXN 1007
#define MAXK 13

int n , m , k ;
string a , b ;

int dp[ MAXN ][ MAXN ][ MAXK ][ 2 ] ;

void input ( ) {
    cin >> n >> m >> k ;
    cin >> a ;
    cin >> b ;
    a = '#' + a ;
    b = '#' + b ;
}

void solve ( ) {
    int i , j , t , z ;
    int ans = 0 ;
    for ( i = 0 ; i <= n ; i ++ ) {
        for ( j = 0 ; j <= m ; j ++ ) {
            for ( t = 0 ; t <= k ; t ++ ) {
                for ( z = 0 ; z < 2 ; z ++ ) {
                    dp[ i ][ j ][ t ][ z ] = -5 * MAXN ;
                }
            }
        }
    }
    dp[ 0 ][ 0 ][ 0 ][ 0 ] = 0 ;
    for ( i = 0 ; i <= n ; i ++ ) {
        for ( j = 0 ; j <= m ; j ++ ) {
            for ( t = 0 ; t <= k ; t ++ ) {
                for ( z = 0 ; z < 2 ; z ++ ) {
                    if ( dp[ i ][ j ][ t ][ z ] < 0 ) { continue ; }
                    if ( t == k ) {
                        if ( ans < dp[ i ][ j ][ t ][ z ] ) {
                            ans = dp[ i ][ j ][ t ][ z ] ;
                        }
                    }
                    if ( dp[ i + 1 ][ j ][ t ][ 0 ] < dp[ i ][ j ][ t ][ z ] ) {
                        dp[ i + 1 ][ j ][ t ][ 0 ] = dp[ i ][ j ][ t ][ z ] ;
                    }
                    if ( dp[ i ][ j + 1 ][ t ][ 0 ] < dp[ i ][ j ][ t ][ z ] ) {
                        dp[ i ][ j + 1 ][ t ][ 0 ] = dp[ i ][ j ][ t ][ z ] ;
                    }
                    if ( dp[ i + 1 ][ j + 1 ][ t ][ 0 ] < dp[ i ][ j ][ t ][ z ] ) {
                        dp[ i + 1 ][ j + 1 ][ t ][ 0 ] = dp[ i ][ j ][ t ][ z ] ;
                    }
                    if ( t < k ) {
                        if ( i < n && j < m ) {
                            if ( a[ i + 1 ] == b[ j + 1 ] ) {
                                if ( dp[ i + 1 ][ j + 1 ][ t + 1 ][ 1 ] < dp[ i ][ j ][ t ][ z ] + 1 ) {
                                    dp[ i + 1 ][ j + 1 ][ t + 1 ][ 1 ] = dp[ i ][ j ][ t ][ z ] + 1 ;
                                }
                            }
                        }
                    }
                    if ( z == 1 ) {
                        if ( i < n && j < m ) {
                            if ( a[ i + 1 ] == b[ j + 1 ] ) {
                                if ( dp[ i + 1 ][ j + 1 ][ t ][ 1 ] < dp[ i ][ j ][ t ][ z ] + 1 ) {
                                    dp[ i + 1 ][ j + 1 ][ t ][ 1 ] = dp[ i ][ j ][ t ][ z ] + 1 ;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}