#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std ;

#define MAXN 507
#define inf 1000000007

int n , m , k , q ;

int f[ MAXN ][ MAXN ] ;
int w[ MAXN ][ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d%d" , &n , &m , &k , &q ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            f[ i ][ j ] = inf ;
        }
    }
    for ( i = 1 ; i <= q ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        f[ x ][ y ] = z ;
    }
}

void solve ( ) {
    int i , j , t ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j + k - 1 <= m ; j ++ ) {
            for ( t = 0 ; t < k ; t ++ ) {
                w[ i ][ j ] = max ( w[ i ][ j ] , f[ i ][ j + t ] ) ;
            }
        }
    }
    int ans = inf ;
    for ( i = 1 ; i + k - 1 <= n ; i ++ ) {
        for ( j = 1 ; j + k - 1 <= m ; j ++ ) {
            int cur = 0 ;
            for ( t = 0 ; t < k ; t ++ ) {
                cur = max ( cur , w[ i + t ][ j ] ) ;
            }
            ans = min ( ans , cur ) ;
        }
    }
    if ( ans == inf ) { ans = -1 ; }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}