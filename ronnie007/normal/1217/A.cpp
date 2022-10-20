#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;




void input ( ) {

}

void solve ( ) {
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        int k = x + z - y ;
        if ( k <= 0 ) { printf ( "0\n" ) ; }
        else {
            printf ( "%d\n" , min ( z + 1 , k / 2 + ( k % 2 ) ) ) ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}