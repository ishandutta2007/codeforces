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

#define MAXN 5007
int n ;
int a[ MAXN ] ;


int f[ MAXN ][ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        f[ i ][ i ] = a[ i ] ;
    }
    for ( int len = 1 ; len < n ; ++ len ) {
        for ( int i = 1 ; i + len <= n ; ++ i ) {
            int j = i + len ;
            f[ i ][ j ] = ( f[ i + 1 ][ j ] ^ f[ i ][ j - 1 ] ) ;
        }
    }
    for ( int len = 1 ; len < n ; ++ len ) {
        for ( int i = 1 ; i + len <= n ; ++ i ) {
            int j = i + len ;
            f[ i ][ j ] = max ( f[ i ][ j ] , f[ i + 1 ][ j ] ) ;
            f[ i ][ j ] = max ( f[ i ][ j ] , f[ i ][ j - 1 ] ) ;
        }
    }
    int q ;
    scanf ( "%d" , &q ) ;
    for ( int i = 1 , x , y ; i <= q ; ++ i ) {
        scanf ( "%d%d" , &x , &y ) ;
        printf ( "%d\n" , f[ x ][ y ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}