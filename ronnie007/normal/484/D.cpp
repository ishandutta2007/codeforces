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

#define MAXN 1000007

int n ;
int a[ MAXN ] ;


int mn[ MAXN ][ 22 ] ;
int mx[ MAXN ][ 22 ] ;

long long dp[ MAXN ] ;

int lenid[ MAXN ] ;

void init ( ) {
	int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	mn[ i ][ 0 ] = mx[ i ][ 0 ] = a[ i ] ;
    }
    for ( j = 1 ; j <= 20 ; j ++ ) {
    	int u = (1<<j) ;
    	for ( i = 1 ; i <= n ; i ++ ) {
        	if ( ( i + u - 1 ) > n ) { break ; }
            mn[ i ][ j ] = min ( mn[ i ][ j - 1 ] , mn[ i + ( u / 2 ) ][ j - 1 ] ) ;
            mx[ i ][ j ] = max ( mx[ i ][ j - 1 ] , mx[ i + ( u / 2 ) ][ j - 1 ] ) ;            
        }
    }
    int br = 0 ;
    int ln = 1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	while ( ( 2 * ln ) < i ) { br ++ ; ln *= 2 ; }
        lenid[ i ] = br ;
    }
}

int getans ( int l , int r ) {
	int id = lenid[ r - l + 1 ] ;
	int u = ( 1 << id ) ;
    int p , q ;
    p = max ( mx[ l ][ id ] , mx[ r - u + 1 ][ id ] ) ;
    q = min ( mn[ l ][ id ] , mn[ r - u + 1 ][ id ] ) ;
    return ( p - q ) ;
}

void input ( ) {
	cin >> n ;
    int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ] ;
    }
}

void solve ( ) {
    init ( ) ;
    int i , j ;
    int prv = 0 ;
    for ( i = 2 ; i <= n ; i ++ ) {
    	dp[ i ] = dp[ i - 1 ] ;
		for ( j = -1 ; j < 2 ; j ++ ) {
        	if ( ( prv + j ) <= 0 ) { continue ; }
            dp[ i ] = max ( dp[ i ] , dp[ prv + j - 1 ] + getans ( prv + j , i ) ) ;
		}
        if ( a[ i ] >= a[ i - 1 ] && a[ i ] >= a[ i + 1 ] ) { prv = i ; }
        if ( a[ i ] <= a[ i - 1 ] && a[ i ] <= a[ i + 1 ] ) { prv = i ; }        
    }
    cout << dp[ n ] << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}