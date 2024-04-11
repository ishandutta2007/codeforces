#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

string s ;

int br1 , br2 , br3 ;
int a , b , c ;
int p1 , p2 , p3 ;
long long q ;

bool f ( long long x ) {
    long long cost ;
    cost = 0 ;
    if ( x * br1 > a ) cost +=( x * br1 - a ) * p1 ;
    if ( x * br2 > b ) cost += ( x * br2 - b ) * p2 ;
    if ( x * br3 > c ) cost += ( x * br3 - c ) * p3 ;
    return ( cost <= q ) ;
}

int main ( ) {
    cin >> s ;
    cin >> a >> b >> c ;
    cin >> p1 >> p2 >> p3 ;
    cin >> q ;
    int i ;
    for ( i = 0 ; i < s.size ( ) ; i ++ ) {
        if ( s[ i ] == 'B' ) br1 ++ ;
        if ( s[ i ] == 'S' ) br2 ++ ;
        if ( s[ i ] == 'C' ) br3 ++ ;
    }
    long long l = 0 ;
    long long r = 0 ;
    long long mid ;
    r = 1 ;
    for ( i = 0 ; i < 13 ; i ++ ) r = r * 13 ;
    while ( r - l > 1 ) {
        mid = ( r + l ) / 2 ;
        if ( f ( mid ) == true ) l = mid ;
        else r = mid ;
    }
    if ( f ( l + 1 ) == true ) l ++ ;
    cout << l << "\n" ;
    return 0 ;
}