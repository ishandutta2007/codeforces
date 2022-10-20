#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std ;

int n , m ;
string a[ 2001 ] ;
string b[ 2001 ] ;
//int used[ 2001 ][ 2001 ] ;

int pr[ 2001 ][ 2001 ] ;

int table[ 2001 ][ 2001 ] ;


int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;

queue < pair < int , int > > q ;
/**
void dfs ( int x , int y , int par ) {
	used[ x ][ y ] = 1 ;
	int i ;
	int nx , ny ;
	int br = 0 ;
	int u = ( x * m + y ) ;
	for ( i = 0 ; i < 4 ; i ++ ) {
		nx = ( x + dx[ i ] ) ;
		ny = ( y + dy[ i ] ) ;
		if ( nx < 0 || nx >= n ) { continue ; }
		if ( ny < 0 || ny >= m ) { continue ; }
		if ( a[ nx ][ ny ] == '*' ) { continue ; }
		if ( par != ( nx * m + ny ) ) { br ++ ; }
		if ( used[ nx ][ ny ] == 1 ) { continue ; }
		dfs ( nx , ny , u ) ;
    }
	pr[ x ][ y ] = br ;
	if ( par != -1 ) { pr[ x ][ y ] ++ ; }
	if ( br == 0 ) { 
		pr[ x ][ y ] = -100 ;
		q.push ( make_pair ( x , y ) ) ;
    }
}
**/

int get ( int x , int y ) {
	int i ;
	int br = 0 ;
	for ( i = 0 ; i < 4 ; i ++ ) {
		int nx = ( x + dx[ i ] ) ;
		int ny = ( y + dy[ i ] ) ;
		if ( nx < 0 || nx >= n ) { continue ; }
		if ( ny < 0 || ny >= m ) { continue ; }
		if ( a[ nx ][ ny ] == '*' ) { continue ; }
		br ++ ;
    }
	if ( br == 1 ) { q.push ( make_pair ( x , y ) ) ; }
	return br ;
}

void input ( ) ;
void solve ( ) ;


int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	cin >> n >> m ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		cin >> a[ i ] ; 
		b[ i ] = a[ i ] ;
    }
}

void solve ( )  {
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( a[ i ][ j ] == '*' )  { continue ; }
			/**
			if ( used[ i ][ j ] == 1 ) { continue ; }
			dfs ( i , j , -1 ) ;
			**/
			pr[ i ][ j ] = get ( i , j ) ;
        }
    }
	pair < int , int > p , e ;
	int nx , ny ;
	int id = 1 ;
	while ( q.empty ( ) == false ) {
		p = q.front ( ) ;
		q.pop ( ) ;
		if ( pr[ p.first ][ p.second ] == -200 ) { continue ; }
		for ( i = 0 ; i < 4 ; i ++ ) {
			nx = ( p.first + dx[ i ] ) ;
			ny = ( p.second + dy[ i ] ) ;
			if ( nx < 0 || nx >= n ) { continue ; }
			if ( ny < 0 || ny >= m ) { continue ; }
			if ( a[ nx ][ ny ] == '*' ) { continue ; }
			a[ nx ][ ny ] = '*' ;
			a[ p.first ][ p.second ] = '*' ;
			table[ p.first ][ p.second ] = table[ nx ][ ny ] = id ;
			id ++ ;
			pr[ p.first ][ p.second ] = -200 ;
			p.first = nx ;
			p.second = ny ;
			pr[ nx ][ ny ] = -200 ;
			break ;
        }
		
		for ( i = 0 ; i < 4 ; i ++ ) {
			nx = ( p.first + dx[ i ] ) ;
			ny = ( p.second + dy[ i ] ) ;
			if ( nx < 0 || nx >= n ) { continue ; }
			if ( ny < 0 || ny >= m ) { continue ; }
			if ( a[ nx ][ ny ] == '*' ) { continue ; }
			pr[ nx ][ ny ] -- ;
			if ( pr[ nx ][ ny ] == 1 ) { pr[ nx ][ ny ] = -100 ; q.push ( make_pair ( nx , ny ) ) ; }
        }
    }
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( b[ i ][ j ] == '.' && table[ i ][ j ] == 0 ) { 	
				cout << "Not unique\n" ;
				return ;
			}
        }
    }
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m - 1 ; j ++ ) {
			if ( table[ i ][ j ] == 0 ) { continue ; }
			if ( table[ i ][ j ] == table[ i ][ j + 1 ] ) { a[ i ][ j ] = '<' ; a[ i ][ j + 1 ] = '>' ; }
        }
    }

	for ( i = 0 ; i < n - 1 ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( table[ i ][ j ] == 0 ) { continue ; }
			if ( table[ i ][ j ] == table[ i + 1 ][ j ] ) { a[ i ][ j ] = '^' ; a[ i + 1 ][ j ] = 'v' ; }
        }
    }
	for ( i = 0 ; i < n ; i ++ ) {
		cout << a[ i ] << "\n" ;
    }
}