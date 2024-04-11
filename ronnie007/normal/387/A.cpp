#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


string a ;
string b ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    cin >> a ;
    cin >> b ;
}

void solve ( )  {
    int h , m ;
    int x ;
    int y ;
    int x1 , y1 ;
    x =  ( a[ 3 ] - '0' ) * 10 + ( a[ 4 ] - '0' ) ;
    y =  ( b[ 3 ] - '0' ) * 10 + ( b[ 4 ] - '0' ) ;
    x1 =  ( a[ 0 ] - '0' ) * 10 + ( a[ 1 ] - '0' ) ;
    y1 =  ( b[ 0 ] - '0' ) * 10 + ( b[ 1 ] - '0' ) ;
    int ans1 , ans2 ;
    if ( y > x ) {
        x += 60 ;
        x1 -- ;
    }
    ans2 = x - y ;
    if ( y1 > x1 ) {
        x1 += 24 ;
    }
    ans1 = x1 - y1 ;
    if ( ans1 < 10 ) printf ( "0%d" , ans1 ) ;
    else printf ( "%d" , ans1 ) ;
    printf ( ":" ) ;
    if ( ans2 < 10 ) printf ( "0%d" , ans2 ) ;
    else printf ( "%d" , ans2 ) ;
    printf ( "\n" ) ;
}