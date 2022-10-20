#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

int n ;
int x , y ;

void input ( ) {
    scanf ( "%d%d%d" , &x , &y , &n ) ;
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 0 ; i <= x ; ++ i ) {
        for ( int j = 0 ; j <= y ; ++ j ) {
            if ( i + j == n ) { ++ ans ; }
        }
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