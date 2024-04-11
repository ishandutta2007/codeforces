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

#define MAXN 2007
int n , m ;
string a[ MAXN ] ;

int lft[ MAXN ][ MAXN ] ;
bool vis[ MAXN ][ MAXN ] ;

void input ( ) {
	cin >> n >> m ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
    	cin >> a[ i ] ;
    }
}

void solve ( ) {
	int i , j , t , z ;
    int id = 1 ;
    for ( i = 0 ; i < n - 1 ; i ++ ) {
    	for ( j = 0 ; j < m - 1 ; j ++ ) {
        	for ( t = 0 ; t < 2 ; t ++ ) {
            	for ( z = 0 ; z < 2 ; z ++ ) {
		            lft[ i ][ j ] += ( a[ i + t ][ j + z ] == '.' ) ;                
                }
            }
            vis[ i ][ j ] = false ;
        }
    }
    queue < pair < int , int > > q ;
    for ( i = 0 ; i < n - 1 ; i ++ ) {
    	for ( j = 0 ; j < m - 1 ; j ++ ) {
        	if ( lft[ i ][ j ] == 3 ) { q.push ( make_pair ( i , j ) ) ; }
        }
    }
    pair < int , int > p ;
    while ( q.empty ( ) == false ) {
    	p = q.front ( ) ;
        q.pop ( ) ;
        vis[ p.first ][ p.second ] = true ;
        int nx , ny ;
        nx = ny = -1 ;
        for ( t = 0 ; t < 2 ; t ++ ) {
        	for ( z = 0 ; z < 2 ; z ++ ) {
            	if ( a[ p.first + t ][ p.second + z ] == '*' ) {
                	nx = p.first + t ;
                    ny = p.second + z ;
                	a[ p.first + t ][ p.second + z ] = '.' ;
                }
            }
        }
        if ( nx == -1 || ny == -1 ) { continue ; }
        for ( t = 0 ; t < 2 ; t ++ ) {
        	for ( z = 0 ; z < 2 ; z ++ ) {
            	if ( ( nx - t ) < 0 || ( ny - z ) < 0 ) { continue ; }
                lft[ nx - t ][ ny - z ] ++ ;
                if ( lft[ nx - t ][ ny - z ] == 3 && vis[ nx - t ][ ny - z ] == false ) {
                	q.push ( make_pair ( nx - t , ny - z ) ) ;
                }
            }
        }
    }
    for ( i = 0 ; i < n ; i ++ ) {
		cout << a[ i ] << "\n" ;
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}