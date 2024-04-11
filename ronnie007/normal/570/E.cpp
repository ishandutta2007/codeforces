#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<ctime>
using namespace std ;

#define MOD 1000000007
#define MAXN 507

int n , m ;
string a[ MAXN ] ;

int dp[ 2 ][ MAXN ][ MAXN ] ;
int dx[ 4 ][ 4 ] = {
	{ 1 , 0 , -1 , 0 } ,
	{ 1 , 0 , 0 , -1 } ,
	{ 0 , 1 , -1 , 0 } ,
	{ 0 , 1 , 0 , -1 } } ;

void input ( ) ;
void solve ( ) ;

int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	cin >> n >> m ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		cin >> a[ i ] ;
    }
}

void solve ( ) {
	if ( a[ 0 ][ 0 ] != a[ n - 1 ][ m - 1 ] ) { 
		printf ( "0\n" ) ;
		return ;
    }
	int len , i , j , t ;
	dp[ 0 ][ 0 ][ 0 ] = 1 ;
	int x1 , y1 , x2 , y2 ;
	int lim = ( n + m - 2 ) / 2 ; 
	int prev = 0 ;
	int cur = 1 ; 
	int ans = 0 ;
	for ( len = 0 ; len < lim ; len ++ ) {
		for ( i = 0 ; i <= len ; i ++ ) {
			for ( j = 0 ; j <= len ; j ++ ) {
				if ( dp[ prev ][ i ][ j ] == 0 ) { continue ; }
				x1 = ( len - i ) ;
				y1 = len - x1 ;
				x2 = n - ( len - j ) - 1 ;
				y2 = m - j - 1 ;
				for ( t = 0 ; t < 4 ; t ++ ) {
					int nx1 = x1 + dx[ t ][ 0 ] ;
					int ny1 = y1 + dx[ t ][ 1 ] ;
					int nx2 = x2 + dx[ t ][ 2 ] ;
					int ny2 = y2 + dx[ t ][ 3 ] ;
					if ( nx1 < 0 || nx1 >= n ) { continue ; }
					if ( ny1 < 0 || ny1 >= m ) { continue ; }
					if ( nx2 < 0 || nx2 >= n ) { continue ; }
					if ( ny2 < 0 || ny2 >= m ) { continue ; }
					if ( a[ nx1 ][ ny1 ] != a[ nx2 ][ ny2 ] ) { continue ; }
					dp[ cur ][ i + dx[ t ][ 1 ] ][ j - dx[ t ][ 3 ] ] += dp[ prev ][ i ][ j ] ;
					if ( dp[ cur ][ i + dx[ t ][ 1 ] ][ j - dx[ t ][ 3 ] ] >= MOD ) {
						dp[ cur ][ i + dx[ t ][ 1 ] ][ j - dx[ t ][ 3 ] ] -= MOD ;
                    }
                }
				dp[ prev ][ i ][ j ] = 0 ;
            }
        }
		prev ^= 1 ;
		cur ^= 1 ;
    }
	ans = 0 ;
	if ( ( n + m ) % 2 == 0 ) {
		for ( i = 0 ; i < m ; i ++ ) {
			ans += dp[ prev ][ i ][ m - i - 1 ] ;
			if ( ans >= MOD ) { ans -= MOD ; }
        }
    }
	else { 
		for ( i = 0 ; i < m ; i ++ ) {
			ans += dp[ prev ][ i ][ m - i - 1 ] ;
			if ( ans >= MOD ) { ans -= MOD ; }
			if ( i != m - 1 ) { ans += dp[ prev ][ i ][ m - i - 2 ] ; }
			if ( ans >= MOD ) { ans -= MOD ; }
        }
    }
	printf ( "%d\n" , ans ) ;
}