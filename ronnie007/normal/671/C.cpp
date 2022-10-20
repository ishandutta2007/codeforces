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

#define MAXN 200007

int n ;
int a[ MAXN ] ;

vector < int > v[ MAXN ] ;

long long mn[ 5 * MAXN ] ;
long long mx[ 5 * MAXN ] ;
long long sm[ 5 * MAXN ] ;
long long lazy[ 5 * MAXN ] ;
long long br[ MAXN ] ;
int LEAVES ;

void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
	if ( IR < CURL || CURR < IL ) { return ; }
    if ( val <= mn[ where ] ) { return ; }
    if ( CURL <= IL && IR <= CURR && val >= mx[ where ] ) {
    	mx[ where ] = mn[ where ] = val ;
        sm[ where ] = 1LL * ( IR - IL + 1 ) * val ;
        lazy[ where ] = val ;
        return ;
    }
    if ( lazy[ where ] != 0 ) {
    	mx[ 2 * where ] = mn[ 2 * where ] = lazy[ where ] ;
        mx[ 2 * where + 1 ] = mn[ 2 * where + 1 ] = lazy[ where ] ;
        sm[ 2 * where ] = sm[ 2 * where + 1 ] = 1LL * ( ( IR - IL + 1 ) / 2 ) * lazy[ where ] ;
        lazy[ 2 * where ] = lazy[ 2 * where + 1 ] = lazy[ where ] ;
        lazy[ where ] = 0 ;
    }
    int mid = ( IL + IR ) / 2 ;
    update ( 2 * where , IL , mid , CURL , CURR , val ) ;
    update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
    mx[ where ] = max ( mx[ 2 * where ] , mx[ 2 * where + 1 ] ) ;
    mn[ where ] = min ( mn[ 2 * where ] , mn[ 2 * where + 1 ] ) ;
    sm[ where ] = sm[ 2 * where ] + sm[ 2 * where + 1 ] ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
        int j ;
        for ( j = 1 ; j * j <= a[ i ] ; j ++ ) {
        	if ( ( a[ i ] % j ) != 0 ) { continue ; }
        	if ( j * j == a[ i ] ) {
				v[ j ].push_back ( i ) ;
			}
            else {
				v[ j ].push_back ( i ) ;
                v[ ( a[ i ] / j ) ].push_back ( i ) ;
            }
        }
    }
}

void solve ( ) {
	int i ;
    LEAVES = 1 ;
    while ( LEAVES < n ) { LEAVES *= 2 ; }
    for ( i = 1 ; i <= n ; i ++ ) {
    	update ( 1 , 1 , LEAVES , i , i , i ) ;
    }
    for ( i = MAXN - 1 ; i >= 1 ; i -- ) {
    	if ( v[ i ].size ( ) >= 2 ) {
	        update ( 1 , 1 , LEAVES , v[ i ][ 1 ] + 1 , n , n + 1 ) ;
    	    update ( 1 , 1 , LEAVES , v[ i ][ 0 ] + 1 , v[ i ][ 1 ] , v[ i ][ v[ i ].size ( ) - 1 ] ) ;
        	update ( 1 , 1 , LEAVES , 1 , v[ i ][ 0 ] , v[ i ][ v[ i ].size ( ) - 2 ] ) ;
		}
        br[ i ] = 1LL * n * ( n - 1 ) - sm[ 1 ] ;
    }
    long long ans = 0 ;
    for ( i = 1 ; i < MAXN - 1 ; i ++ ) {
    	ans += ( br[ i + 1 ] - br[ i ] ) * i ;
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