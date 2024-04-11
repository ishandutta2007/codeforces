#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;

#define MAXN 4307

int n ;
string a ;
string b , revb ;

int dp[ MAXN ] ;
pair < int , int > prv[ MAXN ] ;

pair < int , int > cur ;

int PI[ MAXN ] ;

int f ( int st , int id ) {
	string c ;
	c.clear ( ) ;
	int i ;
	for ( i = st ; i < n ; i ++ ) { c += a[ i ] ; }
	c += '#' ;
	int sz = b.size ( ) ; 
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( id == 0 ) { c += b[ i ] ; }
		else { c += revb[ i ] ; }
	}
	sz = c.size ( ) ;
	PI[ 0 ] = PI[ 1 ] = 0 ;
	int l = 0 ;
	int mx = 0 ;
	for ( i = 2 ; i <= sz ; i ++ ) {
		while ( c[ l ] != c[ i - 1 ] && l != 0 ) {
			l = PI[ l ] ;
		}
		if ( c[ l ] == c[ i - 1 ] ) { l ++ ; }
		PI[ i ] = l ;
		if ( i >= n - st + 2 && mx < PI[ i ] ) {
			mx = PI[ i ] ;
			int fr = ( i - PI[ i ] + 1 ) - ( n - st ) - 2 ;
			int en = i - ( n - st ) - 2 ; 
			if ( id == 1 ) {
				fr = b.size ( ) - fr - 1 ;
				en = b.size ( ) - en - 1 ; 
			}
			cur = make_pair ( fr , en ) ;
		}
	}
	return ( st + mx ) ;
}

void input ( ) {
	cin >> b ;
	int sz = b.size ( ) ;
	int i ;
	for ( i = sz - 1 ; i >= 0 ; i -- ) { revb += b[ i ] ; }
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( ) {
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		dp[ i ] = 2 * MAXN ; 
	}
	dp[ 0 ] = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( dp[ i ] == MAXN ) { continue ; }
		int id ;
		id = f ( i , 0 ) ;
		if ( dp[ id ] > dp[ i ] + 1 ) { dp[ id ] = dp[ i ] + 1 ; prv[ id ] = cur ; }
		id = f ( i , 1 ) ;
		if ( dp[ id ] > dp[ i ] + 1 ) { dp[ id ] = dp[ i ] + 1 ; prv[ id ] = cur ; }
	}
	if ( dp[ n ] > n ) { cout << "-1\n" ; }
	else {
		cout << dp[ n ] << "\n" ; 
		vector < pair < int , int > > v ;
		int where = n ;
		while ( where != 0 ) {
			v.push_back ( prv[ where ] ) ;
			where = where - ( abs ( prv[ where ].second - prv[ where ].first ) + 1 ) ;
		}
		for ( i = dp[ n ] - 1 ; i >= 0 ; i -- ) {
			cout << v[ i ].first + 1 << " " << v[ i ].second + 1 << "\n" ; 
		}
	}
	
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}