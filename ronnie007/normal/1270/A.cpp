#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

int n ;
int x , y ;

void input ( ) {
    int h1 , h2 ;
    scanf ( "%d%d%d" , &n , &h1 , &h2 ) ;
    x = y = 0 ;
    while ( h1 -- ) {
        int a ;
        scanf ( "%d" , &a ) ;
        x = max ( x , a ) ;
    }
    while ( h2 -- ) {
        int a ;
        scanf ( "%d" , &a ) ;
        y = max ( y , a ) ;
    }
}

void solve ( ) {
    if ( x > y ) { printf ( "YES\n" ) ; }
    else { printf ( "NO\n" ) ; }
}

int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}