#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
using namespace std ;

#define MAXN 4007
#define MAXK 807
#define inf 1000000007


int n , k ;
int a[ MAXN ][ MAXN ] ;
int pref[ MAXN ][ MAXN ] ;
int cost[ MAXN ][ MAXN ] ;

int dp[ MAXN ][ MAXK ] ;

int id ;

void f ( int l , int r , int st , int en ) {
	if ( l > r || st > en ) { return ; }
   	int i ;
    int mid = ( l + r ) / 2 ;
    int opt = -1 ;
    for ( i = st ; i <= en ; i ++ ) {
    	if ( dp[ mid ][ id ] > dp[ i - 1 ][ id - 1 ] + cost[ i ][ mid ] ) {
        	dp[ mid ][ id ] = dp[ i - 1 ][ id - 1 ] + cost[ i ][ mid ] ;
            opt = i ;
        }
    }
    if ( l == r ) { return ; }
    f ( l , mid - 1 , st , opt ) ;
    f ( mid + 1 , r , opt , en ) ;
}

void input ( ) {
	cin >> n >> k ;
    int i , j ;
    char s[ 3 * MAXN ] ;
    cin.ignore ( ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	cin.getline ( s , 3 * MAXN ) ;
    	for ( j = 1 ; j <= n ; j ++ ) {
        	a[ i ][ j ] = ( s[ 2 * ( j - 1 ) ] - '0' ) ;
        }
    }
}

void solve ( ) {
	int i , j , t ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= n ; j ++ ) {
        	pref[ i ][ j ] = a[ i ][ j ] + pref[ i - 1 ][ j ] + pref[ i ][ j - 1 ] - pref[ i - 1 ][ j - 1 ] ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = i ; j <= n ; j ++ ) {
        	cost[ i ][ j ] = pref[ j ][ j ] - pref[ i - 1 ][ j ] - pref[ j ][ i - 1 ] + pref[ i - 1 ][ i - 1 ] ;
            cost[ i ][ j ] /= 2 ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= k ; j ++ ) {
        	dp[ i ][ j ] = inf ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) { dp[ i ][ 0 ] = inf ; }
    for ( i = 1 ; i <= k ; i ++ ) {
    	id = i ;
    	f ( 1 , n , 1 , n ) ;
    }
	cout << dp[ n ][ k ] << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}