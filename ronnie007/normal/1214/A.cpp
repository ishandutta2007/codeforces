#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
int x , y ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &x , &y ) ;
}

void solve ( ) {
    y *= 5 ;
    int ans = n ;
    for ( int i = 0 ; i < 1000000 ; ++ i ) {
        int lft = ( n - i * y ) ;
        if ( lft < 0 ) { break ; }
        lft %= x ;
        if ( ans > lft ) { ans = lft ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}