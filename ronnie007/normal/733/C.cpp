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

int n ;
int a[ MAXN ] ;
int k ;
int b[ MAXN ] ;

vector < pair < int , int > > v ;

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
    scanf ( "%d" , &k ) ;
    for ( i = 1 ; i <= k ; i ++ ) {
    	scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
	int i , j ;
    int id = 1 ;
    int lst = 0 ;
    while ( id <= k ) {
    	int sm = 0 ;
        for ( i = lst + 1 ; i <= n ; i ++ ) {
        	sm += a[ i ] ;
            if ( sm == b[ id ] ) { break ; }
            if ( sm > b[ id ] ) { break ; }
        }
        if ( sm != b[ id ] ) {
        	printf ( "NO\n" ) ;
            return ;
        }
        if ( i > n ) {
        	printf ( "NO\n" ) ;
            return ;
        }
        int st = lst + 1 ;
        int en = i ;
        if ( st == en ) { lst = en ; id ++ ; continue ; }
        int mx = 0 ;
        for ( i = st ; i <= en ; i ++ ) {
        	if ( mx < a[ i ] ) { mx = a[ i ] ; }
        }
        int h = -1 ; 
        for ( i = st ; i <= en ; i ++ ) {
        	if ( a[ i ] == mx ) {
            	if ( i != st && a[ i - 1 ] < a[ i ] ) { h = i ; }
                if ( i != en && a[ i + 1 ] < a[ i ] ) { h = i ; }
            }
        }
        if ( h == -1 ) {
        	printf ( "NO\n" ) ;
            return ;        
        }
        if ( h != en && a[ h + 1 ] < a[ h ] ) {
	        for ( i = h + 1 ; i <= en ; i ++ ) {
    	    	v.push_back ( make_pair ( ( h - st + 1 ) + ( id - 1 ) , 2 ) ) ;
        	}
	        for ( i = h - 1 ; i >= st ; i -- ) {
    	    	v.push_back ( make_pair ( ( i + 1 - st + 1 ) + ( id - 1 ) , 1 ) ) ;
        	}
		}
        else {
	        for ( i = h - 1 ; i >= st ; i -- ) {
    	    	v.push_back ( make_pair ( ( i + 1 - st + 1 ) + ( id - 1 ) , 1 ) ) ;
        	}                
	        for ( i = h + 1 ; i <= en ; i ++ ) {
    	    	v.push_back ( make_pair ( 1 + ( id - 1 ) , 2 ) ) ;
        	}
        }
        lst = en ;
        id ++ ;
    }
    if ( lst != n ) {
    	printf ( "NO\n" ) ;
        return ;
    }
    printf ( "YES\n" ) ;
    int sz = v.size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	printf ( "%d " , v[ i ].first ) ;
        if ( v[ i ].second == 1 ) { printf ( "L\n" ) ; }
        else { printf ( "R\n" ) ; }
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}