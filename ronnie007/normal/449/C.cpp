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

#define MAXN 100007

int n ;
bool prime[ MAXN ] ;
bool used[ MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
}

void solve ( ) {
	int i , j ;
    prime[ 1 ] = false ;
    for ( i = 2 ; i <= n ; i ++ ) {
    	prime[ i ] = true ;
    }
    for ( i = 2 ; i <= n ; i ++ ) {
    	if ( prime[ i ] == false ) { continue ; }
        for ( j = 2 * i ; j <= n ; j += i ) {
        	prime[ j ] = false ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	used[ i ] = false ;
    }
    vector < pair < int , int > > ans ;
    for ( i = n ; i >= 1 ; i -- ) {
    	if ( prime[ i ] == false ) { continue ; }
        if ( used[ i ] == true ) { continue ; }
        if ( 2 * i > n ) { continue ; }
        int br = 1 ; 
        for ( j = 2 * i ; j <= n ; j += i ) {
        	if ( used[ j ] == true ) { continue ; }
        	br ++ ;
		}
        j -= i ;
        if ( ( br % 2 ) == 0 ) {
        	int lst = -1 ;
            for ( ; j >= i ; j -= i ) {
	        	if ( used[ j ] == true ) { continue ; }            
            	if ( lst == -1 ) { lst = j ; }
                else {
                	ans.push_back ( make_pair ( j , lst ) ) ;
                    used[ j ] = used[ lst ] = true ;
                    lst = -1 ;
                }
            }
        }
        else {
        	if ( br == 1 ) { continue ; }
        	while ( used[ j ] == true ) { j -= i ; }
	        ans.push_back ( make_pair ( i , j ) ) ;
    	    used[ i ] = used[ j ] = true ;
        	j -= i ;
			int lst = -1 ;
			for ( ; j >= i ; j -= i ) {
				if ( used[ j ] == true ) { continue ; }                
				if ( lst == -1 ) { lst = j ; }
				else {
					ans.push_back ( make_pair ( j , lst ) ) ;
					used[ j ] = used[ lst ] = true ;
					lst = -1 ;
    	        }        	
			}
		}
    }
    int sz = ans.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	printf ( "%d %d\n" , ans[ i ].first , ans[ i ].second ) ;
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}