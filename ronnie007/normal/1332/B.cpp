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

#define MAXN 1007

vector < int > v ;

int n ;
int a[ MAXN ] ;

int f[ MAXN ] ;
int p[ MAXN ] ;
int ans[ MAXN ] ;

void init ( ) {
    for ( int i = 2 ; i <= 35 ; ++ i ) {
        int j = 2 ;
        while ( j * j <= i ) {
            if ( ( i % j ) == 0 ) { break ; }
            ++ j ;
        }
        if ( j * j > i ) { v.push_back ( i ) ; }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int sz = v.size ( ) ;
    for ( int i = 0 ; i <= sz ; ++ i ) { p[ i ] = 0 ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < sz ; ++ j ) {
            if ( ( a[ i ] % v[ j ] ) == 0 ) {
                f[ i ] = j + 1 ;
                ++ p[ j + 1 ] ;
                break ;
            }
        }
    }
    int cnt = 0 ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        if ( p[ i ] > 0 ) {
            ++ cnt ;
            for ( int j = 1 ; j <= n ; ++ j ) {
                if ( f[ j ] == i ) {
                    ans[ j ] = cnt ; 
                }
            }
        }
    }
    printf ( "%d\n" , cnt ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}