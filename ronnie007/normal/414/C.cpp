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

#define MAXN 2000007

int n ;
int k ;
int a[ MAXN ] ;
int b[ MAXN ] ;
long long inv1[ 27 ] ;
long long inv2[ 27 ] ;

bool flip[ 27 ] ;

void f ( int st , int en , int lvl ) {
	if ( st == en ) { return ; }
    int mid = ( st + en ) / 2 ;
    f ( st , mid , lvl - 1 ) ;
    f ( mid + 1 , en , lvl - 1 ) ;
    int id1 = 0 ;
    int id2 = 0 ;
    long long cur = 0 ;
    int i ;
    long long eq = 1 ;
    for ( i = st ; i <= mid ; i ++ ) {
        if ( a[ i ] == a[ i - 1 ] ) {
        	if ( i > st ) { eq ++ ; }
		}
        else {
        	inv2[ lvl - 1 ] += ( eq * ( eq - 1 ) / 2 ) ;
            eq = 1 ;
        }
    }
	inv2[ lvl - 1 ] += ( eq * ( eq - 1 ) / 2 ) ;
	eq = 1 ;  
    for ( i = mid + 1 ; i <= en ; i ++ ) {
        if ( a[ i ] == a[ i - 1 ] ) {
        	if ( i > mid + 1 ) { eq ++ ; }
		}
        else {
        	inv2[ lvl - 1 ] += ( eq * ( eq - 1 ) / 2 ) ;
            eq = 1 ;
        }
    }
	inv2[ lvl - 1 ] += ( eq * ( eq - 1 ) / 2 ) ;
	eq = 1 ;  
    
    for ( i = st ; i <= en ; i ++ ) {
    	if ( mid + 1 + id2 > en || ( st + id1 <= mid && a[ st + id1 ] <= a[ mid + 1 + id2 ] ) ) {
        	cur += id2 ;
            b[ i ] = a[ st + id1 ] ;
            id1 ++ ;
        }
        else {
        	b[ i ] = a[ mid + 1 + id2 ] ;
            id2 ++ ;
        }
    }
	eq = 1 ;
    for ( i = st ; i <= en ; i ++ ) {
    	a[ i ] = b[ i ] ;
        if ( a[ i ] == a[ i - 1 ] ) {
        	if ( i > st ) { eq ++ ; }
		}
        else {
        	inv2[ lvl - 1 ] -= ( eq * ( eq - 1 ) / 2 ) ;
            eq = 1 ;
        }
    }
	inv2[ lvl - 1 ] -= ( eq * ( eq - 1 ) / 2 ) ;
	eq = 1 ;    
    inv1[ lvl - 1 ] += cur ;
    inv2[ lvl - 1 ] += ( ( 1LL * ( mid - st + 1 ) * ( mid - st + 1 ) ) - cur ) ;    
}

void input ( ) {
	scanf ( "%d" , &n ) ;
    k = (1<<n) ;
    int i ;
    for ( i = 1 ; i <= k ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
	f ( 1 , k , n ) ;
    int q ;
    int x ;
    int i ;
    for ( i = 0 ; i <= n ; i ++ ) { flip[ i ] = false ; }
    scanf ( "%d" , &q ) ;
    while ( q != 0 ) {
    	q -- ;
        scanf ( "%d" , &x ) ;
        int i ;
		for ( i = 0 ; i < x ; i ++ ) { flip[ i ] ^= 1 ; }
        long long ret = 0 ;
        for ( i = 0 ; i <= n ; i ++ ) {
        	if ( flip[ i ] == false ) { ret += inv1[ i ] ; }
            else { ret += inv2[ i ] ; }
        }
		printf ( "%I64d\n" , ret ) ;
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}