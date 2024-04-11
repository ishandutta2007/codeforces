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

int x , n ;

int used[ 5007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    scanf ( "%d%d" , &x , &n ) ;
    int i ;
    int t , a , b ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &t ) ;
        if ( t == 1 ) {
            scanf ( "%d%d" , &a , &b ) ;
            used[ a ] = 1 ;
            used[ b ] = 1 ;
        }
        else {
            scanf ( "%d" , &a ) ;
            used[ a ] = 1 ;
        }
    }
}


void solve ( )  {
    int mxans = 0 ;
    int mnans = 0 ;
    int i ;
    int br = 0 ;
    for ( i = 1 ; i < x ; i ++ ) {
        if ( used[ i ] == 0 ) br ++ ;
        else {
            if ( br != 0 ) {
                mnans = mnans + br/ 2 ;
                if ( br%2 == 1 ) mnans ++ ;
                mxans += br ;
            }
            br = 0 ;
        }
    }
    if ( br != 0 ) {
        mnans = mnans + br/ 2 ;
        if ( br%2 == 1 ) mnans ++ ;
        mxans += br ;
    }
    printf ( "%d %d\n" , mnans , mxans ) ;
}