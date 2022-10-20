#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

#define MAXN 507

int n , k ;
string a[ MAXN ] ;
int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;

int prv[ MAXN * MAXN ] ;
int sz[ MAXN * MAXN ] ;
bool used[ MAXN * MAXN ] ;

int code ( int x , int y ) {
	return ( x * n + y + 1 ) ;
}

int find ( int x ) {
	if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( int x , int y ) {
	int k1 = find ( x ) ;
    int k2 = find ( y ) ;
	if ( k1 != k2 ) {
    	prv[ k1 ] = k2 ;
        sz[ k2 ] += sz[ k1 ] ;
    }
}

void input ( ) {
	cin >> n >> k ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
    	cin >> a[ i ] ;
    }
}

void solve ( ) {
	int i , j , t , z ;
    for ( i = 0 ; i < n ; i ++ ) {
    	for ( j = 0 ; j < n ; j ++ ) {
        	int id = code ( i , j ) ;
        	prv[ id ] = -1 ;
            sz[ id ] = 1 ;
        }
    }

    for ( i = 0 ; i < n ; i ++ ) {
    	for ( j = 0 ; j < n ; j ++ ) {
        	if ( a[ i ][ j ] == 'X' ) { continue ; }
			for ( t = 0 ; t < 4 ; t ++ ) {
            	int nx = i + dx[ t ] ;
                int ny = j + dy[ t ] ;
                if ( nx < 0 || nx >= n ) { continue ; }
                if ( ny < 0 || ny >= n ) { continue ; }
                if ( a[ nx ][ ny ] == 'X' ) { continue ; }
                UNITE ( code ( i , j ) , code ( nx , ny ) ) ;
            }
        }
    }
    int ans = 0 ;
    for ( i = 0 ; i + k - 1 < n ; i ++ ) {
    	j = 0 ;
		for ( t = 0 ; t < k ; t ++ ) {
			for ( z = 0 ; z < k ; z ++ ) {
				sz[ find ( code ( i + t , j + z ) ) ] -- ;
			}
		}        
    	for ( j = 0 ; j + k - 1 < n ; j ++ ) {
			int cur = 0 ;
            // top
            if ( i != 0 ) {
	            for ( t = 0 ; t < k ; t ++ ) {
                	if ( a[ i - 1 ][ j + t ] == 'X' ) { continue ; }
                    int id = find ( code ( i - 1 , j + t ) ) ;
                    if ( used[ id ] == false ) {
                    	cur += sz[ id ] ;
                        used[ id ] = true ;
                    }
                }
			}
            // bot
            if ( i + k < n ) {
	            for ( t = 0 ; t < k ; t ++ ) {
                	if ( a[ i + k ][ j + t ] == 'X' ) { continue ; }
                    int id = find ( code ( i + k , j + t ) ) ;
                    if ( used[ id ] == false ) {
                    	cur += sz[ id ] ;
                        used[ id ] = true ;
                    }
                }            	
            }
            // left
            if ( j != 0 ) {
            	for ( t = 0 ; t < k ; t ++ ) {
                	if ( a[ i + t ][ j - 1 ] == 'X' ) { continue ; }
                    int id = find ( code ( i + t , j - 1 ) ) ;
                    if ( used[ id ] == false ) {
                    	cur += sz[ id ] ;
                        used[ id ] = true ;
                    }
                }
            }
            // right
            if ( j + k < n ) {
            	for ( t = 0 ; t < k ; t ++ ) {
                	if ( a[ i + t ][ j + k ] == 'X' ) { continue ; }
                    int id = find ( code ( i + t , j + k ) ) ;
                    if ( used[ id ] == false ) {
                    	cur += sz[ id ] ;
                        used[ id ] = true ;
                    }
                }            
            }
            cur += k * k ;
            if ( ans < cur ) { ans = cur ; }
            // top
            if ( i != 0 ) {
	            for ( t = 0 ; t < k ; t ++ ) {
                	if ( a[ i - 1 ][ j + t ] == 'X' ) { continue ; }
                    int id = find ( code ( i - 1 , j + t ) ) ;
					used[ id ] = false ;
                }
			}
            // bot
            if ( i + k < n ) {
	            for ( t = 0 ; t < k ; t ++ ) {
                	if ( a[ i + k ][ j + t ] == 'X' ) { continue ; }
                    int id = find ( code ( i + k , j + t ) ) ;
					used[ id ] = false ;
                }            	
            }
            // left
            if ( j != 0 ) {
            	for ( t = 0 ; t < k ; t ++ ) {
                	if ( a[ i + t ][ j - 1 ] == 'X' ) { continue ; }
                    int id = find ( code ( i + t , j - 1 ) ) ;
					used[ id ] = false ;
                }
            }
            // right
            if ( j + k < n ) {
            	for ( t = 0 ; t < k ; t ++ ) {
                	if ( a[ i + t ][ j + k ] == 'X' ) { continue ; }
                    int id = find ( code ( i + t , j + k ) ) ;
					used[ id ] = false ;
                }            
            }


            if ( j + k >= n ) { break ; }
            for ( t = 0 ; t < k ; t ++ ) {
            	if ( a[ i + t ][ j ] == 'X' ) { continue ; }
                sz[ find ( code ( i + t , j ) ) ] ++ ;
            }
            for ( t = 0 ; t < k ; t ++ ) {
            	if ( a[ i + t ][ j + k ] == 'X' ) { continue ; }
                sz[ find ( code ( i + t , j + k ) ) ] -- ;
            }            
        }
		for ( t = 0 ; t < k ; t ++ ) {
			for ( z = 0 ; z < k ; z ++ ) {
				sz[ find ( code ( i + t , j + z ) ) ] ++ ;
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