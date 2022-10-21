#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int a , b ;

void input ( ) {
    scanf ( "%d%d" , &a , &b ) ;
}

void solve ( ) {
    int i , j , t ;
    for ( i = 0 ; i <= 300 ; i ++ ) {
        for ( j = i ; j <= 300 ; j ++ ) {
            int br1 , br2 ;
            br1 = br2 = 0 ;
            for ( t = i ; t <= j ; t ++ ) {
                if ( ( t % 2 ) == 0 ) { br1 ++ ; }
                else { br2 ++ ; }
            }
            if ( br1 == a && br2 == b ) {
                printf ( "YES\n" ) ;
                return ;
            }
        }
    }
    printf ( "NO\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}