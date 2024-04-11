#include<iostream>
#include<stdio.h>
#include<string>
#include<set>
using namespace std ;

#define WIN 1
#define LOSE 0

int n , k ;
string a[ 100007 ] ;
set < string > y ;
int g = 0 ;


int dfs ( string x ) {
    int i ;
    int ind = 0 ;
    for ( i = 0 ; i < 26 ; i ++ ) {
        x += ( i + 'a' ) ;
        if ( y.find ( x ) != y.end ( ) ) {
            ind = 1 ;
        }
        x.resize ( x.size ( ) - 1 ) ;
    }
    if ( ind == 0 ) return LOSE ;
    for ( i = 0 ; i < 26 ; i ++ ) {
        x += ( i + 'a' ) ;
        if ( y.find ( x ) != y.end ( ) ) {
            int ret = dfs ( x ) ;
            if ( ret == LOSE ) return WIN ;
        }
        x.resize ( x.size ( ) - 1 ) ;
    }
    return LOSE ;
}

int dfs2 ( string x ) {
    int i ;
    int ind = 0 ;
    for ( i = 0 ; i < 26 ; i ++ ) {
        x += ( i + 'a' ) ;
        if ( y.find ( x ) != y.end ( ) ) {
            ind = 1 ;
        }
        x.resize ( x.size ( ) - 1 ) ;
    }
    if ( ind == 0 ) return WIN ;
    for ( i = 0 ; i < 26 ; i ++ ) {
        x += ( i + 'a' ) ;
        if ( y.find ( x ) != y.end ( ) ) {
            int ret = dfs2 ( x ) ;
            if ( ret == LOSE ) return WIN ;
        }
        x.resize ( x.size ( ) - 1 ) ;
    }
    return LOSE ;
}

void input ( ) {
    cin >> n >> k ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a[ i ] ;
        int sz = a[ i ].size ( ) ;
        int j ;
        for ( j = 1 ; j <= sz ; j ++ ) {
            y.insert ( a[ i ].substr ( 0 , j ) ) ;
        }
    }
}

void solve ( ) {
    string x ;
    x.clear ( ) ;
    g = 0 ;
    bool ans = dfs ( "" ) ;
    g = 1 ;
    bool p = dfs2 ( "" ) ;
    ///printf ( "%d %d\n" , ans , p ) ;
    if ( !ans ) printf ( "Second\n" ) ;
    else {
        if ( p ) printf ( "First\n" ) ;
        else {
            if ( k % 2 == 1 ) printf ( "First\n" ) ;
            else printf ( "Second\n" ) ;
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