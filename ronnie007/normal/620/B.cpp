#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;


int l , r ;
int f[ 10 ] ;

void input ( ) {
	scanf ( "%d%d" , &l , &r ) ;
    f[ 0 ] = 6 ;
    f[ 1 ] = 2 ;
    f[ 2 ] = 5 ;
    f[ 3 ] = 5 ;
    f[ 4 ] = 4 ;
    f[ 5 ] = 5 ;
    f[ 6 ] = 6 ;
    f[ 7 ] = 3 ;
    f[ 8 ] = 7 ;
    f[ 9 ] = 6 ;
}

void solve ( ) {
	int i ;
    int ans = 0 ;
    for ( i = l ; i <= r ; i ++ ) {
    	int x = i ;
        while ( x != 0 ) {
        	ans += f[ ( x % 10 ) ] ;
            x /= 10 ;
        }
    }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}