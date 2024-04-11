#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

int n ;

set < int > s ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int x , y ;
    scanf ( "%d%d" , &x , &y ) ;
    long long i ;
    for ( i = 2 ; i * i <= x ; i ++ ) {
        if ( ( x % i ) == 0 ) {
            s.insert ( i ) ;
            while ( ( x % i ) == 0 ) { x /= i ; }
        }
    }
    if ( x != 1 ) { s.insert ( x ) ; }
    for ( i = 2 ; i * i <= y ; i ++ ) {
        if ( ( y % i ) == 0 ) {
            s.insert ( i ) ;
            while ( ( y % i ) == 0 ) { y /= i ; }
        }
    }
    if ( y != 1 ) { s.insert ( y ) ; }
}

void solve ( ) {
    int i ;
    for ( i = 2 ; i <= n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        set < int > :: iterator it ;
        vector < int > aux ;
        aux.clear ( ) ;
        for ( it = s.begin ( ) ; it != s.end ( ) ; it ++ ) {
            int val = (*it) ;
            if ( ( x % val ) != 0 && ( y % val ) != 0 ) { aux.push_back ( val ) ; }
        }
        int sz = aux.size ( ) ;
        for ( int j = 0 ; j < sz ; j ++ ) {
            s.erase ( aux[ j ] ) ;
        }
    }
    if ( s.size ( ) == 0 ) { printf ( "-1\n" ) ; return ; }
    printf ( "%d\n" , (*s.begin ( )) ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}