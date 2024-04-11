#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
using namespace std ;

#define MAXN 507
#define inf 1000000007

int n , m ;
int a[ MAXN ][ MAXN ] ;

int dp[ MAXN ][ MAXN ] ;
int br[ MAXN ][ MAXN ] ;
int ans[ MAXN ][ MAXN ] ;

void input ( ) {
	cin >> n >> m ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= n ; j ++ ) {
        	dp[ i ][ j ] = inf ;
            a[ i ][ j ] = inf + 7 ;
            if ( i == j ) { dp[ i ][ j ] = 0 ; }
        }
    }
    for ( i = 1 ; i <= m ; i ++ ) {
    	int x , y , z ;
        cin >> x >> y >> z ;
        dp[ x ][ y ] = min ( dp[ x ][ y ] , z ) ;
        dp[ y ][ x ] = min ( dp[ y ][ x ] , z ) ;
        a[ x ][ y ] = min ( a[ x ][ y ] , z ) ;
        a[ y ][ x ] = min ( a[ y ][ x ] , z ) ;
    }
}

void solve ( ) {
	int i , j , t ;
    for ( t = 1 ; t <= n ; t ++ ) {
    	for ( i = 1 ; i <= n ; i ++ ) {
        	for ( j = 1 ; j <= n ; j ++ ) {
            	if ( dp[ i ][ j ] > dp[ i ][ t ] + dp[ t ][ j ] ) {
                	dp[ i ][ j ] = dp[ i ][ t ] + dp[ t ][ j ] ;
                }
            }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= n ; j ++ ) {
        	for ( t = 1 ; t <= n ; t ++ ) {
            	if ( dp[ i ][ t ] + a[ t ][ j ] == dp[ i ][ j ] ) {
                	br[ i ][ j ] ++ ;
                }
            }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= n ; j ++ ) {
        	for ( t = 1 ; t <= n ; t ++ ) {
            	if ( dp[ i ][ t ] + dp[ t ][ j ] == dp[ i ][ j ] ) {
                	ans[ i ][ j ] += br[ i ][ t ] ;
                }
            }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = i + 1 ; j <= n ; j ++ ) {
        	cout << ans[ i ][ j ] ;
            if ( i != ( n - 1 ) || j != n ) { cout << " " ; }
            else { cout << "\n" ; }
        }
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}