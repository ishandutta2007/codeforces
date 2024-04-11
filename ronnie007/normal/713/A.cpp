#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

map < string , int > ZX ;

void input ( ) {

}

void solve ( ) {
	int q ;
    cin >> q ;
    string a ;
    char c ;
    while ( q != 0 ) {
    	q -- ;
        cin >> c >> a ;
        if ( c == '?' ) {
        	string u ;
            for ( int i = 0 ; i < a.size ( ) ; i ++ ) {
            	if ( a[ i ] == '1' ) { u += a[ i ] ; }
                else {
                	if ( u.size ( ) != 0 ) { u += a[ i ] ; }
                }
            }
            a = u ;
        	int ans = 0 ;
            while ( a.size ( ) <= 19 ) {
            	ans += ZX[ a ] ;
                a = '0' + a ;
            }
        	cout << ans << "\n" ;
            continue ;
        }
        string s ;
        int i ;
        int sz = a.size ( ) ;
        s.clear ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
        	int val = ( a[ i ] - '0' ) ;
            if ( val % 2 == 0 ) { s += '0' ; }
            else { s += '1' ; }
        }
        
        if ( c == '+' ) { ZX[ s ] ++ ; }
        else { ZX[ s ] -- ; }
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}