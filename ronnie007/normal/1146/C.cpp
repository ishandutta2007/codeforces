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
    int i , j ;
    int ans = 0 ;
    for ( j = 0 ; j < 8 ; j ++ ) {
        int w = (1<<j) ;
        int br = 0 ;
        for ( i = 1 ; i <= n ; i ++ ) {
            if ( (i&w) == 0 ) { br ++ ; }
        }
        if ( br == 0 || br == n ) { continue ; }
        printf ( "%d %d" , br , ( n - br ) ) ;
        for ( i = 1 ; i <= n ; i ++ ) {
            if ( (i&w) == 0 ) { printf ( " %d" , i ) ; }
        }
        for ( i = 1 ; i <= n ; i ++ ) {
            if ( (i&w) != 0 ) { printf ( " %d" , i ) ; }
        }
        printf ( "\n" ) ;
        fflush ( stdout ) ;
        int ret ;
        scanf ( "%d" , &ret ) ;
        ans = max ( ans , ret ) ;
    }
    printf ( "-1 %d\n" , ans ) ;
    fflush ( stdout ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t != 0 ) {
        input ( ) ;
        solve ( ) ;
        t -- ;
    }
    return 0 ;
}