#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int curr = 0 ;
    int ans = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == '1' ) {
            int val = 0 ;
            for ( int j = 0 ; j < 20 ; ++ j ) {
                if ( i + j >= n ) { break ; }
                val = val * 2 + ( a[ i + j ] - '0' ) ;
                if ( j + 1 + curr >= val ) { ++ ans ; }
            }
            curr = 0 ;
        }
        else { ++ curr ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}