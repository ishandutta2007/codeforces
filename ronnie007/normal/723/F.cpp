#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std ;

#define MAXN 200007

int n , m ;
pair < int , int > p[ 2 * MAXN ] ;

int s , t , ds , dt ;

int par[ MAXN ] ;

vector < pair < int , int > > ans ;

bool fl ;

bool f1[ MAXN ] ;
bool f2[ MAXN ] ;

int find ( int x ) {
	if ( par[ x ] == -1 ) { return x ; }
    int y = find ( par[ x ] ) ;
    par[ x ] = y ;
    return y ;
}

void UNITE ( pair < int , int > u ) {
	int k1 = find ( u.first ) ;
    int k2 = find ( u.second ) ;
    if ( k1 != k2 ) {
    	ans.push_back ( u ) ;
        par[ k1 ] = k2 ;
        if ( u.first == s ) { ds -- ; }
        if ( u.first == t ) { dt -- ; }
        if ( u.second == s ) { ds -- ; }
        if ( u.second == t ) { dt -- ; }
    }
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
    	scanf ( "%d%d" , &p[ i ].first , &p[ i ].second ) ;
    }
    scanf ( "%d%d%d%d" , &s , &t , &ds , &dt ) ;
}

void solve ( ) {
	int i ;
    for ( i = 1 ; i <= n ; i ++ ) { par[ i ] = -1 ; }
    fl = false ;
    for ( i = 1 ; i <= m ; i ++ ) {
    	if ( p[ i ].first != s && p[ i ].first != t && p[ i ].second != s && p[ i ].second != t ) {
	    	UNITE ( p[ i ] ) ;
		}
        else {
        	if ( p[ i ].first == s && p[ i ].second == t ) { fl = true ; }
            else if ( p[ i ].first == t && p[ i ].second == s ) { fl = true ; }
            else {
            	if ( p[ i ].first == s ) { f1[ p[ i ].second ] = true ; }
                if ( p[ i ].first == t ) { f2[ p[ i ].second ] = true ; }
                if ( p[ i ].second == s ) { f1[ p[ i ].first ] = true ; }
                if ( p[ i ].second == t ) { f2[ p[ i ].first ] = true ; }
            }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( f1[ i ] == true && f2[ i ] == false ) {
        	UNITE ( make_pair ( i , s ) ) ;
        }
        if ( f1[ i ] == false && f2[ i ] == true ) {
        	UNITE ( make_pair ( i , t ) ) ;
        }
    }
    if ( ds < 0 || dt < 0 ) {
    	printf ( "No\n" ) ;
        return ;
    }
    int br = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( f1[ i ] == true && f2[ i ] == true ) {
        	br ++ ;
        	if ( br == 1 ) {
            	UNITE ( make_pair ( i , s ) ) ;
                UNITE ( make_pair ( i , t ) ) ;
			}
            else {
            	if ( ds > dt ) { UNITE ( make_pair ( i , s ) ) ; }
                else { UNITE ( make_pair ( i , t ) ) ; }
            }
        }
    }
    if ( find ( s ) != find ( t ) ) {
    	if ( fl == false ) {
		   	printf ( "No\n" ) ;
    	    return ;
		}
        else {
			ans.push_back ( make_pair ( s , t ) ) ;
            ds -- ;
            dt -- ;
        }
	}
    if ( ds < 0 || dt < 0 ) {
    	printf ( "No\n" ) ;
        return ;
    }
    printf ( "Yes\n" ) ;
    for ( i = 0 ; i < n - 1 ; i ++ ) {
    	printf ( "%d %d\n" , ans[ i ].first , ans[ i ].second ) ;
    }
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}