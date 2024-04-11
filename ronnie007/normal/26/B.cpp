#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int n ;
string a ;



int main ( ) {
    cin >> a ;
    n = a.size ( ) ;
    int i ;
    int mn = 0 ;
    int bal = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == '(' ) bal ++ ;
        else bal -- ;
        if ( mn > bal ) mn = bal ;
    }
    //cout << mn << "\n" ;
    int ans ;
    ans = ( 0 - mn ) + ( bal + ( 0 - mn ) ) ;
    printf ( "%d\n" , n - ans ) ;
    return 0 ;
}