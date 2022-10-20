#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std ;

#define MAXN 100007
#define SIGMA 26

int n , q ;
string a ;

int LEAVES = 0 ;

int tr[ SIGMA ][ 5 * MAXN ] ;
int lazy[ SIGMA ][ 5 * MAXN ] ;

int br[ SIGMA ] ;

void init ( int id , int where , int val ) {
	while ( where != 0 ) {
    	tr[ id ][ where ] += val ;
        where /= 2 ;
    }
}

void update ( int id , int where , int IL , int IR , int CURL , int CURR , int val ) {
	if ( IL > IR ) { return ; }
    if ( lazy[ id ][ where ] != -1 ) {
    	tr[ id ][ where ] = lazy[ id ][ where ] * ( IR - IL + 1 ) ;
        if ( where < LEAVES ) {
        	lazy[ id ][ 2 * where ] = lazy[ id ][ where ] ;
            lazy[ id ][ 2 * where + 1 ] = lazy[ id ][ where ] ;
        }
        lazy[ id ][ where ] = -1 ;
    }    
    if ( IR < CURL || CURR < IL ) { return ; }
    if ( CURL <= IL && IR <= CURR ) {
    	tr[ id ][ where ] = val * ( IR - IL + 1 ) ;
        if ( where < LEAVES ) {
        	lazy[ id ][ 2 * where ] = val ;
            lazy[ id ][ 2 * where + 1 ] = val ;
        }
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    update ( id , 2 * where , IL , mid , CURL , CURR , val ) ;
    update ( id , 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
    tr[ id ][ where ] = tr[ id ][ 2 * where ] + tr[ id ][ 2 * where + 1 ] ;
}

int query ( int id , int where , int IL , int IR , int CURL , int CURR ) {
	if ( IL > IR ) { return 0 ; }
    if ( lazy[ id ][ where ] != -1 ) {
    	tr[ id ][ where ] = lazy[ id ][ where ] * ( IR - IL + 1 ) ;
        if ( where < LEAVES ) {
        	lazy[ id ][ 2 * where ] = lazy[ id ][ where ] ;
            lazy[ id ][ 2 * where + 1 ] = lazy[ id ][ where ] ;
        }
        lazy[ id ][ where ] = -1 ;
    }    
    if ( IR < CURL || CURR < IL ) { return 0 ; }
    if ( CURL <= IL && IR <= CURR ) {
        return tr[ id ][ where ] ;
    }    
    int mid = ( IL + IR ) / 2 ;
    int ret = query ( id , 2 * where , IL , mid , CURL , CURR ) ;
    ret += query ( id , 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    tr[ id ][ where ] = tr[ id ][ 2 * where ] + tr[ id ][ 2 * where + 1 ] ;
    return ret ;
}

void input ( ) {
	cin >> n >> q ;
    cin >> a ;
    LEAVES = 1 ;
    while ( LEAVES < n ) { LEAVES *= 2 ; }
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
    	init ( ( a[ i ] - 'a' ) , LEAVES + i , 1 ) ;
    }
}

void solve ( ) {
	int i , j ;
    int x , y , z ;
    for ( i = 0 ; i < 26 ; i ++ ) {
    	for ( j = 0 ; j <= 2 * LEAVES ; j ++ ) {
        	lazy[ i ][ j ] = -1 ;
        }
    }
	while ( q != 0 ) {
    	q -- ;
		cin >> x >> y >> z ;
        for ( i = 0 ; i < 26 ; i ++ ) {
        	br[ i ] = query ( i , 1 , 1 , LEAVES , x , y ) ;
            update ( i , 1 , 1 , LEAVES , x , y , 0 ) ;
        }
        int st , en , step ;
        if ( z == 1 ) {
        	st = 0 ;
            en = 26 ;
            step = 1 ;
        }
        else {
        	st = 25 ;
            en = -1 ;
            step = -1 ;
        }
        int tot = 0 ;
        for ( i = st ; i != en ; i += step ) {
        	if ( br[ i ] == 0 ) { continue ; }
            update ( i , 1 , 1 , LEAVES , x + tot , x + tot + br[ i ] - 1 , 1 ) ;
            tot += br[ i ] ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 0 ; j < 26 ; j ++ ) {
        	if ( query ( j , 1 , 1 , LEAVES , i , i ) != 0 ) {
            	cout << char ( j + 'a' ) ;
                break ;
            }
        }
    }
    cout << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}