#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


int n , p ;
string a ;

string ans ;
string cur ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	cin >> n >> p ;
	cin >> a ; 
}

void solve ( )  {
	int i , j , t , k ;
	int h ; 
	int st ; 
	ans.clear ( ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		st = a[ i ] - 'a' ;
		for ( h = st + 1 ; h < p ; h ++ ) {
			cur.clear ( ) ;
			for ( j = 0 ; j < i ; j ++ ) {
				cur += a[ j ] ;
			}
			if ( ( a[ i ] - 'a' ) == p - 1 ) continue ;
			cur += ( h  + 'a' ) ;
			if ( i != 0 && cur[ i ] == cur[ i - 1 ] ) continue ;
			if ( i >= 2 && cur[ i ] == cur[ i - 2 ] ) continue ;
        	//	cout << cur << "\n" ;
			for ( j = i + 1 ; j < n ; j ++ ) {
				for ( t = 0 ; t < 3 ; t ++ ) {
					if ( t >= p ) continue ;
					for ( k = 0 ; k < 2 ; k ++ ) {
						if ( ( j - 1 ) - k < 0 ) continue ;
						if ( cur[ ( j - 1 ) - k ] == ( 'a' + t ) ) break ;
					}
					if ( k == 2 ) break ;
				}
				if ( t != 3 ) cur += ( t + 'a' ) ;
				else { cur.clear ( ) ; break ; }
			}
    	    //	cout << cur << "\n" ;
			if ( j == n ) {
				if ( ans.size ( ) == 0 || ans > cur ) ans = cur ;
				break ;
			}
		}
    }
	if ( ans.size ( ) == 0 ) cout << "NO\n" ;
	else cout << ans << "\n" ;
}