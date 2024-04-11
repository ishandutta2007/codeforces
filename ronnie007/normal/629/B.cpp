#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std ;

#define MAXN 5007

int n ;
struct tuhla {
	string g ;
	int st , en ;
};

struct tuhla a[ MAXN ] ;

void input ( ) {
	cin >> n ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ].g >> a[ i ].st >> a[ i ].en ;
	}
}

void solve ( ) {
	int i , j ;
	int ans = 0 ;
	int cur = 0 ;
	for ( i = 1 ; i <= 366 ; i ++ ) {
		cur = 0 ;
		int br1 = 0 ;
		int br2 = 0 ;
		for ( j = 1 ; j <= n ; j ++ ) {
			if ( a[ j ].st <= i && i <= a[ j ].en ) {
				if ( a[ j ].g == "M" ) { br1 ++ ; }
				else { br2 ++ ; }
			}
		}
		cur = min ( br1 , br2 ) ;
		if ( ans < 2 * cur ) { ans = 2 * cur ; } 
	}
	cout << ans << "\n" ; 
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}