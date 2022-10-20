#include<iostream>
#include<stdio.h>
using namespace std ;

#define MAXN 507

int n , m ;
string a[ MAXN ] ;

// x --> UP
// y --> LEFT

int x[ MAXN ][ MAXN ] ;
int y[ MAXN ][ MAXN ] ;

int prefx[ MAXN ][ MAXN ] ;
int prefy[ MAXN ][ MAXN ] ;

void input ( ) {
	cin >> n >> m ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ] ;
		a[ i ] = '%' + a[ i ] ;
	}
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= m ; j ++ ) {
			if ( a[ i ][ j ] == '#' ) {
				x[ i ][ j ] = y[ i ][ j ] = 0 ;
				continue ;
			}
			if ( a[ i ][ j ] == a[ i - 1 ][ j ] ) { x[ i ][ j ] = 1 ; }
			else { x[ i ][ j ] = 0 ; }
			if ( a[ i ][ j ] == a[ i ][ j - 1 ] ) { y[ i ][ j ] = 1 ; }
			else { y[ i ][ j ] = 0 ; }
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= m ; j ++ ) {
			prefx[ i ][ j ] = prefx[ i - 1 ][ j ] + prefx[ i ][ j - 1 ] - prefx[ i - 1 ][ j - 1 ] + x[ i ][ j ] ; 
			prefy[ i ][ j ] = prefy[ i - 1 ][ j ] + prefy[ i ][ j - 1 ] - prefy[ i - 1 ][ j - 1 ] + y[ i ][ j ] ; 
		}
	}
	int q ;
	cin >> q ;
	int r1 , r2 , c1 , c2 ;
	while ( q != 0 ) {
		q -- ;
		cin >> r1 >> c1 >> r2 >> c2 ;
		int ans = prefx[ r2 ][ c2 ] - prefx[ r1 ][ c2 ] - prefx[ r2 ][ c1 - 1 ] + prefx[ r1 ][ c1 - 1 ] ;
		ans += prefy[ r2 ][ c2 ] - prefy[ r1 - 1 ][ c2 ] - prefy[ r2 ][ c1 ] + prefy[ r1 - 1 ][ c1 ] ;
		cout << ans << "\n" ;
	}
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}