#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;

int n , m ;
int a[ 3007 ] ;
int b[ 3007 ] ;


void input ( ) ;
void solve ( ) ;

int main ( )  {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( )  {
    int i , j ;
    i = 0 ;
    for ( j = 0 ; j < n ; j ++ ) {
        while ( b[ i ] < a[ j ] && i < m ) i ++ ;
        if ( i == m ) break ;
        i ++ ;
    }
    printf ( "%d\n" , n - j ) ;
}