#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
string a ;
int x , y ;

void input ( ) {
    x = y = 0 ;
    cin >> n ;
    cin >> a ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == 'n' ) { ++ x ; }
        if ( a[ i ] == 'z' ) { ++ y ; }
    }
}

void solve ( ) {
    while ( x -- ) { cout << "1 " ; }
    while ( y -- ) { cout << "0 " ; }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}