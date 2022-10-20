#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 100007

int n ;
long long a[ MAXN ] ;
bool used[ MAXN ] ;
int par[ MAXN ] ;

int u[ MAXN ] ;
long long sm[ MAXN ] ;

long long mx ;

int find ( int x ) {
	if ( par[ x ] == -1 ) { return x ; }
    int y = find ( par[ x ] ) ;
    par[ x ] = y ;
    return y ;
}

void UNITE ( int x , int y ) {
	int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
    	sm[ k1 ] += sm[ k2 ] ;
        if ( mx < sm[ k1 ] ) { mx = sm[ k1 ] ; }
        par[ k2 ] = k1 ;
    }
}

void input ( ) {
	cin >> n ;
   	int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	cin >> a[ i ] ; 
    }
}

void solve ( ) {
	vector < long long > ans ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	cin >> u[ i ] ;
        used[ i ] = false ;
        par[ i ] = -1 ;
    }
    for ( i = n ; i >= 1 ; i -- ) {
        ans.push_back ( mx ) ;    
    	used[ u[ i ] ] = true ;
        sm[ u[ i ] ] = a[ u[ i ] ] ;
        if ( mx < sm[ u[ i ] ] ) { mx = sm[ u[ i ] ] ; }
        if ( u[ i ] != 1 && used[ u[ i ] - 1 ] == true ) { UNITE ( u[ i ] , u[ i ] - 1 ) ; }
        if ( u[ i ] != n && used[ u[ i ] + 1 ] == true ) { UNITE ( u[ i ] , u[ i ] + 1 ) ; }        

    }
    for ( i = n - 1 ; i >= 0 ; i -- ) {
    	cout << ans[ i ] << "\n" ;
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}