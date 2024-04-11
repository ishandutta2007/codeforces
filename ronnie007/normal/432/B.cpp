#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

long long n ;
int a[ 100007 ] ;
int b[ 100007 ] ;

int HOME[ 100007 ] ;
long long ans[ 100007 ][ 3 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%I64d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d%d" , &a[ i ] , &b[ i ] ) ;
    }
}


void solve ( )  {
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        HOME[ a[ i ] ] ++ ;
    }
    long long cur ;
    for ( i = 0 ; i < n ; i ++ ) {
        cur = n - 1 ;
        cur -= HOME[ b[ i ] ] ;
        ans[ i ][ 1 ] = cur ;
        ans[ i ][ 0 ] = 2 * ( n - 1 ) - cur ;
    }
    for ( i = 0 ; i < n ; i ++ ) {
        printf ( "%I64d %I64d\n" , ans[ i ][ 0 ] , ans[ i ][ 1 ] ) ;
    }
}