#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

long long x , y , z ;


map < long long , long long > ZX   ;

void upd ( ) {
	while ( x != y ) {
    	if ( x > y ) {
        	ZX[ x ] += z ;
            x /= 2 ;
        }
        else {
        	ZX[ y ] += z ;
            y /= 2 ;
        }
    }
}

void calc ( ) {
	long long ans = 0 ;
	while ( x != y ) {
    	if ( x > y ) {
        	ans += ZX[ x ] ;
            x /= 2 ;
        }
        else {
			ans += ZX[ y ] ;
            y /= 2 ;
        }
    }
	cout << ans << "\n" ;
}

void input ( ) {

}

void solve ( ) {
	int n ;
    cin >> n ;
    int type ;
    while ( n != 0 ) {
    	n -- ;
        cin >> type ;
        if ( type == 1 ) {
        	cin >> x >> y >> z ;
            upd ( ) ;
        }
		else {
        	cin >> x >> y ;
            calc ( ) ;
        }
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}