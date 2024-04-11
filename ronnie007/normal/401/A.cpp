#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n , x ;
int a[ 1007 ] ;
int s = 0 ;


void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d%d" , &n , &x ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        s += a[ i ] ;
    }
}

void solve ( ) {
    if ( s < 0 ) s = 0 - s ;
    int ans = s / x ;
    if ( s % x != 0 ) ans ++ ;
    printf ( "%d\n" , ans ) ;
}