#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

#define MAXN 1007

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
    int i , j ;
    vector < int > v ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = i + 1 ; j <= n ; j ++ ) {
            int aux1 = ( a[ j ] - a[ j - 1 ] ) ;
            int aux2 = ( a[ j - i ] - a[ j - i - 1 ] ) ;
            if ( aux1 != aux2 ) { break ; }
        }
        if ( j > n ) { v.push_back ( i ) ; }
    }
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d " , v[ i ] ) ;
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}