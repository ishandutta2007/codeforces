#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int n ;
string s ;
long long ans = 0 ;

int main ( ) {
    cin >> n >> s ;
    int i ;
    for( i = 0 ; i < n ; i ++ ) if ( s[ i ] == 'B' ) ans |= (1ll << i) ;
    cout << ans << "\n" ;
    return 0 ;
}