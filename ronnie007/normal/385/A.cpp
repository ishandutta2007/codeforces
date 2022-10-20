#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n , d ;
int a[ 107 ] ; 


void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    int i ;
    scanf ( "%d%d" , &n , &d ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( )  {
    int i ; 
    int ans = 0 ; 
    for ( i = 0 ; i < n - 1 ; i ++ ) {
        if ( ans < a[ i ] - a[ i + 1 ] - d ) ans = a[ i ] - a[ i + 1 ] - d ;
    }
    printf ( "%d\n" , ans ) ;
}