#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 1000007


int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;
int ans[ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    int sz ;
    scanf ( "%d" , &sz ) ;
    while ( sz != 0 ) {
        sz -- ;
        int x ;
        scanf ( "%d" , &x ) ;
        b[ x ] = 1 ;
    }
}

void solve ( ) {
    int i ;
    stack < int > s ;
    for ( i = n ; i >= 1 ; i -- ) {
        if ( s.empty ( ) == true || b[ i ] == 1 ) {
            s.push ( i ) ;
            ans[ i ] = -a[ i ] ;
        }
        else {
            if ( s.empty ( ) == false && a[ s.top ( ) ] == a[ i ] ) {
                ans[ i ] = a[ i ] ;
                s.pop ( ) ;
            }
            else {
                s.push ( i ) ;
                ans[ i ] = -a[ i ] ;
            }
        }
    }
    if ( s.empty ( ) == false ) { printf ( "NO\n" ) ; return ; }
    printf ( "YES\n" ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d" , ans[ i ] ) ;
        if ( i == n ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}