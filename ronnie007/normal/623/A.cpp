#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

#define MAXN 507

int n , m ;
int a[ MAXN ][ MAXN ] ;
vector < int > v[ MAXN ] ;
string s ;

void dfs ( int vertex ) {
	s[ vertex ] = 'a' ;
    int i , sz ;
    sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	if ( s[ v[ vertex ][ i ] ] == '.' ) { dfs ( v[ vertex ][ i ] ) ; }
    }
}

void input ( ) {
	cin >> n >> m ;
    int i ;
    int x , y ;
    for ( i = 1 ; i <= m ; i ++ ) {
		cin >> x >> y ;
        x -- ;
        y -- ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
        a[ x ][ y ] = a[ y ][ x ] = 1 ;
    }
}

void solve ( ) {
	int i , j ;
    for ( i = 0 ; i < n ; i ++ ) { s += '.' ; }
	for ( i = 0 ; i < n ; i ++ ) {
    	if ( v[ i ].size ( ) == ( n - 1 ) ) { s[ i ] = 'b' ; }
    }
    for ( i = 0 ; i < n ; i ++ ) {
    	if ( s[ i ] == '.' ) {
            dfs ( i ) ;
            break ; 
        }
    }

    for ( i = 0 ; i < n ; i ++ ) {
    	if ( s[ i ] == '.' ) {
			s[ i ] = 'c' ;
        }
    }
    for ( i = 0 ; i < n ; i ++ ) {
    	for ( j = i + 1 ; j < n ; j ++ ) {
        	if ( a[ i ][ j ] == 0 ) {
				int u1 = ( s[ i ] - 'a' ) ;
                int u2 = ( s[ j ] - 'a' ) ;
                if ( u1 < u2 ) { swap ( u1 , u2 ) ; }
                if ( ( u1 - u2 ) != 2 ) { cout << "No\n" ; return ; }
            }
            else {
				int u1 = ( s[ i ] - 'a' ) ;
                int u2 = ( s[ j ] - 'a' ) ;
                if ( u1 < u2 ) { swap ( u1 , u2 ) ; }
                if ( ( u1 - u2 ) == 2 ) { cout << "No\n" ; return ; }            
            }
        }
    }
    cout << "Yes\n" ;
    cout << s << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}