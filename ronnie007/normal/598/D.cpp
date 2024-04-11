#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MAXN 1007

int n , m , k ;
string a[ MAXN ] ;

int used[ MAXN ][ MAXN ] ;

int sm[ MAXN * MAXN ] ;

int br[ MAXN ][ MAXN ] ;

int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;

void dfs ( int x , int y , int id ) {
	used[ x ][ y ] = id ;
    sm[ id ] += br[ x ][ y ] ;
    int i ;
    for ( i = 0 ; i < 4 ; i ++ ) {
    	int nx = x + dx[ i ] ;
        int ny = y + dy[ i ] ;
        if ( nx < 0 || nx >= n ) { continue ; }
        if ( ny < 0 || ny >= m ) { continue ; }
        if ( a[ nx ][ ny ] == '*' ) { continue ; }
        if ( used[ nx ][ ny ] != 0 ) { continue ; }
        dfs ( nx , ny , id ) ;
    }
}

void input ( ) {
	cin >> n >> m >> k ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
    	cin >> a[ i ] ;
    }
}

void solve ( ) {
	int i , j , t ;
    for ( i = 0 ; i < n ; i ++ ) {
    	for ( j = 0 ; j < m ; j ++ ) {
        	if ( a[ i ][ j ] != '.' ) { continue ; }
            for ( t = 0 ; t < 4 ; t ++ ) {
            	int nx = i + dx[ t ] ;
                int ny = j + dy[ t ] ;
                if ( nx < 0 || nx >= n ) { continue ; }
                if ( ny < 0 || ny >= m ) { continue ; }
                if ( a[ nx ][ ny ] != '*' ) { continue ; }
                br[ i ][ j ] ++ ;
            }
        }
    }
    int id = 1 ;
    for ( i = 0 ; i < n ; i ++ ) {
    	for ( j = 0 ; j < m ; j ++ ) {
        	if ( used[ i ][ j ] == 0 && a[ i ][ j ] == '.' ) {
            	dfs ( i , j , id ) ;
                id ++ ;
            }
        }
    }
    while ( k != 0 ) {
    	k -- ;
        int x , y ;
        cin >> x >> y ;
        x -- ;
        y -- ;
        cout << sm[ used[ x ][ y ] ] << "\n" ;
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}