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

#define MAXN 200007

int n ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i < n ; ++ i ) {
        int aux = ( max ( a[ i ] , a[ i + 1 ] ) - min ( a[ i ] , a[ i + 1 ] ) ) ;
        if ( aux >= 2 ) {
            printf ( "YES\n" ) ;
            printf ( "%d %d\n" , i , i + 1 ) ;
            return ;
        }
    }
    printf ( "NO\n" ) ;
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