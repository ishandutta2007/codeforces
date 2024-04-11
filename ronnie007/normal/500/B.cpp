#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 307

int n ;
int a[ MAXN ] ;
int pos[ MAXN ] ;

string f[ MAXN ] ;
int used[ MAXN ] ;

int ans[ MAXN ] ;

int mn ;

void dfs ( int vertex ) {
    if ( used[ vertex ] == 1 ) { return ; }
    used[ vertex ] = 1 ;
    if ( ans[ vertex ] == 0 ) {
        if ( mn > vertex ) { mn = vertex ; }
    }
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( f[ vertex - 1 ][ i ] == '0' || used[ i + 1 ] == 1 ) { continue ; }
        dfs ( i + 1 ) ;
    }
}

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
    cin >> n ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
        pos[ a[ i ] ] = i ;
    }
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> f[ i ] ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 0 ; j <= n ; j ++ ) { used[ j ] = 0 ; }
        mn = MAXN ;
        dfs ( pos[ i ] ) ;
        ans[ mn ] = i ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d" , ans[ i ] ) ;
        if ( i == n ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}