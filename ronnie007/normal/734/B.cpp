#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

int x , y , z , t ;

void input ( ) {
	scanf ( "%d%d%d%d" , &x , &y , &z , &t ) ;
}

void solve ( ) {
	int ans = 0 ;
    while ( x != 0 ) {
    	x -- ;
    	if ( z != 0 && t != 0 ) {
        	z -- ; t -- ;
            ans += 256 ;
        }
        else {
        	if ( y == 0 ) { break ; }
            else { ans += 32 ; y -- ;}
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