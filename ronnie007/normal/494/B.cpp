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

#define MOD 1000000007
#define MAXN 100007 

long long dp[ MAXN ] ;

string a , b ;
int n , m ;



long long q1[ MAXN ] ;
long long q2[ MAXN ] ;
int PI[ 2 * MAXN ] ;

long long sr1 , sr2 , sr3 ;

int pos[ MAXN ] ;

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
	cin >> a >> b ;
	n = a.size ( ) ;
	m = b.size ( ) ;

}

void solve ( )  {
	if ( m > n ) { cout << "0\n" ; return ; } 
	int i , j ;
	long long h1 , h2 , h3 ;
	long long olddig ;
	long long newdig ;
	string u ;
	u = b + '#' ;
	u += a ;
	PI[ 0 ] = 0 ;
	PI[ 1 ] = 0 ;
	int l = 0 ;
	for ( i = 2 ; i <= n + m + 1 ; i ++ ) {
		while ( l != 0 && u[ i - 1 ] != u[ l ] ) {
			l = PI[ l ] ;
        }
		if ( u[ i - 1 ] == u[ l ] ) l ++ ;
		PI[ i ] = l ;
		if ( l == m && i >= m ) pos[ i - m - 1 ] = 1 ;
    }
	/**
	for ( i = 1 ; i <= n ; i ++ ) {
		cout << i << " " << pos[ i ] << "\n" ;
    }
	**/
	dp[ n ] = 0 ;
	long long sm1 = 0 ;
	long long sm2 = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( pos[ i ] == 0 ) {
			dp[ i ] = dp[ i - 1 ] ;
        }
		else {
			dp[ i ] = q2[ i - m ] + i - m + 1  ;
        }
		dp[ i ] %= MOD ;
		q1[ i ] = q1[ i - 1 ] + dp[ i ] ;
		q1[ i ] %= MOD ;
		q2[ i ] = q2[ i - 1 ] + q1[ i ] ;
		q2[ i ] %= MOD ;
		//cout << i << " " << dp[ i ] << " " << q1[ i ] << " " << q2[ i ] << "\n" ;
    }
	cout << q1[ n ] << "\n" ;
}