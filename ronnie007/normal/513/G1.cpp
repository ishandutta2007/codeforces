#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n , m ;
vector < int > x ;

double sm ;
int br = 0 ;

void w ( vector < int > v ) {
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = i + 1 ; j < n ; j ++ ) {
			if ( v[ j ] < v[ i ] ) { sm += 1.00 ; }
        }
    }
}

void f ( vector < int > v , int k ) {
	if ( k == 0 ) {
		br ++ ; 
		w ( v ) ;
		return ;
    }
	int i , j , t ;
	vector < int > u ;
	u = v ;
	int l = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = i ; j < n ; j ++ ) {
			u = v ;
			l = i ;
			for ( t = j ; t >= i ; t -- ) {
				u[ t ] = v[ l ] ;
				l ++ ;
            }
			f ( u , k - 1 ) ;
        }
    }
}

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	x.resize ( n ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &x[ i ] ) ;
    }
}

void solve ( )  {
	f ( x , m ) ;
	sm /= br ;
	printf ( "%.15lf\n" , sm ) ;
}