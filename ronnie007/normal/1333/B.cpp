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

#define MAXN 100007

int n ;

bool fl1 , fl2 ;

int a[ MAXN ] ;
int b[ MAXN ] ;

void input ( ) {
    fl1 = fl2 = false ;
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
            
}

void solve ( ) {
    fl1 = fl2 = false ;
    int i ;
    for ( i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == b[ i ] ) {
            if ( a[ i ] == 1 ) { fl1 = true ; }
            if ( a[ i ] == -1 ) { fl2 = true ; }
            continue ;
        }
        if ( a[ i ] < b[ i ] && fl1 == false ) { printf ( "NO\n" ) ; return ; } 
        if ( a[ i ] > b[ i ] && fl2 == false ) { printf ( "NO\n" ) ; return ; } 
        if ( a[ i ] == 1 ) { fl1 = true ; }
        if ( a[ i ] == -1 ) { fl2 = true ; }
    }
    printf ( "YES\n" ) ;
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