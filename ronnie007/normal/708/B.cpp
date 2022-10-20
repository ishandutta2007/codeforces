#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std ;

long long x , y , z , t ;

long long p , q ;

void input ( ) {
	scanf ( "%I64d%I64d%I64d%I64d" , &x , &y , &z , &t ) ;
}

void solve ( ) {
	long long i ;
    p = q = -1 ;
    for ( i = 1 ; i <= 100000 ; i += 1 ) {
    	if ( ( i * ( i - 1 ) / 2 ) == x && p == -1 ) { p = i ; }
    	if ( ( i * ( i - 1 ) / 2 ) == t && q == -1 ) { q = i ; }        
    }
    if ( x == 0 && t == 0 ) {
    	if ( y + z > 1 ) {
			printf ( "Impossible\n" ) ;
        	return ;
		}
        if ( ( y + z ) == 0 ) {
        	printf ( "0\n" ) ;
            return ;
        }
        if ( y == 1 ) {
        	printf ( "01\n" ) ;
            return ;
        }
        if ( z == 1 ) {
        	printf ( "10\n" ) ;
            return ;
        }

		printf ( "Impossible\n" ) ;
		return ;        
    }
    if ( x == 0 ) {
    	if ( q == -1 ) {
			printf ( "Impossible\n" ) ;
        	return ;
        }    
    	if ( ( y + z ) == q ) {
        	for ( i = 0 ; i < z ; i += 1 ) { printf ( "1" ) ; }
            printf ( "0" ) ;
			for ( i = 0 ; i < y ; i += 1 ) { printf ( "1" ) ; }
            printf ( "\n" ) ;
            return ;
        }
        if ( ( y + z ) == 0 ) {
        	for ( i = 1 ; i <= q ; i += 1 ) { printf ( "1" ) ; }
            printf ( "\n" ) ;
            return ;
        }
        printf ( "Impossible\n" ) ;
        return ;
    }

    if ( t == 0 ) {
    	if ( p == -1 ) {
			printf ( "Impossible\n" ) ;
        	return ;
        }
    	if ( ( y + z ) == p ) {
        	for ( i = 0 ; i < y ; i += 1 ) { printf ( "0" ) ; }
            printf ( "1" ) ;
			for ( i = 0 ; i < z ; i += 1 ) { printf ( "0" ) ; }
            printf ( "\n" ) ;
            return ;
        }
        if ( ( y + z ) == 0 ) {
        	for ( i = 1 ; i <= p ; i += 1 ) { printf ( "0" ) ; }
            printf ( "\n" ) ;
            return ;
        }
        printf ( "Impossible\n" ) ;
        return ;
    }
    
    if ( p == -1 || q == -1 ) {
    	printf ( "Impossible\n" ) ;
        return ;
   	}
    if ( p * q != ( y + z ) ) {
        printf ( "Impossible\n" ) ;
        return ;
    }
    vector < int > v ;
    for ( i = 1 ; i <= q ; i += 1 ) {
    	v.push_back ( 1 ) ;
    }
	for ( i = 1 ; i <= p ; i += 1 ) {
    	v.push_back ( 0 ) ;
    }
    int sz = p + q ;
    for ( i = q ; i < sz ; i += 1 ) {
    	if ( y > q ) {
        	y -= q ;
            swap ( v[ ( i - q ) ] , v[ i ] ) ;
        }
        else {
        	int id = i ;
        	while ( y != 0 ) {
            	y -- ;
                swap ( v[ ( id - 1 ) ] , v[ id ] ) ;
                id -- ;
            }
            break ;
        }
    }
    for ( i = 0 ; i < sz ; i ++ ) {
    	printf ( "%d" , v[ i ] ) ;
    }
   	printf ( "\n" ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}