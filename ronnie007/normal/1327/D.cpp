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
#include<random>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;
int used[ MAXN ] ;

vector < pair < int , int > > v ;

vector < int > divs[ MAXN ] ;
int ans ;

void init ( ) {
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        for ( int j = i ; j < MAXN ; j += i ) {
            divs[ j ].push_back ( i ) ;
        }
    }
}

void f ( ) {
    int sz = v.size ( ) ;
    int len = divs[ sz ].size ( ) ;
    for ( int i = 0 ; i < len ; ++ i ) {
        int x = divs[ sz ][ i ] ;
        for ( int j = 0 ; j < x ; ++ j ) {
            int pos = j ;
            while ( 1 ) {
                pos += x ;
                if ( pos >= sz ) { pos -= sz ; }
                if ( v[ pos ].second != v[ j ].second ) { break ; }
                if ( pos == j ) { break ; }
            }
            if ( pos == j ) {
                ans = min ( ans , x ) ;
                return ;
            }
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    ans = n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 0 ) {
            v.clear ( ) ;
            int x = i ;
            while ( used[ x ] == 0 ) {
                used[ x ] = 1 ;
                v.push_back ( { x , b[ x ] } ) ;
                x = a[ x ] ;
            }
            f ( ) ;
        }
    }
    printf ( "%d\n" , ans ) ;
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