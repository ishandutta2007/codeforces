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

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    if ( n == 1 ) { printf ( "-1\n" ) ; }
    else {
        printf ( "2" ) ;
        for ( int i = 1 ; i < n ; ++ i ) {
            printf ( "3" ) ;
        }
        printf ( "\n" ) ;
    }
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