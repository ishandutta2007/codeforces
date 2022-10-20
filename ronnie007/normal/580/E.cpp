#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<ctime>
using namespace std ;


#define MOD 1000000007
#define BASE1 47
#define BASE2 31

struct tuhla {
	long long val1 ;
	long long val2 ;
	int len ;
	int lazy ;
};


int n , q ;
string a ;
struct tuhla tr[ 300007 ] ;
int LEAVES = 0 ;
long long pw1[ 300007 ] ;
long long pw2[ 300007 ] ;
long long prcmp1[ 12 ][ 100007 ] ;
long long prcmp2[ 12 ][ 100007 ] ;
int tot ;
long long ans1 = 0 ;
long long ans2 = 0 ;


void init ( int where , int val ) {
	tr[ where ].val1 = tr[ where ].val2  = val ;
	where /= 2 ;
	while ( where != 0 ) {
		tr[ where ].val1 = ( tr[ 2 * where ].val1 * pw1[ tr[ 2 * where ].len ] ) % MOD ;
		tr[ where ].val1 += tr[ 2 * where + 1 ].val1 ;
		tr[ where ].val1 %= MOD ;

		tr[ where ].val2 = ( tr[ 2 * where ].val2 * pw2[ tr[ 2 * where ].len ] ) % MOD ;
		tr[ where ].val2 += tr[ 2 * where + 1 ].val2 ;
		tr[ where ].val2 %= MOD ;
		where /= 2 ;
	}
}

void update ( int where , int IL , int IR , int CURL , int CURR , int dig ) {
	if ( IL > CURR || IR < CURL ) { return ; }
	if ( IL > IR ) { return ; }
	if ( IL == IR ) { tr[ where ].lazy = -1 ; }
	if ( tr[ where ].lazy != -1 ) {
		tr[ 2 * where ].val1 = prcmp1[ tr[ where ].lazy ][ tr[ 2 * where ].len ] ;
		tr[ 2 * where + 1 ].val1 = prcmp1[ tr[ where ].lazy ][ tr[ 2 * where + 1 ].len ] ;

		tr[ 2 * where ].val2 = prcmp2[ tr[ where ].lazy ][ tr[ 2 * where ].len ] ;
		tr[ 2 * where + 1 ].val2 = prcmp2[ tr[ where ].lazy ][ tr[ 2 * where + 1 ].len ] ;

		tr[ 2 * where ].lazy = tr[ 2 * where + 1 ].lazy = tr[ where ].lazy ;
		tr[ where ].lazy = -1 ;
	}
	if ( CURL <= IL && IR <= CURR ) {
		tr[ where ].val1 = prcmp1[ dig ][ tr[ where ].len ] ;
		tr[ where ].val2 = prcmp2[ dig ][ tr[ where ].len ] ;
		tr[ where ].lazy = dig ;
		return ;
	}
	int mid = ( IL + IR ) / 2 ;
	update ( 2 * where , IL , mid , CURL , CURR , dig ) ;
	update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , dig ) ;

	tr[ where ].val1 = ( tr[ 2 * where ].val1 * pw1[ tr[ 2 * where ].len ] ) % MOD ;
	tr[ where ].val1 += tr[ 2 * where + 1 ].val1 ;
	tr[ where ].val1 %= MOD ;

	tr[ where ].val2 = ( tr[ 2 * where ].val2 * pw2[ tr[ 2 * where ].len ] ) % MOD ;
	tr[ where ].val2 += tr[ 2 * where + 1 ].val2 ;
	tr[ where ].val2 %= MOD ;
}

void query ( int where , int IL , int IR , int CURL , int CURR ) {
	long long ret = 0 ;
	if ( IL > CURR || IR < CURL ) { return ; }
	if ( IL > IR ) { return ; }
	if ( IL == IR ) { tr[ where ].lazy = -1 ; }
	if ( tr[ where ].lazy != -1 ) {
		tr[ 2 * where ].val1 = prcmp1[ tr[ where ].lazy ][ tr[ 2 * where ].len ] ;
		tr[ 2 * where + 1 ].val1 = prcmp1[ tr[ where ].lazy ][ tr[ 2 * where + 1 ].len ] ;

		tr[ 2 * where ].val2 = prcmp2[ tr[ where ].lazy ][ tr[ 2 * where ].len ] ;
		tr[ 2 * where + 1 ].val2 = prcmp2[ tr[ where ].lazy ][ tr[ 2 * where + 1 ].len ] ;

		tr[ 2 * where ].lazy = tr[ 2 * where + 1 ].lazy = tr[ where ].lazy ;
		tr[ where ].lazy = -1 ;
	}
	if ( CURL <= IL && IR <= CURR ) {
		ans1 = ( ans1 * pw1[ tr[ where ].len ] ) % MOD ;
		ans1 += tr[ where ].val1 ;
		ans1 %= MOD ;

		ans2 = ( ans2 * pw2[ tr[ where ].len ] ) % MOD ;
		ans2 += tr[ where ].val2 ;
		ans2 %= MOD ;
		return ;
	}
	int mid = ( IL + IR ) / 2 ;
	query ( 2 * where , IL , mid , CURL , CURR ) ;
	query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
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


void input ( ) {
	int x , y ;
	cin >> n >> x >> y ;
	q = x + y ;
	cin >> a ;
	LEAVES = 1 ;
	while ( LEAVES < n ) { LEAVES *= 2 ; }	
	int i , j ;
	pw1[ 0 ] = 1 ;
	pw2[ 0 ] = 1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		pw1[ i ] = ( pw1[ i - 1 ] * BASE1 ) % MOD ;
		pw2[ i ] = ( pw2[ i - 1 ] * BASE2 ) % MOD ;
	}
	for ( i = 0 ; i <= 9 ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			prcmp1[ i ][ j ] = ( prcmp1[ i ][ j - 1 ] * BASE1 + i ) % MOD ;
			prcmp2[ i ][ j ] = ( prcmp2[ i ][ j - 1 ] * BASE2 + i ) % MOD ;
		}
	}
}

void solve ( ) {
	int i ;
	for ( i = 0 ; i <= 2 * LEAVES ; i ++ ) { tr[ i ].lazy = -1 ; }
	for ( i = 0 ; i < LEAVES ; i ++ ) {
		tr[ LEAVES + i ].len = 1 ;
	}
	for ( i = LEAVES - 1 ; i >= 1 ; i -- ) {
		tr[ i ].len = tr[ 2 * i ].len * 2 ;
	}
	for ( i = 0 ; i <= n ; i ++ ) {
		init ( i + LEAVES , ( a[ i ] - '0' ) ) ;
	}
	int type , x , y , z ;
	while ( q != 0 ) {
		q -- ;
		//scanf ( "%d%d%d%d" , &type , &x , &y , &z ) ;
		cin >> type >> x >> y >> z ;
		if ( type == 1 ) {
			update ( 1 , 1 , LEAVES , x , y , z ) ;
		}
		else {
			if ( z > ( y - x + 1 ) ) { cout << "YES\n" ; }
			else {
				ans1 = 0 ; ans2 = 0 ; query ( 1 , 1 , LEAVES , x + z , y ) ; long long h1 = ans1 ; long long u1 = ans2 ;
				ans1 = 0 ; ans2 = 0 ; query ( 1 , 1 , LEAVES , x , y - z ) ; long long h2 = ans1 ; long long u2 = ans2 ;
				if ( h1 == h2 && u1 == u2 ) { cout << "YES\n" ; }
				else { cout << "NO\n" ; }
			}
		}
	}
}