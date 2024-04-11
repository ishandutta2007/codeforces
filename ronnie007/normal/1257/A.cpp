#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;




void input ( ) {
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        int n , x , a , b ;
        scanf ( "%d%d%d%d" , &n , &x , &a , &b ) ;
        printf ( "%d\n" , min ( n - 1 , abs ( a - b ) + x ) ) ;

    }
}

void solve ( ) {

}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}