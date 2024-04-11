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

#define MAXN 100007

int n , m ;
string a ;
int b[ MAXN ] ;

bool f ( int x ) {
	int i ;
    int lst = -1 ;
    for ( i = 0 ; i < n ; i ++ ) {
    	if ( ( a[ i ] - 'a' ) <= x ) {
        	lst = i ;
            continue ;
        }
		if ( ( i - lst ) >= m ) { return false ; }
    }
    return true ;
}

void input ( ) {
	cin >> m ;
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
	int i , j , t ;
    for ( i = 0 ; i < 26 ; i ++ ) {
    	if ( f ( i ) == true ) {
        	break ; 
        }
    }
    int id = i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( ( a[ i - 1 ] - 'a' ) < id ) { b[ i ] = 1 ; }
        else { b[ i ] = 0 ; }
    }
    b[ 0 ] = 1 ;
    b[ n + 1 ] = 1 ;
    string ret ;
    for ( i = 0 ; i <= n ; i ++ ) {
    	if ( b[ i ] == 0 ) { continue ; }
        for ( j = i + 1 ; j <= n + 1 ; j ++ ) {
        	if ( b[ j ] == 1 ) { break ; }
        }
        if ( ( j - i - 1 ) >= m ) {
        	int lst = i ;
            while ( ( j - lst - 1 ) >= m ) {
            	for ( t = m ; t >= 1 ; t -- ) {
                	if ( lst + t >= ( n + 1 ) ) { continue ; }
                    if ( ( a[ lst + t - 1 ] - 'a' ) == id ) { lst += t ; ret += char ( id + 'a' ) ; break ; }
                }
            }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( b[ i ] == 1 ) { ret += a[ i - 1 ] ; }
    }
    sort ( ret.begin ( ) , ret.end ( ) ) ;
    cout << ret << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}