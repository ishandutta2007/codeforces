#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
using namespace std ;

map < string , int > ZX ;
int MAXVAL ;

int n , m ;

int same ;

void input ( ) {
	cin >> n >> m ;
	int i ;
	MAXVAL = 1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		string s ;
		cin >> s ;
		ZX[ s ] = 1 ;
	}
	same = 0 ;
	for ( i = 1 ; i <= m ; i ++ ) {
		string s ;
		cin >> s ;
		if ( ZX.find ( s ) != ZX.end ( ) ) {
			same ++ ;
		}
	}
}

void solve ( ) {
	int pl = 1 ;
	int lft1 , lft2 ;
	lft1 = n - same ;
	lft2 = m - same ;
	while ( 1 ) {
		if ( pl == 1 ) {
			if ( same != 0 ) {
				same -- ;
			}
			else {
				if ( lft1 <= 0 ) {
					printf ( "NO\n" ) ;
					return ;
				}
				lft1 -- ;
			}
		}
		else {
			if ( same != 0 ) {
				same -- ;
			}
			else {
				if ( lft2 <= 0 ) {
					printf ( "YES\n" ) ;
					return ;
				}
				lft2 -- ;
			}
		}
		pl = 3 - pl ;
	}
	
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}