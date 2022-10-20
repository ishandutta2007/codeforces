#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    int ans = 0 ;
    int br = 1 ;
    for ( i = 2 ; i <= n ; i ++ ) {
        if ( a[ i ] > a[ i - 1 ] ) { br ++ ; }
        else {
            if ( ans < br ) { ans = br ; }
            br = 1 ;
        }
    }
    if ( ans < br ) { ans = br ; }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}