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

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;
int rmq[ 2 ][ MAXN ][ 20 ] ;

int id[ MAXN ] ;

int f ( int l , int r ) {
	int len = ( r - l + 1 ) ;
	int st = r - ( 1 << id[ len ] ) + 1 ;
    int u1 = max ( rmq[ 0 ][ l ][ id[ len ] ] , rmq[ 0 ][ st ][ id[ len ] ] ) ;
    int u2 = min ( rmq[ 1 ][ l ][ id[ len ] ] , rmq[ 1 ][ st ][ id[ len ] ] ) ;
    return ( u1 - u2 ) ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i , j , t , z ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
        rmq[ 0 ][ i ][ 0 ] = a[ i ] ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &b[ i ] ) ;
        rmq[ 1 ][ i ][ 0 ] = b[ i ] ;        
    }
    for ( i = 1 ; i < 20 ; i ++ ) {
    	int u = (1<<i) ;
        for ( j = 1 ; j + u - 1 <= n ; j ++ ) {
        	int p = ( j + ( u / 2 ) ) ;
            rmq[ 0 ][ j ][ i ] = max ( rmq[ 0 ][ j ][ i - 1 ] , rmq[ 0 ][ p ][ i - 1 ] ) ;
			rmq[ 1 ][ j ][ i ] = min ( rmq[ 1 ][ j ][ i - 1 ] , rmq[ 1 ][ p ][ i - 1 ] ) ;
        }
    }

}

void solve ( ) {
	int i ;
    int st = 1 ;
    int p = 0 ;
   	for ( i = 1 ; i <= n ; i ++ ) {
    	while ( 2 * st < i ) { p ++ ; st *= 2 ; }
        id[ i ] = p ;
    }
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
  		int l , r , mid ;
        l = i ;
        r = n ;
        while ( r - l > 3 ) {
        	mid = ( l + r ) / 2 ;
            if ( f ( i , mid ) < 0 ) { l = mid ; }
            else { r = mid ; }
        }
        while ( l <= n && f ( i , l ) < 0 ) { l ++ ; }
        int x = l ;
        l = x ;
        r = n ;
        while ( r - l > 3 ) {
        	mid = ( l + r ) / 2 ;
            if ( f ( i , mid ) > 0 ) { r = mid ; }
            else { l = mid ; }
        }
        while ( r >= x && f ( i , r ) > 0 ) { r -- ; }
        if ( f ( i , x ) != 0 || f ( i , r ) != 0 ) { continue ; }
        if ( x > r ) { continue ; }
        ans += ( r - x + 1 ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}