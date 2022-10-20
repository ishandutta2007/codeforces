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

int n ;
int a[ 100007 ] ;
int b[ 100007 ] ;


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
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}


void solve ( )  {
    int i ;
    long long ans = 0 ;
    long long p ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( 2 * a[ i ] < b[ i ] || b[ i ] == 1 ) {
            ans -- ;
        }
        else {
            p = b[ i ] / 2 ;
            if ( 2 * p != b[ i ] ) ans += p * ( p + 1 ) ;
            else ans += p * p ;
        }
    }
    printf ( "%I64d\n" , ans ) ;
}